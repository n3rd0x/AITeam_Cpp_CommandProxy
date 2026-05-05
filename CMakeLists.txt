cmake_minimum_required(VERSION 3.15)

project(CommandProxy
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "C++ command suggestion console application"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)

option(BUILD_TESTS
    "Build the unit tests"
    ON
)

add_executable(CommandProxy
    src/main.cpp
    src/app.cpp
)

target_include_directories(CommandProxy
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(CommandProxy
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
)

if(BUILD_TESTS)
    enable_testing()

    find_package(GTest REQUIRED)

    add_executable(tests
        test/test_main.cpp
        test/test_app.cpp
        src/app.cpp
    )

    target_include_directories(tests
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${GTEST_INCLUDE_DIRS}
    )

    target_link_libraries(tests
        PRIVATE
            ${GTEST_LIBRARIES}
    )

    target_compile_options(tests
        PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Werror
    )
endif()

install(TARGETS CommandProxy
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES
    LICENSE
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/CommandProxy
)