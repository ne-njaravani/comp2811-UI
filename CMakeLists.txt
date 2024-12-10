cmake_minimum_required(VERSION 3.16)

project(cwk2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and link Qt components
find_package(Qt6 REQUIRED COMPONENTS Widgets Charts Core Quick QuickWidgets QuickControls2 Location Positioning REQUIRED)
qt_standard_project_setup()

# Define the executable and sources
qt_add_executable(watertool
    main.cpp
    window.cpp
    dashboard.cpp
    pops.cpp
    fluorinated.cpp
    pollutantOverview.cpp
    envlitter.cpp
    compliance.cpp
)

# Link Qt libraries
target_link_libraries(watertool PRIVATE Qt6::Widgets Qt6::Charts Qt6::Core Qt6::Quick Qt6::QuickWidgets Qt6::QuickControls2 Qt6::Location Qt6::Positioning)

set_target_properties(watertool PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE ON
)