# AGENTS.md

This file provides guidance to AI coding agents when working with code in this repository.

## graphify

This project has a knowledge graph at graphify-out/ with god nodes, community structure, and cross-file relationships.

Rules:
- For codebase questions, first run `graphify query "<question>"` when graphify-out/graph.json exists. Use `graphify path "<A>" "<B>"` for relationships and `graphify explain "<concept>"` for focused concepts. These return a scoped subgraph, usually much smaller than GRAPH_REPORT.md or raw grep output.
- If graphify-out/wiki/index.md exists, use it for broad navigation instead of raw source browsing.
- Read graphify-out/GRAPH_REPORT.md only for broad architecture review or when query/path/explain do not surface enough context.
- After modifying code, run `graphify update .` to keep the graph current (AST-only, no API cost).

## Project overview

C.H.O.R.D. (Computational Hardware Optimized library for Realtime DSP) is a C++20 header-mostly library of DSP/math primitives (dot product, mean, vector add, FFT sizing, etc.) that lets client code stay CPU-agnostic. At compile time it dispatches to the fastest backend available for the target architecture:

- **Intel (x86_64, amd64)**: implemented via Intel IPP.
- **ARM (arm, armv7, aarch64, arm64)**: currently falls back to the generic `std` implementation (Ne10 integration planned).
- **Generic / override**: the `std` implementation, selectable on any platform via `-DOVERRIDE_USE_STD=ON`.

## Build and test commands

```bash
# Configure with tests + tools (main_exec, gtest_exec, smoke_tests, bench_exec) enabled
cmake -S . -B build -DCHORD_ENABLE_TESTS=ON -DCHORD_BUILD_TOOLS=ON

# Force the generic std backend regardless of detected CPU (useful off-Intel or for parity testing)
cmake -S . -B build -DCHORD_ENABLE_TESTS=ON -DOVERRIDE_USE_STD=ON

# Build everything
cmake --build build

# Run the full unit-test suite
cd build && ctest
# or run the test binary directly (also runs the generated smoke tests target):
./build/src/tests/gtest/gtest_exec
./build/src/tests/gtest/smoke_tests

# Run a single test (GoogleTest filter)
./build/src/tests/gtest/gtest_exec --gtest_filter=*ComputeMeanValue*

# Benchmarks (Google Benchmark; std vs. optimized backend)
./build/src/tests/gbenchmark/bench_exec
```

Requirements: CMake ≥ 3.18, a C++20 compiler, and (optionally, for Intel builds) Intel IPP installed under `/opt/intel/oneapi/ipp/latest/` or `/opt/intel/ipp`. `CHORD_ENABLE_TESTS` and `CHORD_BUILD_TOOLS` are both off by default when this project is consumed as a subdirectory (`CHORD_BUILD_TOOLS` defaults to on only when Chord is the top-level project).

CI (`.gitlab-ci.yml`) builds in a matrix across both `OVERRIDE_USE_STD=ON/OFF` and two builder images, then runs smoke tests and the gtest suite as separate stages.

Packaging: a `conanfile.py` (`ChordConan`) is provided for Conan consumers; it builds the `chord` target and exposes it as `chord::chord`.

## Architecture

### Public API → dispatch → hardware implementation

The library separates a stable public API from swappable hardware-specific backends, joined through a `chord::impl` namespace:

1. **`include/chord/lib.hpp`** — public template declarations in `namespace chord` (e.g. `chord::compute_mean_value<T>`), documented with expected `StatusResult` outcomes.
2. **`include/chord/lib.tpp`** — the public wrapper definitions. Each wrapper validates arguments with the `CHECK_*_RETURN_STATUS` macros (`include/chord/check_args/`) before delegating to the same-named function in `chord::impl`.
3. **`include/chord/lib_impl.hpp`** — declares the `chord::impl` functions, then conditionally includes the backend `.tpp` at the bottom of the file based on which macro is defined at compile time:
   - `INTEL_PRESENT` → `src/impls/ipp/ipp_impl.tpp`
   - `OVERRIDE_USE_STD` → `src/impls/std/std_impl.tpp`
4. **Backends**:
   - `src/impls/ipp/` — Intel IPP-backed implementations. `ipp_wrappers/` contains per-operation wrapper declarations (`specializations/declarations/`) and definitions (`specializations/definitions/`), plus `cast_to_ipp/` for converting between `chord` types (spans, `std::complex`) and native IPP types.
   - `src/impls/std/std_impl.tpp` — the single generic C++ implementation used for ARM and the `OVERRIDE_USE_STD` fallback.

`CMakeLists.txt` detects `CMAKE_SYSTEM_PROCESSOR` against `INTEL_ARCHS`/`ARM_ARCHS` lists and sets `INTEL_PRESENT`/`ARM_PRESENT`/`OVERRIDE_USE_STD` accordingly (ARM currently forces `OVERRIDE_USE_STD`). `src/impls/CMakeLists.txt` globs sources from either the `ipp/` or `std/` subtree into the `impl_lib` INTERFACE target based on those flags, and links Intel IPP via `find_package(IPP REQUIRED)` when applicable.

### Error handling

All public operations return a `chord::StatusResult` (`include/chord/chord_status.hpp`) rather than throwing. It wraps a `Status` enum plus a message/function/file/line, and — when built with `INTEL_PRESENT` — has a dedicated constructor that maps every `IppStatus` value to the corresponding `chord::Status` and human-readable message, so IPP errors surface through the same type callers already check with `is_success()`/`is_fail()`/`operator bool()`.

### Libraries produced

- `utils_lib` (`src/utils/`) — static library: type helpers/casts (`types/`), generic math (`builtin_math/`), status/return-code helpers (`check_and_return_status/`), and random-vector generation for tests (`random_generate/`).
- `impl_lib` (`src/impls/`) — INTERFACE library selecting IPP or std sources as described above; links `utils_lib` and `Threads::Threads`.
- `chord` — the installed public library; PUBLIC-links `impl_lib`, PRIVATE-links `utils_lib`, and exposes `include/`.

### Adding a new operation

1. Declare it in `include/chord/lib.hpp` and add the validating wrapper in `include/chord/lib.tpp` (calling `chord::impl::your_op(...)`).
2. Declare the `chord::impl` signature in `include/chord/lib_impl.hpp`.
3. Implement it for `std` in `src/impls/std/std_impl.tpp` (required — this is the ARM/generic fallback).
4. Implement it for IPP by adding a wrapper declaration under `src/impls/ipp/ipp_wrappers/specializations/declarations/` and a definition under `.../definitions/`, calling the appropriate `ipps*` IPP function.
5. New files under `src/impls/{ipp,std}` are picked up automatically by the `file(GLOB_RECURSE ...)` in `src/impls/CMakeLists.txt`.

### Tests

- `src/tests/gtest/std_tests/` and `src/tests/gtest/ipp_tests/` mirror each operation with parallel test files, letting the same operation be validated against both backends.
- `src/tests/gtest/library/smoke_tests_generated.test.cpp` is **generated at configure time** by `src/tests/gtest/utils/generate_smoke_tests.py`, which parses `include/chord/lib.hpp` and emits a smoke test per public function (skipping entries in that script's `IGNORED_FUNCTIONS` list). Regenerate by reconfiguring/rebuilding — do not hand-edit the generated file.
- `src/tests/gtest/utils/test_runner.hpp` provides the shared `gtest_utils::run_tests` entry point used by test `main()`s.
