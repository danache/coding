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
CMAKE_SOURCE_DIR = /home/dan/coding/real_problem/ct

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dan/coding/real_problem/ct/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ct.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ct.dir/flags.make

CMakeFiles/ct.dir/main.cpp.o: CMakeFiles/ct.dir/flags.make
CMakeFiles/ct.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/coding/real_problem/ct/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ct.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ct.dir/main.cpp.o -c /home/dan/coding/real_problem/ct/main.cpp

CMakeFiles/ct.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ct.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/coding/real_problem/ct/main.cpp > CMakeFiles/ct.dir/main.cpp.i

CMakeFiles/ct.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ct.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/coding/real_problem/ct/main.cpp -o CMakeFiles/ct.dir/main.cpp.s

CMakeFiles/ct.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ct.dir/main.cpp.o.requires

CMakeFiles/ct.dir/main.cpp.o.provides: CMakeFiles/ct.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ct.dir/build.make CMakeFiles/ct.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ct.dir/main.cpp.o.provides

CMakeFiles/ct.dir/main.cpp.o.provides.build: CMakeFiles/ct.dir/main.cpp.o


# Object files for target ct
ct_OBJECTS = \
"CMakeFiles/ct.dir/main.cpp.o"

# External object files for target ct
ct_EXTERNAL_OBJECTS =

ct: CMakeFiles/ct.dir/main.cpp.o
ct: CMakeFiles/ct.dir/build.make
ct: CMakeFiles/ct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dan/coding/real_problem/ct/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ct.dir/build: ct

.PHONY : CMakeFiles/ct.dir/build

CMakeFiles/ct.dir/requires: CMakeFiles/ct.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ct.dir/requires

CMakeFiles/ct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ct.dir/clean

CMakeFiles/ct.dir/depend:
	cd /home/dan/coding/real_problem/ct/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dan/coding/real_problem/ct /home/dan/coding/real_problem/ct /home/dan/coding/real_problem/ct/cmake-build-debug /home/dan/coding/real_problem/ct/cmake-build-debug /home/dan/coding/real_problem/ct/cmake-build-debug/CMakeFiles/ct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ct.dir/depend

