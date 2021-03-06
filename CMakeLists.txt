cmake_minimum_required(VERSION 3.15)

# Set project name ...
project(SFML_template CXX)

include(cmake/StandardProjectSettings.cmake)

# Link this 'library' to set the C++ standard / compile-time options requested ...
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

# Link this 'library' to use warnings specified in CompilerWarnings.cmake ...
add_library(project_warnings INTERFACE)

# Standard compiler warnings.
include(cmake/CompilerWarnings.cmake)

# TODO: Uncomment the following line and fix the issues that come up ...
# set_project_warnings(project_warnings)

# Conan
include(cmake/Conan.cmake)
run_conan()

add_executable(${CMAKE_PROJECT_NAME} "")
add_subdirectory(src)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        project_options
        project_warnings
        CONAN_PKG::sfml
        CONAN_PKG::fmt
)

# Compile list of user include dirs ...
list(APPEND include_list
    include
    include/Entities
    include/Managers
    include/Screens
)

# Add user include list ...
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${include_list})

# Add CMB classes ...
add_subdirectory(CMB)

# Move resources to build dir ...
file(COPY res DESTINATION ${CMAKE_BINARY_DIR}/Debug)
