# Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# When Makefiles are generated, output all command lines by default
set(CMAKE_VERBOSE_MAKEFILE ON)

# Declare the build of the mpags-cipher main program
add_executable(mpags-cipher.out mpags-cipher.cpp MPAGSCipher/TransformChar.cpp MPAGSCipher/ProcessCommandLine.cpp)

target_include_directories(mpags-cipher.out
  PRIVATE MPAGSCipher
  )
# Set the C++ standard directly
set(CMAKE_CXX_STANDARD 14)

# Using all our compile flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")

target_compile_features(mpags-cipher.out
  PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization
  )
