# Graph Report - .  (2026-08-12)

## Corpus Check
- Corpus is ~30,126 words - fits in a single context window. You may not need a graph.

## Summary
- 565 nodes · 808 edges · 74 communities (71 shown, 3 thin omitted)
- Extraction: 99% EXTRACTED · 1% INFERRED · 0% AMBIGUOUS · INFERRED: 8 edges (avg confidence: 0.79)
- Token cost: 0 input · 0 output

## Community Hubs (Navigation)
- IPP Casting & Algorithm Utilities
- IPP Generate Tone Implementation
- IPP XOR Implementation
- IPP Multiply With Scalar Tests
- Status & Argument Validation Utilities
- Project Build & CI Pipeline
- IPP Find Min/Max Tests
- IPP Subtract Implementation
- Random Generation & Type Utilities
- IPP Divide Implementation
- Main Entry & Random Number Generation
- STD Test Runner Utilities
- Conan Package Recipe
- IPP Add Implementation
- IPP Complex Conjugate Implementation
- IPP Flip Implementation
- IPP Magnitude Implementation
- IPP Absolute Value Implementation
- IPP Sample Up Implementation
- STD Apply Power Tests
- Numeric Type Traits
- IPP Compute Complex Magnitude Tests
- IPP Integer Fraction / FFT Tests
- STD Generate Tone Samples Tests
- IPP Compute Sum Tests
- IPP Apply Absolute Tests
- IPP Combine With Scalar Tests
- IPP Divide By Scalar Tests
- IPP Compute Up Sample Tests
- IPP Exponential Implementation
- IPP XOR Implementation (variant)
- STD Combine Tests
- STD Compute Complex Conjugate Tests
- STD Compute Complex Magnitude Tests
- IPP Apply Power Tests
- IPP Compute Dot Product Tests
- IPP Floor Tests
- STD Combine With Scalar Tests
- STD Floor Tests
- IPP Apply Flip Tests
- IPP Apply Square Tests
- IPP Compute Real/Imag Magnitude Tests
- IPP Compute XOR Tests
- IPP Fill Slope Tests
- STD Multiply With Scalar Tests
- STD Sample Up Tests
- IPP Floor Implementation
- IPP Min Implementation
- IPP Square Implementation
- STD Apply Flip Tests
- Smoke Test Generator Script
- STD Compute Average Tests
- STD Compute Complex Exponent Tests
- STD Compute Exponential Tests
- STD Compute Subtraction Tests
- STD Compute XOR Tests
- IPP Compute Complex Exponent Tests
- IPP Compute Exponential Tests
- STD Divide By Scalar Tests
- STD Fill Slope Tests
- STD Fraction Split Tests
- IPP Compute Mean Value Tests
- STD Apply Square Tests
- STD Compute Mean Value Tests
- Size Validation Utilities
- Benchmark Install Script

## God Nodes (most connected - your core abstractions)
1. `StatusResult` - 20 edges
2. `Chord Library Project` - 9 edges
3. `ChordConan` - 7 edges
4. `TEST()` - 7 edges
5. `TEST()` - 7 edges
6. `Implementation Library (impl_lib)` - 7 edges
7. `WorkBufferSizes` - 6 edges
8. `TEST()` - 6 edges
9. `get_ipp_status_map()` - 5 edges
10. `get_ipp_status_message()` - 5 edges

## Surprising Connections (you probably didn't know these)
- `Maya K. (Author)` --references--> `Chord Library Project`  [INFERRED]
  README.md → CMakeLists.txt
- `Team Kernels (Development Team)` --references--> `Chord Library Project`  [INFERRED]
  README.md → CMakeLists.txt
- `Test GTest CI Job` --references--> `GTest Unit Test Executable`  [INFERRED]
  .gitlab-ci.yml → src/tests/gtest/CMakeLists.txt
- `Benchmark Executable` --conceptually_related_to--> `Chord Library Project`  [INFERRED]
  src/tests/gbenchmark/CMakeLists.txt → CMakeLists.txt
- `GTest Unit Test Executable` --conceptually_related_to--> `Chord Library Project`  [INFERRED]
  src/tests/gtest/CMakeLists.txt → CMakeLists.txt

## Import Cycles
- None detected.

