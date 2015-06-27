# LLVM CMake Import Demo

This small project serves to demonstrate how to write a CMake project
that uses LLVM via its exported CMake targets.

## Building on *BSD/Linux/OSX

The most basic commands to build on OSX/Linux are as follows:

```
$ mkdir build
$ cd build
$ cmake <src>
$ make
```

where ``<src>`` is the path to the root of this repository.

When CMake is invoked on this project it will automatically try to search a set
of paths for a directory containing a file called ``LLVMConfig.cmake``. If it
cannot find it will produce an error.

You can give CMake a hint where to look passing it the path to the directory
containing the ``LLVMConfig.cmake`` file on your system by setting the ``LLVM_DIR``
cache variable. For example:

```
cmake -DLLVM_DIR=<LLVMConfig_DIR> <src>
```

where ``<LLVMConfig_DIR>`` is the path to the directory containing the ``LLVMConfig.cmake``
file.

This file is available is two places

* If you built LLVM from source using CMake then it is available from the LLVM build tree in ``share/llvm/cmake``.
* If LLVM is installed on your system then it will be located somewhere in your installation directory.
  On Linux it is typically available in ``/usr/share/llvm/cmake/`` (``/usr/share/llvm-<VERSION>/cmake`` on Debian/Ubuntu systems).

## Building on Windows

Building is very similar to the above except you will most likely be using the
Visual Studio generator rather than the makefile generator. For example

```
mkdir build
cd build
cmake -G "Visual Studio 12" <src>
```

You can then open the created ``llvmCMakeImportDemo.sln`` file with Visual Studio and build.

Note on Windows you cannot mix Debug and Release code so the project must be built with
the same configuration that LLVM was built with.
