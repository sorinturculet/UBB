# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.28

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.4\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/04_laborator5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/04_laborator5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/04_laborator5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/04_laborator5.dir/flags.make

CMakeFiles/04_laborator5.dir/problema5.cpp.obj: CMakeFiles/04_laborator5.dir/flags.make
CMakeFiles/04_laborator5.dir/problema5.cpp.obj: C:/eu/ubb/2nd_Semester/grafuri/05_lab/04_laborator/problema5.cpp
CMakeFiles/04_laborator5.dir/problema5.cpp.obj: CMakeFiles/04_laborator5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/04_laborator5.dir/problema5.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/04_laborator5.dir/problema5.cpp.obj -MF CMakeFiles\04_laborator5.dir\problema5.cpp.obj.d -o CMakeFiles\04_laborator5.dir\problema5.cpp.obj -c C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\problema5.cpp

CMakeFiles/04_laborator5.dir/problema5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/04_laborator5.dir/problema5.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\problema5.cpp > CMakeFiles\04_laborator5.dir\problema5.cpp.i

CMakeFiles/04_laborator5.dir/problema5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/04_laborator5.dir/problema5.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\problema5.cpp -o CMakeFiles\04_laborator5.dir\problema5.cpp.s

# Object files for target 04_laborator5
04_laborator5_OBJECTS = \
"CMakeFiles/04_laborator5.dir/problema5.cpp.obj"

# External object files for target 04_laborator5
04_laborator5_EXTERNAL_OBJECTS =

04_laborator5.exe: CMakeFiles/04_laborator5.dir/problema5.cpp.obj
04_laborator5.exe: CMakeFiles/04_laborator5.dir/build.make
04_laborator5.exe: CMakeFiles/04_laborator5.dir/linkLibs.rsp
04_laborator5.exe: CMakeFiles/04_laborator5.dir/objects1.rsp
04_laborator5.exe: CMakeFiles/04_laborator5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 04_laborator5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\04_laborator5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/04_laborator5.dir/build: 04_laborator5.exe
.PHONY : CMakeFiles/04_laborator5.dir/build

CMakeFiles/04_laborator5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\04_laborator5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/04_laborator5.dir/clean

CMakeFiles/04_laborator5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\cmake-build-debug C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\cmake-build-debug C:\eu\ubb\2nd_Semester\grafuri\05_lab\04_laborator\cmake-build-debug\CMakeFiles\04_laborator5.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/04_laborator5.dir/depend