## Hyperedges (group relationships)
- **Testing Architecture** — cmakelists_chord, src_tests_gtest_cmakelists_gtest_exec, src_tests_gtest_cmakelists_smoke_tests, src_tests_gbenchmark_cmakelists_bench_exec [INFERRED 0.85]
- **CI/CD Pipeline** — cmakelists_chord, .gitlab_ci_yml_build_in_matrix, .gitlab_ci_yml_test_smoketests, .gitlab_ci_yml_test_gtest [EXTRACTED 1.00]
- **Architecture-Specific Implementation Dispatch** — cmakelists_hardware_arch_detection, src_impls_cmakelists_impl_lib, src_impls_cmakelists_intel_ipp [EXTRACTED 1.00]

## Communities (74 total, 3 thin omitted)

### Community 0 - "IPP Casting & Algorithm Utilities"
Cohesion: 0.06
Nodes (37): IppHintAlgorithm, cast_to_ipp(), AlgoChoice, complex, IppStatus, span, ipp::wrappers::compute_complex_exponent<float>(), complex (+29 more)

### Community 1 - "IPP Generate Tone Implementation"
Cohesion: 0.05
Nodes (34): ComplexFloat_Float, DISABLED_IPP_ComputeFractionalPart, DISABLED_IPP_DivideListByList_Inplace, IPP_CombineListWithList, IPP_CombineListWithList_Inplace, IPP_DivideListByList, IPP_GenerateTone, combine() (+26 more)

### Community 2 - "IPP XOR Implementation"
Cohesion: 0.05
Nodes (8): WorkBufferSizes, size_buffer, size_init, size_spec, IppStatus, ipp::wrappers::generate_DFT_sizes<std::complex<float>>(), IppStatus, ipp::wrappers::generate_FFT_sizes<std::complex<float>>()

### Community 3 - "IPP Multiply With Scalar Tests"
Cohesion: 0.07
Nodes (21): AllFunctionsCompileAndLink, DivisionByZero, IPP_ComputeComplexConjugate, IPP_ComputeComplexConjugate_Inplace, IPP_MultiplyWithScalar, IPP_MultiplyWithScalar_Inplace, LIB_GeneratedSmokeTests, LIB_Test (+13 more)

### Community 4 - "Status & Argument Validation Utilities"
Cohesion: 0.14
Nodes (12): get_ipp_status_map(), get_ipp_status_message(), IppStatus, StatusResult, file_, func_name_, line_, message_ (+4 more)

### Community 5 - "Project Build & CI Pipeline"
Cohesion: 0.15
Nodes (19): Build In Matrix CI Job, Test GTest CI Job, Test SmokeTests CI Job, Chord Library Project, Hardware Architecture Detection, Main Executable, CPU-Agnostic API Design Pattern, Hardware-Optimized Implementations (+11 more)

### Community 6 - "IPP Find Min/Max Tests"
Cohesion: 0.12
Nodes (14): IPP_FindMax, IPP_FindMaxIndex, IPP_FindMin, IPP_FindMinIndex, IPP_SubstractByList, IPP_SubstractByList_Inplace, ComplexDouble, ComplexFloat (+6 more)

### Community 7 - "IPP Subtract Implementation"
Cohesion: 0.42
Nodes (11): complex, IppStatus, span, ipp::wrappers::substract_by_list<double>(), ipp::wrappers::substract_by_list<float>(), ipp::wrappers::substract_by_list_inplace<double>(), ipp::wrappers::substract_by_list_inplace<float>(), ipp::wrappers::substract_by_list_inplace<std::complex<double>>() (+3 more)

### Community 8 - "Random Generation & Type Utilities"
Cohesion: 0.20
Nodes (8): mt19937, random_utils::get_random_gen(), getInnerType, getInnerType<Wrap<Inner>>, false_type, is_specialization, is_specialization<Ref<Args...>, Ref>, true_type

### Community 9 - "IPP Divide Implementation"
Cohesion: 0.45
Nodes (10): complex, IppStatus, span, ipp::wrappers::divide_by_scalar<float>(), ipp::wrappers::divide_by_scalar_inplace<float>(), ipp::wrappers::divide_by_scalar_inplace<std::complex<float>>(), ipp::wrappers::divide_by_scalar<std::complex<float>>(), ipp::wrappers::divide_list_by_list() (+2 more)

