# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/pooya/Desktop/CarAgentStore-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pooya/Desktop/CarAgentStore-master/build

# Include any dependencies generated for this target.
include CMakeFiles/server_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/server_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/server_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/server_test.dir/flags.make

CMakeFiles/server_test.dir/server.cpp.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/server.cpp.o: ../server.cpp
CMakeFiles/server_test.dir/server.cpp.o: CMakeFiles/server_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/server_test.dir/server.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_test.dir/server.cpp.o -MF CMakeFiles/server_test.dir/server.cpp.o.d -o CMakeFiles/server_test.dir/server.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/server.cpp

CMakeFiles/server_test.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_test.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/server.cpp > CMakeFiles/server_test.dir/server.cpp.i

CMakeFiles/server_test.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_test.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/server.cpp -o CMakeFiles/server_test.dir/server.cpp.s

CMakeFiles/server_test.dir/Car.cpp.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/Car.cpp.o: ../Car.cpp
CMakeFiles/server_test.dir/Car.cpp.o: CMakeFiles/server_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/server_test.dir/Car.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_test.dir/Car.cpp.o -MF CMakeFiles/server_test.dir/Car.cpp.o.d -o CMakeFiles/server_test.dir/Car.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/Car.cpp

CMakeFiles/server_test.dir/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_test.dir/Car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/Car.cpp > CMakeFiles/server_test.dir/Car.cpp.i

CMakeFiles/server_test.dir/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_test.dir/Car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/Car.cpp -o CMakeFiles/server_test.dir/Car.cpp.s

CMakeFiles/server_test.dir/User.cpp.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/User.cpp.o: ../User.cpp
CMakeFiles/server_test.dir/User.cpp.o: CMakeFiles/server_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/server_test.dir/User.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_test.dir/User.cpp.o -MF CMakeFiles/server_test.dir/User.cpp.o.d -o CMakeFiles/server_test.dir/User.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/User.cpp

CMakeFiles/server_test.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_test.dir/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/User.cpp > CMakeFiles/server_test.dir/User.cpp.i

CMakeFiles/server_test.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_test.dir/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/User.cpp -o CMakeFiles/server_test.dir/User.cpp.s

CMakeFiles/server_test.dir/CarAgency.cpp.o: CMakeFiles/server_test.dir/flags.make
CMakeFiles/server_test.dir/CarAgency.cpp.o: ../CarAgency.cpp
CMakeFiles/server_test.dir/CarAgency.cpp.o: CMakeFiles/server_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/server_test.dir/CarAgency.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/server_test.dir/CarAgency.cpp.o -MF CMakeFiles/server_test.dir/CarAgency.cpp.o.d -o CMakeFiles/server_test.dir/CarAgency.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/CarAgency.cpp

CMakeFiles/server_test.dir/CarAgency.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/server_test.dir/CarAgency.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/CarAgency.cpp > CMakeFiles/server_test.dir/CarAgency.cpp.i

CMakeFiles/server_test.dir/CarAgency.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/server_test.dir/CarAgency.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/CarAgency.cpp -o CMakeFiles/server_test.dir/CarAgency.cpp.s

# Object files for target server_test
server_test_OBJECTS = \
"CMakeFiles/server_test.dir/server.cpp.o" \
"CMakeFiles/server_test.dir/Car.cpp.o" \
"CMakeFiles/server_test.dir/User.cpp.o" \
"CMakeFiles/server_test.dir/CarAgency.cpp.o"

# External object files for target server_test
server_test_EXTERNAL_OBJECTS =

../output/server_test: CMakeFiles/server_test.dir/server.cpp.o
../output/server_test: CMakeFiles/server_test.dir/Car.cpp.o
../output/server_test: CMakeFiles/server_test.dir/User.cpp.o
../output/server_test: CMakeFiles/server_test.dir/CarAgency.cpp.o
../output/server_test: CMakeFiles/server_test.dir/build.make
../output/server_test: CMakeFiles/server_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../output/server_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/server_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/server_test.dir/build: ../output/server_test
.PHONY : CMakeFiles/server_test.dir/build

CMakeFiles/server_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/server_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/server_test.dir/clean

CMakeFiles/server_test.dir/depend:
	cd /home/pooya/Desktop/CarAgentStore-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master/build /home/pooya/Desktop/CarAgentStore-master/build /home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles/server_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/server_test.dir/depend

