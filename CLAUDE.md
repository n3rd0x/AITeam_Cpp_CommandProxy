# C++ Command Proxy

A C++20 console application that reads stdin and suggests matching commands.

## Project Overview

**Type**: C++ console application
**Build System**: CMake
**Language**: C++20
**Target Platform**: GCC
**Dependencies**: None (pure standard library)

## Project Structure

```
claude-cpp/
├── src/               # .cpp definition files
├── include/           # .h declaration files
├── test/              # unit test files
├── build/
│   ├── app/           # compiled application output
│   └── test/          # compiled test output
├── CMakeLists.txt     # root build definition
├── .clang-format      # C++ formatter config
├── .cmake-format.yaml # CMake formatter config
├── .claudeignore      # files hidden from Claude
├── CLAUDE.md          # project rules and architecture
├── memory.md          # current context and decisions
├── TASKS.md           # task backlog
├── PLAN.md            # current feature plan
├── CHANGELOG.md       # permanent record of what shipped
└── .claude/
    ├── settings.json  # Claude permissions
    ├── commands/      # slash command definitions (/start, /stop)
    └── archived/      # completed tasks, plans and memory snapshots
        └── yyyyMMdd/  # one folder per archived date
```

## Build & Run

```bash
# Configure
cmake -S . -B build -G "Unix Makefiles" -DBUILD_TESTS=ON

# Build everything
cmake --build build --parallel

# Run app
./build/app/bin/CommandProxy.exe

# Run tests
./build/tests/bin/tests.exe

# Or via ctest
ctest --test-dir build
```

## Code Style

### Naming
| Construct        | Convention  | Example             |
|------------------|-------------|---------------------|
| Functions        | camelCase   | parseInput()        |
| Classes          | PascalCase  | InputParser         |
| Member variables | camelCase   | delimiter           |
| Constants        | UPPER_SNAKE | MAX_SUGGESTIONS     |
| Local variables  | lower_snake | token_list          |
| Files            | PascalCase  | InputParser.cpp     |

### Header Template
#ifndef cmdprxMYCLASS_H
#define cmdprxMYCLASS_H

namespace suggest {

class MyClass {
public:
    [[nodiscard]] std::string getValue() const;
    void printValue(std::string_view);

private:
    std::string value;
};

} // namespace suggest

#endif

### Rules
- `header guard` in every header, prefix as `cmdprx` and suffix as `_H`
- `[[nodiscard]]` on every non-void return
- `std::string_view` for read-only string params
- No `using namespace` in headers
- One class per header/source pair

## Code Formatting

### Tools
- **clang-format**: C++ code formatting (`.clang-format` in project root)
- **cmake-format**: CMakeLists.txt formatting (`.cmake-format.yaml` in project root)

### Usage
```bash
# Format all C++ files
clang-format -i src/ include/ test/

# Format CMake files
cmake-format -i CMakeLists.txt
```

## CMake Style

- Commands in lowercase: add_executable() not ADD_EXECUTABLE()
- Keywords in uppercase: PRIVATE, PUBLIC, INTERFACE, TARGET
- 4 space indentation
- One argument per line when a command has more than 3 arguments
- Closing parenthesis aligned with the command name
- Two blank line between top-level blocks

Example:
add_executable(
    CommandSuggest
    src/main.cpp
    src/app.cpp
)


target_include_directories(CommandSuggest
    PRIVATE
        include
)


target_compile_options(CommandSuggest
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
- Never push — commits stay local until human reviews