### Community 10 - "Main Entry & Random Number Generation"
Cohesion: 0.22
Nodes (8): getInnerType_t_opt, T, random_utils::generate_random_number(), random_utils::generate_random_vector(), random_utils::get_random_dist(), uniform_int_distribution, uniform_real_distribution, vector

### Community 11 - "STD Test Runner Utilities"
Cohesion: 0.22
Nodes (6): FindMax, FindMaxIndex, FindMin, FindMinIndex, ComplexFloatInput, TEST()

### Community 13 - "IPP Add Implementation"
Cohesion: 0.57
Nodes (7): complex, IppStatus, span, ipp::wrappers::combine(), ipp::wrappers::combine_inplace(), ipp::wrappers::combine_with_scalar(), ipp::wrappers::combine_with_scalar_inplace()

### Community 14 - "IPP Complex Conjugate Implementation"
Cohesion: 0.57
Nodes (7): complex, IppStatus, span, ipp::wrappers::compute_complex_conjugates<double>(), ipp::wrappers::compute_complex_conjugates<float>(), ipp::wrappers::compute_complex_conjugates_inplace<double>(), ipp::wrappers::compute_complex_conjugates_inplace<float>()

### Community 15 - "IPP Flip Implementation"
Cohesion: 0.50
Nodes (7): complex, IppStatus, span, ipp::wrappers::apply_flip<float>(), ipp::wrappers::apply_flip_inplace<float>(), ipp::wrappers::apply_flip_inplace<std::complex<float>>(), ipp::wrappers::apply_flip<std::complex<float>>()

### Community 16 - "IPP Magnitude Implementation"
Cohesion: 0.50
Nodes (7): complex, IppStatus, span, ipp::wrappers::compute_complex_magnitude<double>(), ipp::wrappers::compute_complex_magnitude<float>(), ipp::wrappers::compute_real_imag_magnitude<double>(), ipp::wrappers::compute_real_imag_magnitude<float>()

### Community 17 - "IPP Absolute Value Implementation"
Cohesion: 0.57
Nodes (6): IppStatus, span, ipp::wrappers::apply_absolute<double>(), ipp::wrappers::apply_absolute<float>(), ipp::wrappers::apply_absolute_inplace<double>(), ipp::wrappers::apply_absolute_inplace<float>()

### Community 18 - "IPP Sample Up Implementation"
Cohesion: 0.48
Nodes (6): complex, IppStatus, span, ipp::wrappers::compute_up_sample<double>(), ipp::wrappers::compute_up_sample<float>(), ipp::wrappers::compute_up_sample<std::complex<float>>()

### Community 19 - "STD Apply Power Tests"
Cohesion: 0.33
Nodes (5): ApplyRaisePower, ApplyRaisePowerWithScalar, ComplexFloatInput, FloatInput, TEST()

### Community 20 - "Numeric Type Traits"
Cohesion: 0.33
Nodes (4): bool_constant<std::is_arithmetic_v<T>>, false_type, is_numeric_complex, is_numeric_complex<std::complex<T>>

### Community 21 - "IPP Compute Complex Magnitude Tests"
Cohesion: 0.33
Nodes (5): DISABLED_IPP_ComputeComplexMagnitude, IPP_ComputeComplexMagnitude, ComplexDouble, ComplexFloat, TEST()

### Community 22 - "IPP Integer Fraction / FFT Tests"
Cohesion: 0.33
Nodes (3): DISABLED_IPP_IntegerFractionSplit, Float, TEST()

### Community 23 - "STD Generate Tone Samples Tests"
Cohesion: 0.33
Nodes (5): GeneratComplexTone, GeneratTone, ComplexFloatInput, FloatInput, TEST()

### Community 24 - "IPP Compute Sum Tests"
Cohesion: 0.33
Nodes (5): Int, IPP_ComputeSum, ComplexFloat, Float, TEST()

### Community 25 - "IPP Apply Absolute Tests"
Cohesion: 0.33
Nodes (5): IPP_ApplyAbsolute, IPP_ApplyAbsolute_Inplace, Double, Float, TEST()

### Community 26 - "IPP Combine With Scalar Tests"
Cohesion: 0.33
Nodes (5): IPP_CombineWithScalar, IPP_CombineWithScalar_Inplace, ComplexFloat, Float, TEST()

