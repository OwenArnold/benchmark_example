Toy Examples for use with google benchmark v1.1.0

Requires:

* CMake 2.6 or greater
* GCC or LLVM with c++11 features
* [Google benchmark](https://github.com/google/benchmark) built from source

Example CMake Configuration:

```
cmake -DCMAKE_BUILD_TYPE=Release -G"CodeBlocks - Unix Makefiles" -DGBENCH_SOURCE_DIR=~/sources/benchmark -DGBENCH_BUILD_DIR=~/builds/googlebenchmark/ ~/sources/benchmark_example/
```
