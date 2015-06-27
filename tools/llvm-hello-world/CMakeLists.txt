add_executable(llvm-hello-world main.cpp)
target_link_libraries(llvm-hello-world PRIVATE foo)
