project(llvmCMakeImportDemo)
cmake_minimum_required(VERSION 2.8.12)

# The user can pass -DLLVM_DIR=/path/to/dir/containing/LLVMConfig.cmake
# to use a particular LLVM build tree or installation.
find_package(LLVM CONFIG REQUIRED)

message(STATUS "LLVM_PACKAGE_VERSION: ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")

# Generate Config.h
configure_file(${CMAKE_SOURCE_DIR}/include/llvmCMakeImportDemo/Config.h.in
               ${CMAKE_BINARY_DIR}/include/llvmCMakeImportDemo/Config.h)

# Setup this project's global includes
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_BINARY_DIR}/include)

add_subdirectory(lib)
add_subdirectory(tools)
