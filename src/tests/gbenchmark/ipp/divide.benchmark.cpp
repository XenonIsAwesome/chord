// //
// // Created by mayak on 7/10/25.
// //
// TODO: fix, problem with ipp_wrappers include
// #include "builtin_math/math_std.hpp"
// #include "imp"
//
// #include <benchmark/benchmark.h>
//
// namespace ipp::gbenchmark {
// static void BM_divide_by_scalar(benchmark::State& state) {
//     // SET VALUES -------------------------------------------------------------------------------
//     const size_t size = state.range(0);
//     std::vector<float> src(size, 42.0f);
//     std::vector<float> dst(size);
//     float scalar = 2.0f;
//
//     std::span<float> src_span(src);
//     std::span<float> dst_span(dst);
//
//     // RUN --------------------------------------------------------------------------------------
//     for (auto _ : state) {
//         benchmark::DoNotOptimize(src_span);
//         benchmark::DoNotOptimize(dst_span);
//         ipp::wrappers::divide_by_scalar<float>(src_span, scalar, dst_span, size);
//
//         benchmark::ClobberMemory();
//     }
//
//     state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(size * sizeof(float)));
// }
// }  // namespace ipp::gbenchmark
//
//
// namespace math_std::gbenchmark {
// static void BM_divide_by_scalar(benchmark::State& state) {
//     // SET VALUES -------------------------------------------------------------------------------
//     const size_t size = state.range(0);
//     std::vector<float> src(size, 42.0f);
//     std::vector<float> dst(size);
//     float scalar = 2.0f;
//
//     std::span<float> src_span(src);
//     std::span<float> dst_span(dst);
//
//
//     // RUN --------------------------------------------------------------------------------------
//     for (auto _ : state) {
//         benchmark::DoNotOptimize(src_span);
//         benchmark::DoNotOptimize(dst_span);
//
//         // CALL FUNCTION ------------------------------------------------------------------------
//         math_std::divide_by_scalar<float>(src_span, scalar, dst_span);
//
//         benchmark::ClobberMemory();
//     }
//
//     state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(size * sizeof(float)));
// }
// }  // namespace math_std::gbenchmark
//
//
// BENCHMARK(ipp::gbenchmark::BM_divide_by_scalar)->Range(64, 1 << 20);
// BENCHMARK(math_std::gbenchmark::BM_divide_by_scalar)->Range(64, 1 << 20);
//
//
// namespace ipp::gbenchmark {
// static void BM_mul_by_scalar(benchmark::State& state) {
//     // SET VALUES -------------------------------------------------------------------------------
//     const size_t size = state.range(0);
//     std::vector<float> src(size, 42.0f);
//     std::vector<float> dst(size);
//     float scalar = 2.0f;
//
//     std::span<float> src_span(src);
//     std::span<float> dst_span(dst);
//
//     // RUN --------------------------------------------------------------------------------------
//     for (auto _ : state) {
//         benchmark::DoNotOptimize(src_span);
//         benchmark::DoNotOptimize(dst_span);
//         ipp::wrappers::multiply_with_scalar<float>(src_span, scalar, dst_span, size);
//
//         benchmark::ClobberMemory();
//     }
//
//     state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(size * sizeof(float)));
// }
// }  // namespace ipp::gbenchmark
//
//
// namespace math_std::gbenchmark {
// static void BM_mul_by_scalar(benchmark::State& state) {
//     // SET VALUES -------------------------------------------------------------------------------
//     const size_t size = state.range(0);
//     std::vector<float> src(size, 42.0f);
//     std::vector<float> dst(size);
//     float scalar = 2.0f;
//
//     std::span<float> src_span(src);
//     std::span<float> dst_span(dst);
//
//
//     // RUN --------------------------------------------------------------------------------------
//     for (auto _ : state) {
//         benchmark::DoNotOptimize(src_span);
//         benchmark::DoNotOptimize(dst_span);
//
//         // CALL FUNCTION ------------------------------------------------------------------------
//         math_std::multiply_with_scalar<float>(src_span, scalar, dst_span);
//
//         benchmark::ClobberMemory();
//     }
//
//     state.SetBytesProcessed(int64_t(state.iterations()) * int64_t(size * sizeof(float)));
// }
// }  // namespace math_std::gbenchmark
//
//
// BENCHMARK(ipp::gbenchmark::BM_mul_by_scalar)->Range(64, 1 << 20);
// BENCHMARK(math_std::gbenchmark::BM_mul_by_scalar)->Range(64, 1 << 20);
