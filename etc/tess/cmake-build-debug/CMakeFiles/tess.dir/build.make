# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\coding\etc\tess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\coding\etc\tess\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tess.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tess.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tess.dir/flags.make

CMakeFiles/tess.dir/main.cpp.obj: CMakeFiles/tess.dir/flags.make
CMakeFiles/tess.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\coding\etc\tess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tess.dir/main.cpp.obj"
	E:\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\tess.dir\main.cpp.obj -c F:\coding\etc\tess\main.cpp

CMakeFiles/tess.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tess.dir/main.cpp.i"
	E:\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\coding\etc\tess\main.cpp > CMakeFiles\tess.dir\main.cpp.i

CMakeFiles/tess.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tess.dir/main.cpp.s"
	E:\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\coding\etc\tess\main.cpp -o CMakeFiles\tess.dir\main.cpp.s

CMakeFiles/tess.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/tess.dir/main.cpp.obj.requires

CMakeFiles/tess.dir/main.cpp.obj.provides: CMakeFiles/tess.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\tess.dir\build.make CMakeFiles/tess.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/tess.dir/main.cpp.obj.provides

CMakeFiles/tess.dir/main.cpp.obj.provides.build: CMakeFiles/tess.dir/main.cpp.obj


# Object files for target tess
tess_OBJECTS = \
"CMakeFiles/tess.dir/main.cpp.obj"

# External object files for target tess
tess_EXTERNAL_OBJECTS =

tess.exe: CMakeFiles/tess.dir/main.cpp.obj
tess.exe: CMakeFiles/tess.dir/build.make
tess.exe: CMakeFiles/tess.dir/linklibs.rsp
tess.exe: CMakeFiles/tess.dir/objects1.rsp
tess.exe: CMakeFiles/tess.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\coding\etc\tess\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tess.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\tess.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tess.dir/build: tess.exe

.PHONY : CMakeFiles/tess.dir/build

CMakeFiles/tess.dir/requires: CMakeFiles/tess.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/tess.dir/requires

CMakeFiles/tess.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\tess.dir\cmake_clean.cmake
.PHONY : CMakeFiles/tess.dir/clean

CMakeFiles/tess.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\coding\etc\tess F:\coding\etc\tess F:\coding\etc\tess\cmake-build-debug F:\coding\etc\tess\cmake-build-debug F:\coding\etc\tess\cmake-build-debug\CMakeFiles\tess.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tess.dir/depend

