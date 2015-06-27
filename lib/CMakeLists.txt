add_library(foo Foo.cpp)

# We mostly use a PUBLIC scope here so that we build
# with those options/defines/includes and any targets that link
# with Foo also build with those options/defines/includes.
target_include_directories(foo PUBLIC ${LLVM_INCLUDE_DIRS})
target_compile_definitions(foo PUBLIC ${LLVM_DEFINITIONS})

if (NOT LLVM_ENABLE_RTTI)
  if (NOT MSVC)
    target_compile_options(foo PUBLIC "-fno-rtti")
  else()
    target_compile_options(foo PUBLIC "/GR-")
  endif()
endif()

if (NOT LLVM_ENABLE_EH)
  if (NOT MSVC)
    target_compile_options(foo PUBLIC "-fno-exceptions")
  else()
    target_compile_options(foo PUBLIC "/EHs-c-")
    target_compile_definitions(foo PUBLIC "_HAS_EXCEPTIONS=0")
  endif()
endif()

# LLVM requires C++11
if (NOT MSVC)
  target_compile_options(foo PUBLIC "-std=c++11")
endif()

# The INTERFACE scope means that any target that links
# against Foo will also implicitly link against
# the requested LLVM libraries.
llvm_map_components_to_libnames(LLVM_LIBS support)
target_link_libraries(foo INTERFACE ${LLVM_LIBS})
