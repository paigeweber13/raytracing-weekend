# Raytracing in one Weekend

Made while following Peter Shirley's awesome
book, [available here](https://raytracing.github.io/)

# Prerequisistes

- A C++ compiler
- GNU make
- CMake
- [fmt](https://github.com/fmtlib/fmt) v6.1.2 - installable on ubuntu 20.04 
  with `sudo apt install libfmt-dev`
- (Optional) [Catch2](https://github.com/catchorg/Catch2) v2.13.6 - follow 
  the [directions here](https://github.com/catchorg/Catch2/blob/v2.x/docs/cmake-integration.md#installing-catch2-from-git-repository) and be 
  sure to check out tag v2.13.6 before installing.

# Running

First, build executables:

1. `mkdir build && cd build`
3. `cmake ..`
4. `make`

Next, (assuming you are still in the `build` directory) run the software with
`./wrtx`. You may run tests with `./wrtx-test`. Catch2 must be installed
for tests to work.
 