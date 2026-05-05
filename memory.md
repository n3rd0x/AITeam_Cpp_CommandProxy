# MEMORY.md

## Current Context
- Project initialized with C++20 console application structure
- Basic application class with init() and run() methods
- CMake build system configured for C++20
- GoogleTest for unit testing
- CMakePresets.json created with ucrt64 preset
- All 10 tests pass successfully

## Decisions
- Used C++20 standard for the project
- Chose CMake as the build system
- Used clang-format for C++ code formatting
- Set default run() to return false (to be implemented later)
- Created CMakePresets.json for standardized build configurations
- Set CMAKE_PREFIX_PATH to use MSYS_UCRT64 environment variable

## Next Step
- Resume feature implementation: Implement command matching/suggestion logic for the App class
- Need to modify App::run() to read from stdin and suggest matching commands