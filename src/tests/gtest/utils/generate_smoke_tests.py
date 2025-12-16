import argparse
import re
import os
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument("--header", required=True)
parser.add_argument("--output", required=True)
args = parser.parse_args()

HEADER_FILE = Path(args.header)
OUTPUT_FILE = Path(args.output)

FILE_INCLUDES = """#include <gtest/gtest.h>
#include <lib.hpp>
#include "smoke_tests_generated.hpp"
"""

IGNORED_FUNCTIONS = ["init", "compute_xor", "generate_FFT_sizes", "generate_DFT_sizes"]  # TODO: fix generate sizes


def default_args_for_type(typ):
    typ = typ.strip()

    if "std::span<const std::complex" in typ:
        return "std::span<std::complex<float>>()"
    if "std::span<std::complex" in typ:
        return "std::span<std::complex<float>>()"
    if "std::span" in typ:
        return "std::span<float>()"
    if "std::complex<float>" in typ:
        return "std::complex<float>(0.0f, 0.0f)"
    if "std::complex<double>" in typ:
        return "std::complex<double>(0.0, 0.0)"
    if "float&" in typ:
        return "FLOAT"
    if "int&" in typ:
        return "INT"
    if "T&" in typ:
        return "FLOAT"
    if "WorkBufferSizes&" in typ:
        return "BUFFER"
    if "std::string" in typ:
        return "test"
    if "float" in typ:
        return "0"
    if "int" in typ:
        return "0"
    if "double" in typ or "float" in typ:
        return "0.0"
    if typ.endswith("*"):
        return "{}"

    return "{}"


def extract_functions(header_path):
    with open(header_path, "r") as f:
        content = f.read()

    # remove comments
    content = re.sub(r"//.*", "", content)
    content = re.sub(r"/\*.*?\*/", "", content, flags=re.DOTALL)

    lines = content.splitlines()
    funcs = []
    template_type = None

    template_pattern = re.compile(r'^\s*template\s*<\s*typename\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*>')
    func_pattern = re.compile(r'^\s*([\w:<>]+(?:\s+[\w:<>]+)?)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*\(([^)]*)\)\s*;')

    for line in lines:
        line = line.strip()
        template_match = template_pattern.match(line)
        if template_match:
            template_type = template_match.group(1)
            continue

        match = func_pattern.match(line)
        if match:
            return_type = match.group(1).strip()
            name = match.group(2).strip()
            args = match.group(3).strip()

            arg_types = []
            if args:
                for arg in args.split(','):
                    if '=' in arg:
                        arg = arg.split('=')[0].strip()

                    parts = arg.strip().split()
                    if len(parts) >= 2:
                        arg_type = " ".join(parts[:-1])
                        arg_types.append(arg_type)
                    else:
                        arg_types.append("float")

            funcs.append(
                {"name": name,
                 "return_type": return_type,
                 "args": arg_types,
                 "is_template": template_type is not None,
                 "template_param": template_type})

            template_type = None
    return funcs


def generate_tests(functions):
    lines = [FILE_INCLUDES]
    lines.append("\nTEST(LIB_GeneratedSmokeTests, AllFunctionsCompileAndLink) {")

    for func in functions:
        if func["name"] in IGNORED_FUNCTIONS:
            continue
        arg_types = ", ".join(default_args_for_type(arg) for arg in func["args"])
        template_str = f"<float>" if func["is_template"] else ""
        call_expr = f"{func['name']}{template_str}({arg_types})"

        if func["return_type"] != "void":
            call_expr = f"chord::{func['return_type']} result = chord::{call_expr}; (void)result;"
        else:
            call_expr += ";"

        lines.append("    EXPECT_NO_THROW({")
        lines.append(f"        {call_expr}")
        lines.append("    });\n")

    lines.append("}")
    return "\n".join(lines)


def main():
    if not os.path.exists(HEADER_FILE):
        print(f"Could not find header file: {HEADER_FILE}")
        return

    funcs = extract_functions(HEADER_FILE)
    if not funcs:
        print("Could not extract functions(no functions found in header)")
        return

    test_code = generate_tests(funcs)
    with open(OUTPUT_FILE, "w") as f:
        f.write(test_code)
    print(f"Generated: {HEADER_FILE}")


if __name__ == "__main__":
    main()
