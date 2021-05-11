cmake_minimum_required(VERSION 3.15)
project(AhoCorasick)

set(AC "${PROJECT_NAME}")

# option for debug (debug info)
set(PR_DEBUG_OPTIONS -g)

# some useful warnings
set(WARN_OPTIONS
  -Wall -Wextra -Wunused -Wpedantic
  -Wno-old-style-cast -Waggressive-loop-optimizations
  -Wunreachable-code)

add_executable(${AC} main.cc AhoCor.cc)

target_compile_features(${AC} PRIVATE cxx_std_17)
target_compile_options(${AC} PRIVATE ${WARN_OPTIONS})
target_compile_options(${AC} PRIVATE "$<$<CONFIG:DEBUG>:${PR_DEBUG_OPTIONS}>")
