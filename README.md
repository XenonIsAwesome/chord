# C.H.O.R.D

**C**omputational **H**ardware **O**ptimized library for **R**ealtime **D**SP
___

Chord was developed to be integrated into realtime DSP pipelines that require optimized mathematical operations. Chord allows client code to be CPU agnostic, and will use CPU hardware optimizations depending on the architecture of the CPU compiled on.
___

Chord was developed mainly by Maya K. of Team Kernels.

## Rationale
In high-performance audio and signal processing applications, leveraging hardware-specific optimizations (like AVX on Intel or NEON on ARM) is crucial for low latency. However, maintaining separate codebases for different architectures is burdensome. Chord solves this by providing a unified C++ API that automatically dispatches to the most optimized implementation available for the target hardware.

## Description
Chord is a header-only(ish) C++ library that provides a collection of common mathematical and DSP functions (e.g., dot product, mean, vector addition). It abstracts away the underlying implementation:
*   **Intel Processors**: Uses [Intel IPP](https://www.intel.com/content/www/us/en/developer/tools/oneapi/ipp.html) for maximum performance.
*   **ARM Processors**: Currently falls back to a standard C++ implementation (std). Future updates will integrate [Ne10](https://github.com/projectNe10/Ne10).
*   **Generic**: A standard C++ implementation (`std`) is always available as a fallback or override.

## Code Snippet Example
Here is how you can use Chord in your application. Notice how the same code compiles and runs on any supported architecture.

```cpp
#include <chord/lib.hpp>
#include <vector>
#include <iostream>

int main() {
    // Input vectors
    const std::vector<float> a = {1.0f, 2.0f, 3.0f};
    std::vector<float> result(3);

    // Compute mean value using optimized backend
    float mean = 0.0f;
    chord::compute_mean_value<float>(a, mean);
    std::cout << "Mean: " << mean << std::endl;

    // Combine vector with scalar (element-wise multiplication)
    chord::combine_with_scalar<float>(a, 4.3f, result);
    
    std::cout << "Result vector: ";
    for (auto val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## Supported Hardware
*   **Intel**: x86_64, amd64 (via Intel IPP)
*   **ARM**: arm, armv7, aarch64, arm64 (via std implementation, Ne10 planned)

## Build, Install, and Usage

### Prerequisites
*   CMake 3.18 or higher
*   C++20 compliant compiler
*   (Optional) Intel IPP installed for Intel optimizations.

### Usage as a Subdirectory (Recommended)
You can include Chord directly in your project using `add_subdirectory`.

1.  Clone Chord into your project (e.g., `libs/chord`).
2.  Add to your `CMakeLists.txt`:
    ```cmake
    add_subdirectory(libs/chord)
    target_link_libraries(your_target PRIVATE chord)
    ```
3.  Include headers in your code:
    ```cpp
    #include <chord/lib.hpp>
    ```

### Usage via FetchContent
You can also use CMake's `FetchContent` to download and include Chord automatically.

```cmake
include(FetchContent)

FetchContent_Declare(
  chord
  GIT_REPOSITORY https://github.com/yourusername/chord.git # Replace with actual URL
  GIT_TAG        main # or specific tag/commit
)

FetchContent_MakeAvailable(chord)

target_link_libraries(your_target PRIVATE chord)
```

### CPU Optimization Overrides
By default, Chord detects the target CPU and selects the best implementation. You can force the use of the standard C++ implementation (bypassing generic optimizations) by configuring CMake:

```bash
cmake -DOVERRIDE_USE_STD=ON ..
```

## Technical Library Details: How to Add Functions

The library is structured to separate the public API from the hardware-specific implementations. If you want to add a new function (e.g., `compute_new_op`):

1.  **Public API**:
    *   Add the declaration in `include/chord/lib.hpp`.
    *   Add the template public wrapper in `include/chord/lib.tpp`. This wrapper should perform argument validity checks (size, null pointers) using provided macros (e.g., `CHECK_EQUAL_SIZE_RETURN_STATUS`).
    *   Call the implementation namespace function `chord::impl::compute_new_op(...)`.

2.  **Implementation Dispatch**:
    *   In `include/chord/lib_impl.hpp` (or similar internal header), ensure the new function is exposed within the `chord::impl` namespace.

3.  **Hardware Implementations**:
    *   **Intel IPP**: Add the specialization files in `src/impls/ipp/`. You will likely need to add a wrapper in `src/impls/ipp/ipp_wrappers/` that calls the specific IPP function (e.g., `ippsAdd_...`).
    *   **Standard (Generic)**: Add the generic C++ implementation in `src/impls/std/std_impl.tpp`. This is required for ARM and generic fallback support.

4.  **Registering Files**:
    *   Ensure any new `.cpp`, `.hpp`, or `.tpp` files in `src/impls/` are picked up by the `src/impls/CMakeLists.txt` globbing logic (which they should be automatically if added to the correct folders).

## Tests and Benchmarks

### Tests
The library uses **Google Test** for unit testing.
To build and run tests:
```bash
cmake -DCHORD_ENABLE_TESTS=ON -B build
cmake --build build
cd build
ctest
```

### Benchmarks
The library uses **Google Benchmark** to measure performance.
*Note: Benchmarks are currently available in source but may be commented out in `src/tests/gbenchmark/` as a work-in-progress example.*

To explore benchmarks, look at files in `src/tests/gbenchmark/`. When enabled, they allow comparing the performance of the `std` implementation versus optimized backends (IPP/Ne10).