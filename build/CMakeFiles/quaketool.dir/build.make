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
CMAKE_SOURCE_DIR = "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build"

# Include any dependencies generated for this target.
include CMakeFiles/quaketool.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/quaketool.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/quaketool.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/quaketool.dir/flags.make

quaketool_autogen/timestamp: /Users/Sultan/Qt/6.7.3/macos/libexec/moc
quaketool_autogen/timestamp: /Users/Sultan/Qt/6.7.3/macos/libexec/uic
quaketool_autogen/timestamp: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target quaketool"
	/opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E cmake_autogen "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles/quaketool_autogen.dir/AutogenInfo.json" Debug
	/opt/homebrew/Cellar/cmake/3.30.4/bin/cmake -E touch "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/quaketool_autogen/timestamp"

CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o: quaketool_autogen/mocs_compilation.cpp
CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o -MF CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/quaketool_autogen/mocs_compilation.cpp"

CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/quaketool_autogen/mocs_compilation.cpp" > CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.i

CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/quaketool_autogen/mocs_compilation.cpp" -o CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.s

CMakeFiles/quaketool.dir/main.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/main.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/main.cpp
CMakeFiles/quaketool.dir/main.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/quaketool.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/main.cpp.o -MF CMakeFiles/quaketool.dir/main.cpp.o.d -o CMakeFiles/quaketool.dir/main.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/main.cpp"

CMakeFiles/quaketool.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/main.cpp" > CMakeFiles/quaketool.dir/main.cpp.i

CMakeFiles/quaketool.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/main.cpp" -o CMakeFiles/quaketool.dir/main.cpp.s

CMakeFiles/quaketool.dir/quake.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/quake.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/quake.cpp
CMakeFiles/quaketool.dir/quake.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/quaketool.dir/quake.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/quake.cpp.o -MF CMakeFiles/quaketool.dir/quake.cpp.o.d -o CMakeFiles/quaketool.dir/quake.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/quake.cpp"

CMakeFiles/quaketool.dir/quake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/quake.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/quake.cpp" > CMakeFiles/quaketool.dir/quake.cpp.i

CMakeFiles/quaketool.dir/quake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/quake.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/quake.cpp" -o CMakeFiles/quaketool.dir/quake.cpp.s

CMakeFiles/quaketool.dir/dataset.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/dataset.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/dataset.cpp
CMakeFiles/quaketool.dir/dataset.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/quaketool.dir/dataset.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/dataset.cpp.o -MF CMakeFiles/quaketool.dir/dataset.cpp.o.d -o CMakeFiles/quaketool.dir/dataset.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/dataset.cpp"

CMakeFiles/quaketool.dir/dataset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/dataset.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/dataset.cpp" > CMakeFiles/quaketool.dir/dataset.cpp.i

CMakeFiles/quaketool.dir/dataset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/dataset.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/dataset.cpp" -o CMakeFiles/quaketool.dir/dataset.cpp.s

CMakeFiles/quaketool.dir/model.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/model.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/model.cpp
CMakeFiles/quaketool.dir/model.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/quaketool.dir/model.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/model.cpp.o -MF CMakeFiles/quaketool.dir/model.cpp.o.d -o CMakeFiles/quaketool.dir/model.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/model.cpp"

CMakeFiles/quaketool.dir/model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/model.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/model.cpp" > CMakeFiles/quaketool.dir/model.cpp.i

CMakeFiles/quaketool.dir/model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/model.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/model.cpp" -o CMakeFiles/quaketool.dir/model.cpp.s

CMakeFiles/quaketool.dir/window.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/window.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/window.cpp
CMakeFiles/quaketool.dir/window.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/quaketool.dir/window.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/window.cpp.o -MF CMakeFiles/quaketool.dir/window.cpp.o.d -o CMakeFiles/quaketool.dir/window.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/window.cpp"

CMakeFiles/quaketool.dir/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/window.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/window.cpp" > CMakeFiles/quaketool.dir/window.cpp.i

CMakeFiles/quaketool.dir/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/window.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/window.cpp" -o CMakeFiles/quaketool.dir/window.cpp.s

