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
CMAKE_SOURCE_DIR = /home/dan/coding/程序员代码面试指南/max_sbumatrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dan/coding/程序员代码面试指南/max_sbumatrix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/max_sbumatrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/max_sbumatrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/max_sbumatrix.dir/flags.make

CMakeFiles/max_sbumatrix.dir/main.cpp.o: CMakeFiles/max_sbumatrix.dir/flags.make
CMakeFiles/max_sbumatrix.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/coding/程序员代码面试指南/max_sbumatrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/max_sbumatrix.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/max_sbumatrix.dir/main.cpp.o -c /home/dan/coding/程序员代码面试指南/max_sbumatrix/main.cpp

CMakeFiles/max_sbumatrix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/max_sbumatrix.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/coding/程序员代码面试指南/max_sbumatrix/main.cpp > CMakeFiles/max_sbumatrix.dir/main.cpp.i

CMakeFiles/max_sbumatrix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/max_sbumatrix.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/coding/程序员代码面试指南/max_sbumatrix/main.cpp -o CMakeFiles/max_sbumatrix.dir/main.cpp.s

CMakeFiles/max_sbumatrix.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/max_sbumatrix.dir/main.cpp.o.requires

CMakeFiles/max_sbumatrix.dir/main.cpp.o.provides: CMakeFiles/max_sbumatrix.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/max_sbumatrix.dir/build.make CMakeFiles/max_sbumatrix.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/max_sbumatrix.dir/main.cpp.o.provides

CMakeFiles/max_sbumatrix.dir/main.cpp.o.provides.build: CMakeFiles/max_sbumatrix.dir/main.cpp.o


# Object files for target max_sbumatrix
max_sbumatrix_OBJECTS = \
"CMakeFiles/max_sbumatrix.dir/main.cpp.o"

# External object files for target max_sbumatrix
max_sbumatrix_EXTERNAL_OBJECTS =

max_sbumatrix: CMakeFiles/max_sbumatrix.dir/main.cpp.o
max_sbumatrix: CMakeFiles/max_sbumatrix.dir/build.make
max_sbumatrix: CMakeFiles/max_sbumatrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dan/coding/程序员代码面试指南/max_sbumatrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable max_sbumatrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/max_sbumatrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/max_sbumatrix.dir/build: max_sbumatrix

.PHONY : CMakeFiles/max_sbumatrix.dir/build

CMakeFiles/max_sbumatrix.dir/requires: CMakeFiles/max_sbumatrix.dir/main.cpp.o.requires

.PHONY : CMakeFiles/max_sbumatrix.dir/requires

CMakeFiles/max_sbumatrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/max_sbumatrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/max_sbumatrix.dir/clean

CMakeFiles/max_sbumatrix.dir/depend:
	cd /home/dan/coding/程序员代码面试指南/max_sbumatrix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dan/coding/程序员代码面试指南/max_sbumatrix /home/dan/coding/程序员代码面试指南/max_sbumatrix /home/dan/coding/程序员代码面试指南/max_sbumatrix/cmake-build-debug /home/dan/coding/程序员代码面试指南/max_sbumatrix/cmake-build-debug /home/dan/coding/程序员代码面试指南/max_sbumatrix/cmake-build-debug/CMakeFiles/max_sbumatrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/max_sbumatrix.dir/depend

