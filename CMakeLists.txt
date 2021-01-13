cmake_minimum_required(VERSION 3.15)

# TODO: Rename this to your desired project name.
project(myproject CXX)

include(cmake/StandardProjectSettings.cmake)

# Link this 'library' to set the C++ standard / compile-time options requested.
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

# Link this 'library' to use warnings specified in CompilerWarnings.cmake.
add_library(project_warnings INTERFACE)

# Standard compiler warnings.
include(cmake/CompilerWarnings.cmake)
# TODO: Uncomment the following line and fix the issues that come up.
# set_project_warnings(project_warnings)

# Conan
include(cmake/Conan.cmake)
run_conan()

include_directories(include)
add_subdirectory(src)