### Community 27 - "IPP Divide By Scalar Tests"
Cohesion: 0.33
Nodes (5): IPP_DivideByScalar, IPP_DivideByScalar_Inplace, ComplexFloat, Float, TEST()

### Community 28 - "IPP Compute Up Sample Tests"
Cohesion: 0.33
Nodes (5): IPP_SampleUp, ComplexFloat, Double, Float, TEST()

### Community 29 - "IPP Exponential Implementation"
Cohesion: 0.47
Nodes (5): complex, IppStatus, span, ipp::wrappers::compute_exponential<float>(), ipp::wrappers::compute_exponential<std::complex<float>>()

### Community 30 - "IPP XOR Implementation (variant)"
Cohesion: 0.53
Nodes (5): IppStatus, span, ipp::wrappers::compute_xor(), ipp::wrappers::compute_xor_inplace(), u_short

### Community 31 - "STD Combine Tests"
Cohesion: 0.33
Nodes (5): ComplexFloat, Float, TEST(), STD_Combine, STD_Combine_Inplace

### Community 32 - "STD Compute Complex Conjugate Tests"
Cohesion: 0.40
Nodes (4): ComputeComplexConjugate, ComputeComplexConjugateInplace, ComplexFloatInput, TEST()

### Community 33 - "STD Compute Complex Magnitude Tests"
Cohesion: 0.40
Nodes (4): ComputeComplexMagnitudeRealImag, ComplexFloatInput, TEST(), STD_ComputeComplexMagnitude

### Community 34 - "IPP Apply Power Tests"
Cohesion: 0.40
Nodes (4): DISABLED_IPP_ApplyPower, DISABLED_IPP_ApplyPowerWithScalar, Float, TEST()

### Community 35 - "IPP Compute Dot Product Tests"
Cohesion: 0.40
Nodes (4): DISABLED_IPP_ComputeComplexDotProduct, IPP_ComputeDotProduct, Float, TEST()

### Community 36 - "IPP Floor Tests"
Cohesion: 0.40
Nodes (4): DISABLED_IPP_Floor, Double, Float, TEST()

### Community 37 - "STD Combine With Scalar Tests"
Cohesion: 0.40
Nodes (4): FloatInputInplace, FloatInput, TEST(), STD_CombineWithScalar

### Community 38 - "STD Floor Tests"
Cohesion: 0.40
Nodes (4): Floor, WorksForFloat, TEST(), WorksForDouble

### Community 39 - "IPP Apply Flip Tests"
Cohesion: 0.40
Nodes (4): IPP_ApplyFlip, IPP_ApplyFlip_Inplace, Float, TEST()

### Community 40 - "IPP Apply Square Tests"
Cohesion: 0.40
Nodes (4): IPP_ApplySquare, IPP_ApplySquare_Inplace, Float, TEST()

### Community 41 - "IPP Compute Real/Imag Magnitude Tests"
Cohesion: 0.40
Nodes (4): IPP_ComputeRealIMagMagnitude, Double, Float, TEST()

### Community 42 - "IPP Compute XOR Tests"
Cohesion: 0.40
Nodes (4): IPP_ComputeXor, IPP_ComputeXor_Inplace, UnsignedShortType, TEST()

### Community 43 - "IPP Fill Slope Tests"
Cohesion: 0.40
Nodes (4): IPP_FillSlope, Double, Float, TEST()

### Community 44 - "STD Multiply With Scalar Tests"
Cohesion: 0.40
Nodes (4): MultiplyWithScalar, WorksForComplexFloatType, TEST(), WorksForFloatType

### Community 45 - "STD Sample Up Tests"
Cohesion: 0.40
Nodes (4): SampleUp, WorksWithFloat, TEST(), WorksWithComplexFloat

### Community 46 - "IPP Floor Implementation"
Cohesion: 0.60
Nodes (4): IppStatus, span, ipp::wrappers::apply_floor<double>(), ipp::wrappers::apply_floor<float>()

### Community 47 - "IPP Min Implementation"
Cohesion: 0.60
Nodes (4): IppStatus, span, ipp::wrappers::find_minimum(), ipp::wrappers::find_minimum_index()

