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
include CMakeFiles/udp_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/udp_client.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/udp_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/udp_client.dir/flags.make

CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o: ../src/client/udp_client.cpp
CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o: CMakeFiles/udp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o -MF CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o.d -o CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/src/client/udp_client.cpp

CMakeFiles/udp_client.dir/src/client/udp_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_client.dir/src/client/udp_client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/src/client/udp_client.cpp > CMakeFiles/udp_client.dir/src/client/udp_client.cpp.i

CMakeFiles/udp_client.dir/src/client/udp_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_client.dir/src/client/udp_client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/src/client/udp_client.cpp -o CMakeFiles/udp_client.dir/src/client/udp_client.cpp.s

CMakeFiles/udp_client.dir/src/Car.cpp.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/src/Car.cpp.o: ../src/Car.cpp
CMakeFiles/udp_client.dir/src/Car.cpp.o: CMakeFiles/udp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/udp_client.dir/src/Car.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/udp_client.dir/src/Car.cpp.o -MF CMakeFiles/udp_client.dir/src/Car.cpp.o.d -o CMakeFiles/udp_client.dir/src/Car.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/src/Car.cpp

CMakeFiles/udp_client.dir/src/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_client.dir/src/Car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/src/Car.cpp > CMakeFiles/udp_client.dir/src/Car.cpp.i

CMakeFiles/udp_client.dir/src/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_client.dir/src/Car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/src/Car.cpp -o CMakeFiles/udp_client.dir/src/Car.cpp.s

CMakeFiles/udp_client.dir/src/User.cpp.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/src/User.cpp.o: ../src/User.cpp
CMakeFiles/udp_client.dir/src/User.cpp.o: CMakeFiles/udp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/udp_client.dir/src/User.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/udp_client.dir/src/User.cpp.o -MF CMakeFiles/udp_client.dir/src/User.cpp.o.d -o CMakeFiles/udp_client.dir/src/User.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/src/User.cpp

CMakeFiles/udp_client.dir/src/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_client.dir/src/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/src/User.cpp > CMakeFiles/udp_client.dir/src/User.cpp.i

CMakeFiles/udp_client.dir/src/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_client.dir/src/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/src/User.cpp -o CMakeFiles/udp_client.dir/src/User.cpp.s

CMakeFiles/udp_client.dir/src/CarAgency.cpp.o: CMakeFiles/udp_client.dir/flags.make
CMakeFiles/udp_client.dir/src/CarAgency.cpp.o: ../src/CarAgency.cpp
CMakeFiles/udp_client.dir/src/CarAgency.cpp.o: CMakeFiles/udp_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/udp_client.dir/src/CarAgency.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/udp_client.dir/src/CarAgency.cpp.o -MF CMakeFiles/udp_client.dir/src/CarAgency.cpp.o.d -o CMakeFiles/udp_client.dir/src/CarAgency.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/src/CarAgency.cpp

CMakeFiles/udp_client.dir/src/CarAgency.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/udp_client.dir/src/CarAgency.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/src/CarAgency.cpp > CMakeFiles/udp_client.dir/src/CarAgency.cpp.i

CMakeFiles/udp_client.dir/src/CarAgency.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/udp_client.dir/src/CarAgency.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/src/CarAgency.cpp -o CMakeFiles/udp_client.dir/src/CarAgency.cpp.s

# Object files for target udp_client
udp_client_OBJECTS = \
"CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o" \
"CMakeFiles/udp_client.dir/src/Car.cpp.o" \
"CMakeFiles/udp_client.dir/src/User.cpp.o" \
"CMakeFiles/udp_client.dir/src/CarAgency.cpp.o"

# External object files for target udp_client
udp_client_EXTERNAL_OBJECTS =

../output/udp_client: CMakeFiles/udp_client.dir/src/client/udp_client.cpp.o
../output/udp_client: CMakeFiles/udp_client.dir/src/Car.cpp.o
../output/udp_client: CMakeFiles/udp_client.dir/src/User.cpp.o
../output/udp_client: CMakeFiles/udp_client.dir/src/CarAgency.cpp.o
../output/udp_client: CMakeFiles/udp_client.dir/build.make
../output/udp_client: CMakeFiles/udp_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../output/udp_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/udp_client.dir/build: ../output/udp_client
.PHONY : CMakeFiles/udp_client.dir/build

CMakeFiles/udp_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/udp_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/udp_client.dir/clean

CMakeFiles/udp_client.dir/depend:
	cd /home/pooya/Desktop/CarAgentStore-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master/build /home/pooya/Desktop/CarAgentStore-master/build /home/pooya/Desktop/CarAgentStore-master/build/CMakeFiles/udp_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/udp_client.dir/depend

