from pathlib import Path

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import copy


class ChordConan(ConanFile):
    name = "chord"
    version = "1.0.0"
    author = "mkmagic"
    url = "https://github.com/mkmagic/chord"
    description = "C.H.O.R.D - Computational Hardware Optimized library for Realtime DSP"
    topics = ("neon", "ipp", "math", "cpu", "dsp")

    settings = "os", "compiler", "build_type", "arch"

    # Files to export with the recipe and to send to the build
    exports_sources = (
        "CMakeLists.txt",
        "src/*",
        "include/*",
        "cmake/*",
        "README.md",
        "conanfile.py",
    )

    generators = "CMakeToolchain", "CMakeDeps"

    def layout(self):
        cmake_layout(self)

    def build_requirements(self):
        self.tool_requires("cmake/3.19.8")

    def requirements(self):
        # Chord needs IPP, but it is not in conan
        pass

    def build(self):
        cmake = CMake(self)
        cmake.configure()

        cmake.build(target="chord")

        # install target will place artifacts into the package folder
        cmake.install()

    def package(self):
        # Copy license if present
        copy(self, "LICENSE*", src=self.source_folder, dst=self.package_folder, keep_path=False)

    def package_info(self):
        # Consumers should link to `chord` library
        self.cpp_info.libs = ["chord"]
        # Provide a CMake package name for downstream consumers
        self.cpp_info.set_property("cmake_file_name", "chord")
        self.cpp_info.set_property("cmake_target_name", "chord::chord")
