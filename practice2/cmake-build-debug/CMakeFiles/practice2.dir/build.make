# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/practice2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practice2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practice2.dir/flags.make

CMakeFiles/practice2.dir/main.cpp.obj: CMakeFiles/practice2.dir/flags.make
CMakeFiles/practice2.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/practice2.dir/main.cpp.obj"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\practice2.dir\main.cpp.obj -c C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\main.cpp

CMakeFiles/practice2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/practice2.dir/main.cpp.i"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\main.cpp > CMakeFiles\practice2.dir\main.cpp.i

CMakeFiles/practice2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/practice2.dir/main.cpp.s"
	C:\PROGRA~2\Dev-Cpp\MinGW64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\main.cpp -o CMakeFiles\practice2.dir\main.cpp.s

# Object files for target practice2
practice2_OBJECTS = \
"CMakeFiles/practice2.dir/main.cpp.obj"

# External object files for target practice2
practice2_EXTERNAL_OBJECTS =

practice2.exe: CMakeFiles/practice2.dir/main.cpp.obj
practice2.exe: CMakeFiles/practice2.dir/build.make
practice2.exe: CMakeFiles/practice2.dir/linklibs.rsp
practice2.exe: CMakeFiles/practice2.dir/objects1.rsp
practice2.exe: CMakeFiles/practice2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable practice2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\practice2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practice2.dir/build: practice2.exe

.PHONY : CMakeFiles/practice2.dir/build

CMakeFiles/practice2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\practice2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/practice2.dir/clean

CMakeFiles/practice2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2 C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2 C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\cmake-build-debug C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\cmake-build-debug C:\Users\iceQH\Documents\GitHub\DSAA_reports\practice2\cmake-build-debug\CMakeFiles\practice2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practice2.dir/depend

