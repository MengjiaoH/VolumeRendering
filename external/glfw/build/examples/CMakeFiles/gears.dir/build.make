# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build"

# Include any dependencies generated for this target.
include examples/CMakeFiles/gears.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/gears.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/gears.dir/flags.make

examples/gears.app/Contents/Resources/glfw.icns: ../examples/glfw.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content examples/gears.app/Contents/Resources/glfw.icns"
	$(CMAKE_COMMAND) -E copy "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/examples/glfw.icns" examples/gears.app/Contents/Resources/glfw.icns

examples/CMakeFiles/gears.dir/gears.c.o: examples/CMakeFiles/gears.dir/flags.make
examples/CMakeFiles/gears.dir/gears.c.o: ../examples/gears.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/gears.dir/gears.c.o"
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gears.dir/gears.c.o   -c "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/examples/gears.c"

examples/CMakeFiles/gears.dir/gears.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/gears.c.i"
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/examples/gears.c" > CMakeFiles/gears.dir/gears.c.i

examples/CMakeFiles/gears.dir/gears.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/gears.c.s"
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/examples/gears.c" -o CMakeFiles/gears.dir/gears.c.s

examples/CMakeFiles/gears.dir/gears.c.o.requires:

.PHONY : examples/CMakeFiles/gears.dir/gears.c.o.requires

examples/CMakeFiles/gears.dir/gears.c.o.provides: examples/CMakeFiles/gears.dir/gears.c.o.requires
	$(MAKE) -f examples/CMakeFiles/gears.dir/build.make examples/CMakeFiles/gears.dir/gears.c.o.provides.build
.PHONY : examples/CMakeFiles/gears.dir/gears.c.o.provides

examples/CMakeFiles/gears.dir/gears.c.o.provides.build: examples/CMakeFiles/gears.dir/gears.c.o


examples/CMakeFiles/gears.dir/__/deps/glad.c.o: examples/CMakeFiles/gears.dir/flags.make
examples/CMakeFiles/gears.dir/__/deps/glad.c.o: ../deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object examples/CMakeFiles/gears.dir/__/deps/glad.c.o"
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gears.dir/__/deps/glad.c.o   -c "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/deps/glad.c"

examples/CMakeFiles/gears.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/__/deps/glad.c.i"
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/deps/glad.c" > CMakeFiles/gears.dir/__/deps/glad.c.i

examples/CMakeFiles/gears.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/__/deps/glad.c.s"
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/deps/glad.c" -o CMakeFiles/gears.dir/__/deps/glad.c.s

examples/CMakeFiles/gears.dir/__/deps/glad.c.o.requires:

.PHONY : examples/CMakeFiles/gears.dir/__/deps/glad.c.o.requires

examples/CMakeFiles/gears.dir/__/deps/glad.c.o.provides: examples/CMakeFiles/gears.dir/__/deps/glad.c.o.requires
	$(MAKE) -f examples/CMakeFiles/gears.dir/build.make examples/CMakeFiles/gears.dir/__/deps/glad.c.o.provides.build
.PHONY : examples/CMakeFiles/gears.dir/__/deps/glad.c.o.provides

examples/CMakeFiles/gears.dir/__/deps/glad.c.o.provides.build: examples/CMakeFiles/gears.dir/__/deps/glad.c.o


# Object files for target gears
gears_OBJECTS = \
"CMakeFiles/gears.dir/gears.c.o" \
"CMakeFiles/gears.dir/__/deps/glad.c.o"

# External object files for target gears
gears_EXTERNAL_OBJECTS =

examples/gears.app/Contents/MacOS/gears: examples/CMakeFiles/gears.dir/gears.c.o
examples/gears.app/Contents/MacOS/gears: examples/CMakeFiles/gears.dir/__/deps/glad.c.o
examples/gears.app/Contents/MacOS/gears: examples/CMakeFiles/gears.dir/build.make
examples/gears.app/Contents/MacOS/gears: src/libglfw3.a
examples/gears.app/Contents/MacOS/gears: examples/CMakeFiles/gears.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable gears.app/Contents/MacOS/gears"
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gears.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/gears.dir/build: examples/gears.app/Contents/MacOS/gears
examples/CMakeFiles/gears.dir/build: examples/gears.app/Contents/Resources/glfw.icns

.PHONY : examples/CMakeFiles/gears.dir/build

examples/CMakeFiles/gears.dir/requires: examples/CMakeFiles/gears.dir/gears.c.o.requires
examples/CMakeFiles/gears.dir/requires: examples/CMakeFiles/gears.dir/__/deps/glad.c.o.requires

.PHONY : examples/CMakeFiles/gears.dir/requires

examples/CMakeFiles/gears.dir/clean:
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" && $(CMAKE_COMMAND) -P CMakeFiles/gears.dir/cmake_clean.cmake
.PHONY : examples/CMakeFiles/gears.dir/clean

examples/CMakeFiles/gears.dir/depend:
	cd "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1" "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/examples" "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build" "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples" "/Users/hanmengjiao/Desktop/Volume Rendering/tb_volume_rendering/tb_volume_rendering/glfw-3.2.1/build/examples/CMakeFiles/gears.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : examples/CMakeFiles/gears.dir/depend

