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

# This is probably pointless ...
set(ENV{PROJECT_TITLE} template_game)

add_executable($ENV{PROJECT_TITLE} "")
add_subdirectory(src)

target_link_libraries(
    $ENV{PROJECT_TITLE}
    PRIVATE project_options
            project_warnings
            CONAN_PKG::sfml
)

# When you decide to run multiple subdirs in your include
# folder, call this in each CMakeLists file and try to
# instead make it mirror the include structure ...
target_include_directories($ENV{PROJECT_TITLE} PRIVATE include)

# Move resources to build dir
file(COPY res DESTINATION ${CMAKE_BINARY_DIR}/Debug)
