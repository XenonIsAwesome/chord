//
// Created by userk on 5/15/25.
//

#pragma once

#include <chord/chord_structs.hpp>

#ifdef INTEL_PRESENT
#    if __has_include(<ipp/ippversion.h>)
#        include <ipp/ipp.h>
#    elif __has_include(<ippversion.h>)
#        include <ipp.h>
#    else
#        error "IPP Version not supported"
#    endif
#endif

#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>

#define STATUS_RESULT(status, ...) \
    return StatusResult(status, __VA_ARGS__, __func__, __FILE__, __LINE__);


namespace chord {

class StatusResult {
public:
    /**
     * "Default constructor" for when status is ok, no error detected.
     *
     * @param func_name function name
     * @param file file in which function exists
     * @param line line number of function in file
     */
    explicit StatusResult(std::string func_name, std::string file, int line) :
        status_(Status::Ok), func_name_(std::move(func_name)), file_(std::move(file)), line_(line) {
    }

    explicit StatusResult() : status_(Status::Ok) {}

    explicit StatusResult(Status status,
                          std::string message,
                          std::string function,
                          std::string file,
                          int line) :
        status_(status), message_(std::move(message)), func_name_(std::move(function)),
        file_(std::move(file)), line_(line) {}


#ifdef INTEL_PRESENT
    /**
     * Returns static map that holds the IppStatus and its corrolating string describing the status.
     *
     * @return unordered map of Ippstatuses and their strings describing them.
     */
    static std::unordered_map<IppStatus, const std::string> get_ipp_status_map() {
        static const std::unordered_map<IppStatus, const std::string> ipp_status_messages = {
            {ippStsNoErr, "No error."},
            {ippStsCpuNotSupportedErr, "The target cpu is not supported."},
            {ippStsUnknownStatusCodeErr, "Unknown status code."},
            {ippStsLzoBrokenStreamErr, "LZO safe decompression function cannot decode LZO stream."},
            {ippStsRoundModeNotSupportedErr, "Rounding mode is not supported."},
            {ippStsRegExpOptionsErr, "RegExp: Options for the pattern are incorrect."},
            {ippStsRegExpErr, "RegExp: The structure pRegExpState contains wrong data."},
            {ippStsRegExpMatchLimitErr, "RegExp: The match limit has been exhausted."},
            {ippStsRegExpQuantifierErr, "RegExp: Incorrect quantifier."},
            {ippStsRegExpGroupingErr, "RegExp: Incorrect grouping."},
            {ippStsRegExpBackRefErr, "RegExp: Incorrect back reference."},
            {ippStsRegExpChClassErr, "RegExp: Incorrect character class."},
            {ippStsRegExpMetaChErr, "RegExp: Icnorrect metacharacter."},
            {ippStsLengthErr, "Incorrect value for string length."},
            {ippStsToneMagnErr, "Tone magnitude is less than or equal to zero."},
            {ippStsToneFreqErr, "Tone frequency is negative, or greater than or equal to 0.5."},
            {ippStsTonePhaseErr, "Tone phase is negative, or greater than or equal to 2*PI."},
            {ippStsTrnglMagnErr, "Triangle magnitude is less than or equal to zero."},
            {ippStsTrnglFreqErr,
             "Triangle frequency is negative, or greater than or equal to 0.5."},
            {ippStsTrnglPhaseErr, "Triangle phase is negative, or greater than or equal to 2*PI."},
            {ippStsTrnglAsymErr,
             "Triangle asymmetry is less than -PI, or greater than or equal to PI."},
            {ippStsHugeWinErr, "The Kaiser window is too big."},
            {ippStsJaehneErr, "Magnitude value is negative."},
            {ippStsStepErr, "Step value is not valid."},
            {ippStsStrideErr, "Stride value is less than length of the row."},
            {ippStsEpsValErr, "Negative epsilon value."},
            {ippStsScaleRangeErr, "Scale bounds are out of range."},
            {ippStsThresholdErr, "Invalid threshold bounds."},
            {ippStsWtOffsetErr, "Invalid offset value for wavelet filter."},
            {ippStsAnchorErr, "Anchor point is outside the mask."},
            {ippStsMaskSizeErr, "Invalid mask size."},
            {ippStsShiftErr, "Shift value is less than zero."},
            {ippStsSampleFactorErr, "Sampling factor is less than or equal to zero."},
            {ippStsSamplePhaseErr, "Phase value is out of range, 0 ≤ phase < factor."},
            {ippStsFIRMRFactorErr, "MR FIR sampling factor is less than or equal to zero."},
            {ippStsFIRMRPhaseErr,
             "MR FIR sampling phase parameter is negative, or greater than or equal to the "
             "sampling factor."},
            {ippStsRelFreqErr, "Relative frequency value is out of range."},
            {ippStsFIRLenErr, "Length of the FIR filter is less than or equal to zero."},
            {ippStsIIROrderErr, "Order of the IIR filter is not valid."},
            {ippStsResizeFactorErr, "Resize factor(s) is less than or equal to zero."},
            {ippStsDivByZeroErr, "An attempt to divide by zero."},
            {ippStsInterpolationErr, "Invalid interpolation mode."},
            {ippStsMirrorFlipErr, "Invalid flip mode."},
            {ippStsMoment00ZeroErr, "Moment value M(0,0) is too small to continue calculations."},
            {ippStsThreshNegLevelErr, "Negative value of the level in the threshold operation."},
            {ippStsContextMatchErr, "Context parameter does not match the operation."},
            {ippStsFftFlagErr, "Invalid value for the FFT flag parameter."},
            {ippStsFftOrderErr, "Invalid value for the FFT order parameter."},
            {ippStsMemAllocErr, "Not enough memory for the operation."},
            {ippStsNullPtrErr, "Null pointer error."},
            {ippStsSizeErr, "Incorrect value for data size."},
            {ippStsBadArgErr, "Incorrect argument/parameter of the function."},
            {ippStsErr, "Unknown/unspecified error."},
            {ippStsNoOperation, "No operation has been executed."},
            {ippStsSqrtNegArg, "Negative value(s) of the argument in the function Sqrt ."},
            {ippStsEvenMedianMaskSize,
             "Even size of the Median Filter mask was replaced by the odd one."},
            {ippStsDivByZero, "Even size of the Median Filter mask was replaced by the odd one."},
            {ippStsLnZeroArg, "Zero value(s) of the argument in the function Ln ."},
            {ippStsLnNegArg, "Negative value(s) of the argument in the function Ln ."},
            {ippStsNanArg, "Argument value is not a number."},
            {ippStsOverflow, "Overflow in the operation."},
            {ippStsUnderflow, "Underflow in the operation."},
            {ippStsSingularity, "Singularity in the operation."},
            {ippStsDomain, "Argument is out of the function domain."},
            {ippStsCpuMismatch, "Cannot set the library for the given cpu."},
            {ippStsOvermuchStrings, "Number of destination strings is more than expected."},
            {ippStsOverlongString,
             "Length of one of the destination strings is more than expected."},
            {ippStsSrcSizeLessExpected,
             "DC: The size of source buffer is less than the expected one."},
            {ippStsDstSizeLessExpected,
             "DC: The size of destination buffer is less than the expected one."},
            {ippStsNotSupportedCpu, "The CPU is not supported."},
            {ippStsAlgTypeErr, "The algorithm type is not supported."}};

        return ipp_status_messages;
    }

