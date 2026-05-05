# C++ Command Proxy

A C++20 console application that reads stdin and suggests matching commands.

## Project Overview

**Type**: C++ console application
**Build System**: CMake
**Language**: C++20
**Target Platform**: GCC
**Dependencies**: gtest

## Project Structure

```
commandproxy.git/
├── src/               # .cpp definition files
├── include/           # .h declaration files
├── test/              # unit test files
├── build/
│   ├── app/           # compiled application output
│   └── test/          # compiled test output
├── CMakeLists.txt     # root build definition
├── CMakePresets.json  # CMake build presets
├── .clang-format      # C++ formatter config
├── .cmake-format.yaml # CMake formatter config
├── CLAUDE.md          # project rules and architecture
├── MEMORY.md          # current context and decisions
├── TASKS.md           # task backlog
├── PLAN.md            # current feature plan
├── CHANGELOG.md       # permanent record of what shipped
└── .claude/
    ├── settings.json  # Claude permissions
    ├── commands/      # slash command definitions (/start, /stop)
    └── archived/      # completed tasks, plans and memory snapshots
        └── YYYYMMDD/  # one folder per archived date
```

## Build & Run

```bash
# (Windows) Configure with preset (requires MSYS_UCRT64 env var set)
cmake --preset ucrt64 -DBUILD_TESTS=ON

# (Unix/macOS) Configure with preset
cmake --preset gcc -DBUILD_TESTS=ON

# Build everything
cmake --build build/ucrt64 --parallel

# Run app
./build/[ucrt64|gcc]/<AppName>.exe

# Run tests
./build/[ucrt64|gcc]/tests.exe

# Or via ctest
ctest --test-dir build/[ucrt64|gcc]
```

## Code Style

### Naming

| Construct        | Convention  | Example          | Note                                         |
|------------------|-------------|------------------|----------------------------------------------|
| Functions        | camelCase   | parseInput()     |                                              |
| Classes          | PascalCase  | InputParser      |                                              |
| Member variables | camelCase   | delimiter        | class fields only                            |
| Constants        | UPPER_SNAKE | MAX_SUGGESTIONS  |                                              |
| Local variables  | snake_case  | token_list       | variables declared inside function body only |
| Local variables  | camelCase   | numInputs        | variables declared inside classes            |
| Files            | PascalCase  | InputParser.cpp  |                                              |

### Header Template
#ifndef aiteam_cmdprx_MYCLASS_H
#define aiteam_cmdprx_MYCLASS_H

namespace aiteam {

class MyClass {
public:
    [[nodiscard]] std::string getValue() const;
    void printValue(std::string_view);

private:
    std::string value;
};

} // namespace aiteam

#endif // aiteam_cmdprx_MYCLASS_H

### Source Template
#include "MyClass.h"

namespace aiteam {


std::string MyClass::getValue() const {
    return "";
}


void MyClass::printValue(std::string_view sv) {
    std::cout << sv << std::end;
}


}

### Rules
- `header guard` in every header, prefix as `cmdprx` and suffix as `_H`
- `[[nodiscard]]` on every non-void return
- `std::string_view` for read-only string params
- No `using namespace` in headers
- Always two break lines between function implementation in source files
- One class per header/source pair

## Code Formatting

### Tools
- **clang-format**: C++ code formatting (`.clang-format` in project root)

### Usage
```bash
# Format all C++ files
clang-format -i src/ include/ test/
```

## CMake Style

- Commands in lowercase: add_executable() not ADD_EXECUTABLE()
- Keywords in uppercase: PRIVATE, PUBLIC, INTERFACE, TARGET
- 4 space indentation
- One argument per line when a command has more than 3 arguments
- Closing parenthesis aligned with the command name
- Always two blank lines between top-level blocks

Example:
add_executable(
    CommandProxy
    src/main.cpp
    src/app.cpp
)


target_include_directories(CommandProxy
    PRIVATE
        include
)


target_compile_options(CommandProxy
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)

### Conventions
- Use clang-format style with consistent indentation (4 spaces)
- CMake: standard formatting with comments explaining complex logic
- Keep formatting consistent across all source files

## Git Rules

- Every task gets its own branch before any code is written
- Branch naming: task/[id]-[short-description]
  - Example: task/001-add-fuzzy-match
  - Example: task/002-fix-input-parser
- Never work directly on main or dev
- Commit messages: [type]: [short description]
  - Example: feature: add fuzzy match to Suggester
  - Example: fix: handle empty input in InputParser
  - Example: bugfix: fix fuzzy mismatch
  - Example: docs: add fuzzy documentation
- Never commit automatically — only when told "commit now"
- Never push, merge, rebase, or switch branches — human only or when told
