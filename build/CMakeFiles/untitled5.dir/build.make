# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build

# Include any dependencies generated for this target.
include CMakeFiles/untitled5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/untitled5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled5.dir/flags.make

untitled5_autogen/timestamp: /usr/lib/qt5/bin/moc
untitled5_autogen/timestamp: /usr/lib/qt5/bin/uic
untitled5_autogen/timestamp: CMakeFiles/untitled5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target untitled5"
	/usr/bin/cmake -E cmake_autogen /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles/untitled5_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/untitled5_autogen/timestamp

CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o: untitled5_autogen/mocs_compilation.cpp
CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o: CMakeFiles/untitled5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o -MF CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/untitled5_autogen/mocs_compilation.cpp

CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/untitled5_autogen/mocs_compilation.cpp > CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.i

CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/untitled5_autogen/mocs_compilation.cpp -o CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.s

CMakeFiles/untitled5.dir/Definition/main.cpp.o: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/Definition/main.cpp.o: /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Definition/main.cpp
CMakeFiles/untitled5.dir/Definition/main.cpp.o: CMakeFiles/untitled5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled5.dir/Definition/main.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled5.dir/Definition/main.cpp.o -MF CMakeFiles/untitled5.dir/Definition/main.cpp.o.d -o CMakeFiles/untitled5.dir/Definition/main.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Definition/main.cpp

CMakeFiles/untitled5.dir/Definition/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled5.dir/Definition/main.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Definition/main.cpp > CMakeFiles/untitled5.dir/Definition/main.cpp.i

CMakeFiles/untitled5.dir/Definition/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled5.dir/Definition/main.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Definition/main.cpp -o CMakeFiles/untitled5.dir/Definition/main.cpp.s

CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o: /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp
CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o: CMakeFiles/untitled5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o -MF CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o.d -o CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp

CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp > CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.i

CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp -o CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.s

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o: /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsSorted.cpp
CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o: CMakeFiles/untitled5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o -MF CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o.d -o CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsSorted.cpp

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsSorted.cpp > CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.i

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsSorted.cpp -o CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.s

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o: /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp
CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o: CMakeFiles/untitled5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o -MF CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o.d -o CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp > CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.i

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp -o CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.s

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o: CMakeFiles/untitled5.dir/flags.make
CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o: /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestInt.cpp
CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o: CMakeFiles/untitled5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o -MF CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o.d -o CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o -c /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestInt.cpp

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.i"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestInt.cpp > CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.i

CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.s"
	/usr/bin/clang++-14 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/Tests/LoadTests/Definition/LoadTestInt.cpp -o CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.s

# Object files for target untitled5
untitled5_OBJECTS = \
"CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/untitled5.dir/Definition/main.cpp.o" \
"CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o" \
"CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o" \
"CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o" \
"CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o"

# External object files for target untitled5
untitled5_EXTERNAL_OBJECTS =

untitled5: CMakeFiles/untitled5.dir/untitled5_autogen/mocs_compilation.cpp.o
untitled5: CMakeFiles/untitled5.dir/Definition/main.cpp.o
untitled5: CMakeFiles/untitled5.dir/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp.o
untitled5: CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsSorted.cpp.o
untitled5: CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp.o
untitled5: CMakeFiles/untitled5.dir/Tests/LoadTests/Definition/LoadTestInt.cpp.o
untitled5: CMakeFiles/untitled5.dir/build.make
untitled5: libuntitled5_TypesOfData_lib.so
untitled5: libuntitled5_Function_For_Tests_lib.so
untitled5: libuntitled5_Unit_Tests.so
untitled5: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.13
untitled5: /home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0
untitled5: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.13
untitled5: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.13
untitled5: CMakeFiles/untitled5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable untitled5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled5.dir/build: untitled5
.PHONY : CMakeFiles/untitled5.dir/build

CMakeFiles/untitled5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled5.dir/clean

CMakeFiles/untitled5.dir/depend: untitled5_autogen/timestamp
	cd /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build /home/goshagaina/MEPHILabsMyselfThirdSemester/SecondLaboratorySort/build/CMakeFiles/untitled5.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/untitled5.dir/depend