    static std::string get_ipp_status_message(IppStatus ipp_status) {
        return get_ipp_status_map().at(ipp_status);
    }

    /**
     * @brief Constructor that recieves IppStatus(along with other params) and converts to
     * StatusResult.
     *
     * Converts from all possible ipp statues to according StatusResult by logic, and type of error,
     * passing the error message IppStatus holds to message_ param in StatusResult.
     *
     * For example: \n
     * If ipp function returned an ippStsNullPtrErr, in which case a null pointer was
     * passed to function causing this error to be returned. \n
     * So accordingly, for StatusResult: \n
     * status_ will be : Status::InvalidParamter \n
     * message_ will be: "Null pointer error."
     *
     * @param ipp_status IppStatus recieved from ipp function called inside.
     * @param func_name name of the function called.
     * @param file file name in which function exists.
     * @param line line of function in file.
     */
    explicit StatusResult(IppStatus ipp_status, std::string func_name, std::string file, int line) :
        func_name_(std::move(func_name)), file_(std::move(file)), line_(line) {
        switch (ipp_status) {
            case ippStsNoErr:
            case ippStsNoOperation:
                status_ = Status::Ok;
                break;

            case ippStsCpuNotSupportedErr:
            case ippStsNotSupportedCpu:
                status_ = Status::CpuNotSupported;
                break;

            case ippStsUnknownStatusCodeErr:
            case ippStsLzoBrokenStreamErr:
            case ippStsRoundModeNotSupportedErr:
            case ippStsErr:
                status_ = Status::NotImplemented;
                break;

            case ippStsRegExpOptionsErr:
            case ippStsRegExpErr:
            case ippStsRegExpMatchLimitErr:
            case ippStsRegExpQuantifierErr:
            case ippStsRegExpGroupingErr:
            case ippStsRegExpBackRefErr:
            case ippStsRegExpChClassErr:
            case ippStsRegExpMetaChErr:
                status_ = Status::RegExpError;
                break;

            case ippStsLengthErr:
            case ippStsToneMagnErr:
            case ippStsToneFreqErr:
            case ippStsTonePhaseErr:
            case ippStsTrnglMagnErr:
            case ippStsTrnglFreqErr:
            case ippStsTrnglPhaseErr:
            case ippStsTrnglAsymErr:
            case ippStsHugeWinErr:
            case ippStsJaehneErr:
            case ippStsStepErr:
            case ippStsStrideErr:
            case ippStsEpsValErr:
            case ippStsScaleRangeErr:
            case ippStsThresholdErr:
            case ippStsWtOffsetErr:
            case ippStsAnchorErr:
            case ippStsMaskSizeErr:
            case ippStsShiftErr:
            case ippStsSampleFactorErr:
            case ippStsSamplePhaseErr:
            case ippStsFIRMRFactorErr:
            case ippStsFIRMRPhaseErr:
            case ippStsRelFreqErr:
            case ippStsFIRLenErr:
            case ippStsIIROrderErr:
            case ippStsResizeFactorErr:
            case ippStsDivByZeroErr:
            case ippStsInterpolationErr:
            case ippStsMirrorFlipErr:
            case ippStsMoment00ZeroErr:
            case ippStsThreshNegLevelErr:
            case ippStsFftFlagErr:
            case ippStsFftOrderErr:
            case ippStsNullPtrErr:
            case ippStsSizeErr:
            case ippStsBadArgErr:
            case ippStsOvermuchStrings:
            case ippStsOverlongString:
            case ippStsSrcSizeLessExpected:
            case ippStsDstSizeLessExpected:
            case ippStsAlgTypeErr:
                status_ = Status::InvalidParamter;
                break;

            case ippStsContextMatchErr:
            case ippStsSqrtNegArg:
            case ippStsEvenMedianMaskSize:
            case ippStsDivByZero:
            case ippStsLnZeroArg:
            case ippStsLnNegArg:
            case ippStsNanArg:
            case ippStsOverflow:
            case ippStsUnderflow:
            case ippStsSingularity:
            case ippStsDomain:
            case ippStsCpuMismatch:
                status_ = Status::Warning;
                break;

            case ippStsMemAllocErr:
                status_ = Status::MemoryError;
                break;

            case ippStsOutOfRangeErr:
                status_ = Status::OutOfRange;
                break;

            default:
                status_ = Status::Unknown;
                break;
        }

        message_ = get_ipp_status_message(ipp_status);
    }
#endif