CMakeFiles/quaketool.dir/stats.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/stats.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/stats.cpp
CMakeFiles/quaketool.dir/stats.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/quaketool.dir/stats.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/stats.cpp.o -MF CMakeFiles/quaketool.dir/stats.cpp.o.d -o CMakeFiles/quaketool.dir/stats.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/stats.cpp"

CMakeFiles/quaketool.dir/stats.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/stats.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/stats.cpp" > CMakeFiles/quaketool.dir/stats.cpp.i

CMakeFiles/quaketool.dir/stats.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/stats.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/stats.cpp" -o CMakeFiles/quaketool.dir/stats.cpp.s

CMakeFiles/quaketool.dir/dashboard.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/dashboard.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/dashboard.cpp
CMakeFiles/quaketool.dir/dashboard.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/quaketool.dir/dashboard.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/dashboard.cpp.o -MF CMakeFiles/quaketool.dir/dashboard.cpp.o.d -o CMakeFiles/quaketool.dir/dashboard.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/dashboard.cpp"

CMakeFiles/quaketool.dir/dashboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/dashboard.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/dashboard.cpp" > CMakeFiles/quaketool.dir/dashboard.cpp.i

CMakeFiles/quaketool.dir/dashboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/dashboard.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/dashboard.cpp" -o CMakeFiles/quaketool.dir/dashboard.cpp.s

CMakeFiles/quaketool.dir/pops.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/pops.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/pops.cpp
CMakeFiles/quaketool.dir/pops.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/quaketool.dir/pops.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/pops.cpp.o -MF CMakeFiles/quaketool.dir/pops.cpp.o.d -o CMakeFiles/quaketool.dir/pops.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/pops.cpp"

CMakeFiles/quaketool.dir/pops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/pops.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/pops.cpp" > CMakeFiles/quaketool.dir/pops.cpp.i

CMakeFiles/quaketool.dir/pops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/pops.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/pops.cpp" -o CMakeFiles/quaketool.dir/pops.cpp.s

CMakeFiles/quaketool.dir/fluorinated.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/fluorinated.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/fluorinated.cpp
CMakeFiles/quaketool.dir/fluorinated.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/quaketool.dir/fluorinated.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/fluorinated.cpp.o -MF CMakeFiles/quaketool.dir/fluorinated.cpp.o.d -o CMakeFiles/quaketool.dir/fluorinated.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/fluorinated.cpp"

CMakeFiles/quaketool.dir/fluorinated.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/fluorinated.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/fluorinated.cpp" > CMakeFiles/quaketool.dir/fluorinated.cpp.i

CMakeFiles/quaketool.dir/fluorinated.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/fluorinated.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/fluorinated.cpp" -o CMakeFiles/quaketool.dir/fluorinated.cpp.s

CMakeFiles/quaketool.dir/pollutantOverview.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/pollutantOverview.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/pollutantOverview.cpp
CMakeFiles/quaketool.dir/pollutantOverview.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/quaketool.dir/pollutantOverview.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/pollutantOverview.cpp.o -MF CMakeFiles/quaketool.dir/pollutantOverview.cpp.o.d -o CMakeFiles/quaketool.dir/pollutantOverview.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/pollutantOverview.cpp"

CMakeFiles/quaketool.dir/pollutantOverview.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/pollutantOverview.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/pollutantOverview.cpp" > CMakeFiles/quaketool.dir/pollutantOverview.cpp.i

CMakeFiles/quaketool.dir/pollutantOverview.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/pollutantOverview.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/pollutantOverview.cpp" -o CMakeFiles/quaketool.dir/pollutantOverview.cpp.s

CMakeFiles/quaketool.dir/envlitter.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/envlitter.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/envlitter.cpp
CMakeFiles/quaketool.dir/envlitter.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/quaketool.dir/envlitter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/envlitter.cpp.o -MF CMakeFiles/quaketool.dir/envlitter.cpp.o.d -o CMakeFiles/quaketool.dir/envlitter.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/envlitter.cpp"

CMakeFiles/quaketool.dir/envlitter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/envlitter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/envlitter.cpp" > CMakeFiles/quaketool.dir/envlitter.cpp.i

