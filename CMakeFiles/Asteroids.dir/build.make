# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anchor/Trab2_SO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anchor/Trab2_SO

# Include any dependencies generated for this target.
include CMakeFiles/Asteroids.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Asteroids.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Asteroids.dir/flags.make

CMakeFiles/Asteroids.dir/src/main.cpp.o: CMakeFiles/Asteroids.dir/flags.make
CMakeFiles/Asteroids.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anchor/Trab2_SO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Asteroids.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Asteroids.dir/src/main.cpp.o -c /home/anchor/Trab2_SO/src/main.cpp

CMakeFiles/Asteroids.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Asteroids.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anchor/Trab2_SO/src/main.cpp > CMakeFiles/Asteroids.dir/src/main.cpp.i

CMakeFiles/Asteroids.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Asteroids.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anchor/Trab2_SO/src/main.cpp -o CMakeFiles/Asteroids.dir/src/main.cpp.s

CMakeFiles/Asteroids.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/Asteroids.dir/src/main.cpp.o.requires

CMakeFiles/Asteroids.dir/src/main.cpp.o.provides: CMakeFiles/Asteroids.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Asteroids.dir/build.make CMakeFiles/Asteroids.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Asteroids.dir/src/main.cpp.o.provides

CMakeFiles/Asteroids.dir/src/main.cpp.o.provides.build: CMakeFiles/Asteroids.dir/src/main.cpp.o


# Object files for target Asteroids
Asteroids_OBJECTS = \
"CMakeFiles/Asteroids.dir/src/main.cpp.o"

# External object files for target Asteroids
Asteroids_EXTERNAL_OBJECTS =

Asteroids: CMakeFiles/Asteroids.dir/src/main.cpp.o
Asteroids: CMakeFiles/Asteroids.dir/build.make
Asteroids: CMakeFiles/Asteroids.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anchor/Trab2_SO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Asteroids"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Asteroids.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Asteroids.dir/build: Asteroids

.PHONY : CMakeFiles/Asteroids.dir/build

CMakeFiles/Asteroids.dir/requires: CMakeFiles/Asteroids.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/Asteroids.dir/requires

CMakeFiles/Asteroids.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Asteroids.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Asteroids.dir/clean

CMakeFiles/Asteroids.dir/depend:
	cd /home/anchor/Trab2_SO && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anchor/Trab2_SO /home/anchor/Trab2_SO /home/anchor/Trab2_SO /home/anchor/Trab2_SO /home/anchor/Trab2_SO/CMakeFiles/Asteroids.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Asteroids.dir/depend