    [[nodiscard]] bool is_success() const {
        if (status_ == Status::Ok) {}
        return status_ == Status::Ok;
    }

    [[nodiscard]] bool is_fail() const {
        return !is_success();
    }

    [[nodiscard]] Status get_status() const {
        return status_;
    }

    [[nodiscard]] std::string get_message() const {
        return message_;
    }

    [[nodiscard]] std::string get_func_name_name() const {
        return func_name_;
    }

    [[nodiscard]] std::string get_file_name() const {
        return file_;
    }

    [[nodiscard]] unsigned int get_line_num() const {
        return line_;
    }

    [[nodiscard]] std::string to_string() const {
        if (is_success()) {
            return "Success";
        }
        return ("Error message: " + message_ + "\nIn function: " + func_name_ +
                "\nIn file: " + file_ + ": line " + std::to_string(line_));
    }

    /**
     * @return true if status is "success", false otherwise.
     */
    bool operator!() const {
        return is_fail();
    }

    /**
     * @return true if status is "success", false otherwise.
     */
    explicit operator bool() const {
        return is_success();
    }

    friend std::ostream& operator<<(std::ostream& os, const StatusResult& status) {
        os << status.to_string();
        return os;
    }


private:
    Status status_;
    std::string message_;
    std::string func_name_;
    std::string file_;
    unsigned int line_;
};

}  // namespace chord