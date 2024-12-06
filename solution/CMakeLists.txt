cmake_minimum_required(VERSION 3.16)

project(cwk2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and link Qt components
find_package(Qt6 REQUIRED COMPONENTS Widgets Charts)
qt_standard_project_setup()

# Define the executable and sources
qt_add_executable(quaketool
    main.cpp
    quake.cpp
    dataset.cpp
    model.cpp
    window.cpp
    stats.cpp
    dashboard.cpp
    pops.cpp
)

# Link Qt libraries
target_link_libraries(quaketool PRIVATE Qt6::Widgets Qt6::Charts)

set_target_properties(quaketool PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)