### Community 48 - "IPP Square Implementation"
Cohesion: 0.60
Nodes (4): IppStatus, span, ipp::wrappers::apply_square<float>(), ipp::wrappers::apply_square_inplace<float>()

### Community 49 - "STD Apply Flip Tests"
Cohesion: 0.40
Nodes (4): TEST(), STD_ApplyFlip, STD_ApplyFlipInplace, WorksWithInt

### Community 50 - "Smoke Test Generator Script"
Cohesion: 0.70
Nodes (4): default_args_for_type(), extract_functions(), generate_tests(), main()

### Community 51 - "STD Compute Average Tests"
Cohesion: 0.50
Nodes (3): ComplexFloatType, TEST(), STD_ComputeAverage

### Community 52 - "STD Compute Complex Exponent Tests"
Cohesion: 0.50
Nodes (3): ComputeComplexExponent, FloatInput, TEST()

### Community 53 - "STD Compute Exponential Tests"
Cohesion: 0.50
Nodes (3): ComputeExponential, WorksForComplexFloatType, TEST()

### Community 54 - "STD Compute Subtraction Tests"
Cohesion: 0.50
Nodes (3): ComputeSubstraction, WorksForFloat, TEST()

### Community 55 - "STD Compute XOR Tests"
Cohesion: 0.50
Nodes (3): ComputeXor, UnsignedShortType, TEST()

### Community 56 - "IPP Compute Complex Exponent Tests"
Cohesion: 0.50
Nodes (3): DISABLED_IPP_ComputeComplexExponent, Float, TEST()

### Community 57 - "IPP Compute Exponential Tests"
Cohesion: 0.50
Nodes (3): DISABLED_IPP_ComputeExponential, Float, TEST()

### Community 58 - "STD Divide By Scalar Tests"
Cohesion: 0.50
Nodes (3): DivideByScalar, WorksWithFloat, TEST()

### Community 59 - "STD Fill Slope Tests"
Cohesion: 0.50
Nodes (3): FillSlope, FloatType, TEST()

### Community 60 - "STD Fraction Split Tests"
Cohesion: 0.50
Nodes (3): IntegerFractionSplit, WorksWithFloat, TEST()

### Community 61 - "IPP Compute Mean Value Tests"
Cohesion: 0.50
Nodes (3): IPP_ComputeAverage, Float, TEST()

### Community 62 - "STD Apply Square Tests"
Cohesion: 0.50
Nodes (3): ComplexFloat, TEST(), STD_ApplySqaure_Inplace

### Community 63 - "STD Compute Mean Value Tests"
Cohesion: 0.50
Nodes (3): Float, TEST(), STD_ComputeMeanValue

## Knowledge Gaps
- **16 isolated node(s):** `gbenchmark_install.sh script`, `status_`, `message_`, `func_name_`, `file_` (+11 more)
  These have ≤1 connection - possible missing edges or undocumented components.
- **3 thin communities (<3 nodes) omitted from report** — run `graphify query` to explore isolated nodes.

## Suggested Questions
_Questions this graph is uniquely positioned to answer:_

- **Are the 5 inferred relationships involving `Chord Library Project` (e.g. with `Maya K. (Author)` and `Team Kernels (Development Team)`) actually correct?**
  _`Chord Library Project` has 5 INFERRED edges - model-reasoned connections that need verification._
- **What connects `gbenchmark_install.sh script`, `status_`, `message_` to the rest of the system?**
  _16 weakly-connected nodes found - possible documentation gaps or missing edges._
- **Should `IPP Casting & Algorithm Utilities` be split into smaller, more focused modules?**
  _Cohesion score 0.05757575757575758 - nodes in this community are weakly interconnected._
- **Should `IPP Generate Tone Implementation` be split into smaller, more focused modules?**
  _Cohesion score 0.05204872646733112 - nodes in this community are weakly interconnected._
- **Should `IPP XOR Implementation` be split into smaller, more focused modules?**
  _Cohesion score 0.05128205128205128 - nodes in this community are weakly interconnected._
- **Should `IPP Multiply With Scalar Tests` be split into smaller, more focused modules?**
  _Cohesion score 0.07407407407407407 - nodes in this community are weakly interconnected._
- **Should `Status & Argument Validation Utilities` be split into smaller, more focused modules?**
  _Cohesion score 0.14 - nodes in this community are weakly interconnected._