CMakeFiles/quaketool.dir/envlitter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/envlitter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/envlitter.cpp" -o CMakeFiles/quaketool.dir/envlitter.cpp.s

CMakeFiles/quaketool.dir/compliance.cpp.o: CMakeFiles/quaketool.dir/flags.make
CMakeFiles/quaketool.dir/compliance.cpp.o: /Users/Sultan/Desktop/User\ Interfaces/Github\ Repository/comp2811-UI/solution/compliance.cpp
CMakeFiles/quaketool.dir/compliance.cpp.o: CMakeFiles/quaketool.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/quaketool.dir/compliance.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/quaketool.dir/compliance.cpp.o -MF CMakeFiles/quaketool.dir/compliance.cpp.o.d -o CMakeFiles/quaketool.dir/compliance.cpp.o -c "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/compliance.cpp"

CMakeFiles/quaketool.dir/compliance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/quaketool.dir/compliance.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/compliance.cpp" > CMakeFiles/quaketool.dir/compliance.cpp.i

CMakeFiles/quaketool.dir/compliance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/quaketool.dir/compliance.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution/compliance.cpp" -o CMakeFiles/quaketool.dir/compliance.cpp.s

# Object files for target quaketool
quaketool_OBJECTS = \
"CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/quaketool.dir/main.cpp.o" \
"CMakeFiles/quaketool.dir/quake.cpp.o" \
"CMakeFiles/quaketool.dir/dataset.cpp.o" \
"CMakeFiles/quaketool.dir/model.cpp.o" \
"CMakeFiles/quaketool.dir/window.cpp.o" \
"CMakeFiles/quaketool.dir/stats.cpp.o" \
"CMakeFiles/quaketool.dir/dashboard.cpp.o" \
"CMakeFiles/quaketool.dir/pops.cpp.o" \
"CMakeFiles/quaketool.dir/fluorinated.cpp.o" \
"CMakeFiles/quaketool.dir/pollutantOverview.cpp.o" \
"CMakeFiles/quaketool.dir/envlitter.cpp.o" \
"CMakeFiles/quaketool.dir/compliance.cpp.o"

# External object files for target quaketool
quaketool_EXTERNAL_OBJECTS =

quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/quaketool_autogen/mocs_compilation.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/main.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/quake.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/dataset.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/model.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/window.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/stats.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/dashboard.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/pops.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/fluorinated.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/pollutantOverview.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/envlitter.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/compliance.cpp.o
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/build.make
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtCharts.framework/Versions/A/QtCharts
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtQuickWidgets.framework/Versions/A/QtQuickWidgets
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtQuickControls2.framework/Versions/A/QtQuickControls2
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtLocation.framework/Versions/A/QtLocation
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtOpenGLWidgets.framework/Versions/A/QtOpenGLWidgets
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtPositioningQuick.framework/Versions/A/QtPositioningQuick
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtPositioning.framework/Versions/A/QtPositioning
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtQuickShapes.framework/Versions/A/QtQuickShapes
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtQuick.framework/Versions/A/QtQuick
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtOpenGL.framework/Versions/A/QtOpenGL
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtGui.framework/Versions/A/QtGui
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtQmlModels.framework/Versions/A/QtQmlModels
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtQml.framework/Versions/A/QtQml
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtNetwork.framework/Versions/A/QtNetwork
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/libQt6QmlBuiltins.a
quaketool.app/Contents/MacOS/quaketool: /Users/Sultan/Qt/6.7.3/macos/lib/QtCore.framework/Versions/A/QtCore
quaketool.app/Contents/MacOS/quaketool: CMakeFiles/quaketool.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable quaketool.app/Contents/MacOS/quaketool"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/quaketool.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/quaketool.dir/build: quaketool.app/Contents/MacOS/quaketool
.PHONY : CMakeFiles/quaketool.dir/build

CMakeFiles/quaketool.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/quaketool.dir/cmake_clean.cmake
.PHONY : CMakeFiles/quaketool.dir/clean

CMakeFiles/quaketool.dir/depend: quaketool_autogen/timestamp
	cd "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/solution" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build" "/Users/Sultan/Desktop/User Interfaces/Github Repository/comp2811-UI/build/CMakeFiles/quaketool.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/quaketool.dir/depend

