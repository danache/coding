# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/dan/clion-2017.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/dan/clion-2017.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dan/coding/leetcode/leetcode486

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dan/coding/leetcode/leetcode486/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/leetcode486.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/leetcode486.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leetcode486.dir/flags.make

CMakeFiles/leetcode486.dir/main.cpp.o: CMakeFiles/leetcode486.dir/flags.make
CMakeFiles/leetcode486.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/coding/leetcode/leetcode486/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/leetcode486.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leetcode486.dir/main.cpp.o -c /home/dan/coding/leetcode/leetcode486/main.cpp

CMakeFiles/leetcode486.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leetcode486.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/coding/leetcode/leetcode486/main.cpp > CMakeFiles/leetcode486.dir/main.cpp.i

CMakeFiles/leetcode486.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leetcode486.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/coding/leetcode/leetcode486/main.cpp -o CMakeFiles/leetcode486.dir/main.cpp.s

CMakeFiles/leetcode486.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/leetcode486.dir/main.cpp.o.requires

CMakeFiles/leetcode486.dir/main.cpp.o.provides: CMakeFiles/leetcode486.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/leetcode486.dir/build.make CMakeFiles/leetcode486.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/leetcode486.dir/main.cpp.o.provides

CMakeFiles/leetcode486.dir/main.cpp.o.provides.build: CMakeFiles/leetcode486.dir/main.cpp.o


# Object files for target leetcode486
leetcode486_OBJECTS = \
"CMakeFiles/leetcode486.dir/main.cpp.o"

# External object files for target leetcode486
leetcode486_EXTERNAL_OBJECTS =

leetcode486: CMakeFiles/leetcode486.dir/main.cpp.o
leetcode486: CMakeFiles/leetcode486.dir/build.make
leetcode486: CMakeFiles/leetcode486.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dan/coding/leetcode/leetcode486/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leetcode486"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leetcode486.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leetcode486.dir/build: leetcode486

.PHONY : CMakeFiles/leetcode486.dir/build

CMakeFiles/leetcode486.dir/requires: CMakeFiles/leetcode486.dir/main.cpp.o.requires

.PHONY : CMakeFiles/leetcode486.dir/requires

CMakeFiles/leetcode486.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/leetcode486.dir/cmake_clean.cmake
.PHONY : CMakeFiles/leetcode486.dir/clean

CMakeFiles/leetcode486.dir/depend:
	cd /home/dan/coding/leetcode/leetcode486/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dan/coding/leetcode/leetcode486 /home/dan/coding/leetcode/leetcode486 /home/dan/coding/leetcode/leetcode486/cmake-build-debug /home/dan/coding/leetcode/leetcode486/cmake-build-debug /home/dan/coding/leetcode/leetcode486/cmake-build-debug/CMakeFiles/leetcode486.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/leetcode486.dir/depend

