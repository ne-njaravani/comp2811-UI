# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build"

# Utility rule file for watertool_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/watertool_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/watertool_autogen_timestamp_deps.dir/progress.make

watertool_autogen_timestamp_deps: CMakeFiles/watertool_autogen_timestamp_deps.dir/build.make
.PHONY : watertool_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/watertool_autogen_timestamp_deps.dir/build: watertool_autogen_timestamp_deps
.PHONY : CMakeFiles/watertool_autogen_timestamp_deps.dir/build

CMakeFiles/watertool_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/watertool_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/watertool_autogen_timestamp_deps.dir/clean

CMakeFiles/watertool_autogen_timestamp_deps.dir/depend:
	cd "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles/watertool_autogen_timestamp_deps.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/watertool_autogen_timestamp_deps.dir/depend
