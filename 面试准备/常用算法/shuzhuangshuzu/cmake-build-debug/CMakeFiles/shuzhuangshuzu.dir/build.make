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
CMAKE_SOURCE_DIR = /home/dan/coding/面试准备/常用算法/shuzhuangshuzu

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/shuzhuangshuzu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shuzhuangshuzu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shuzhuangshuzu.dir/flags.make

CMakeFiles/shuzhuangshuzu.dir/main.cpp.o: CMakeFiles/shuzhuangshuzu.dir/flags.make
CMakeFiles/shuzhuangshuzu.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dan/coding/面试准备/常用算法/shuzhuangshuzu/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shuzhuangshuzu.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shuzhuangshuzu.dir/main.cpp.o -c /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/main.cpp

CMakeFiles/shuzhuangshuzu.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shuzhuangshuzu.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/main.cpp > CMakeFiles/shuzhuangshuzu.dir/main.cpp.i

CMakeFiles/shuzhuangshuzu.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shuzhuangshuzu.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/main.cpp -o CMakeFiles/shuzhuangshuzu.dir/main.cpp.s

CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.requires

CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.provides: CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/shuzhuangshuzu.dir/build.make CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.provides

CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.provides.build: CMakeFiles/shuzhuangshuzu.dir/main.cpp.o


# Object files for target shuzhuangshuzu
shuzhuangshuzu_OBJECTS = \
"CMakeFiles/shuzhuangshuzu.dir/main.cpp.o"

# External object files for target shuzhuangshuzu
shuzhuangshuzu_EXTERNAL_OBJECTS =

shuzhuangshuzu: CMakeFiles/shuzhuangshuzu.dir/main.cpp.o
shuzhuangshuzu: CMakeFiles/shuzhuangshuzu.dir/build.make
shuzhuangshuzu: CMakeFiles/shuzhuangshuzu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dan/coding/面试准备/常用算法/shuzhuangshuzu/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable shuzhuangshuzu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shuzhuangshuzu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shuzhuangshuzu.dir/build: shuzhuangshuzu

.PHONY : CMakeFiles/shuzhuangshuzu.dir/build

CMakeFiles/shuzhuangshuzu.dir/requires: CMakeFiles/shuzhuangshuzu.dir/main.cpp.o.requires

.PHONY : CMakeFiles/shuzhuangshuzu.dir/requires

CMakeFiles/shuzhuangshuzu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shuzhuangshuzu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shuzhuangshuzu.dir/clean

CMakeFiles/shuzhuangshuzu.dir/depend:
	cd /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dan/coding/面试准备/常用算法/shuzhuangshuzu /home/dan/coding/面试准备/常用算法/shuzhuangshuzu /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/cmake-build-debug /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/cmake-build-debug /home/dan/coding/面试准备/常用算法/shuzhuangshuzu/cmake-build-debug/CMakeFiles/shuzhuangshuzu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shuzhuangshuzu.dir/depend

