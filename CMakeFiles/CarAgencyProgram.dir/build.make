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
CMAKE_BINARY_DIR = /home/pooya/Desktop/CarAgentStore-master

# Include any dependencies generated for this target.
include CMakeFiles/CarAgencyProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/CarAgencyProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/CarAgencyProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CarAgencyProgram.dir/flags.make

CMakeFiles/CarAgencyProgram.dir/main.cpp.o: CMakeFiles/CarAgencyProgram.dir/flags.make
CMakeFiles/CarAgencyProgram.dir/main.cpp.o: main.cpp
CMakeFiles/CarAgencyProgram.dir/main.cpp.o: CMakeFiles/CarAgencyProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CarAgencyProgram.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CarAgencyProgram.dir/main.cpp.o -MF CMakeFiles/CarAgencyProgram.dir/main.cpp.o.d -o CMakeFiles/CarAgencyProgram.dir/main.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/main.cpp

CMakeFiles/CarAgencyProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CarAgencyProgram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/main.cpp > CMakeFiles/CarAgencyProgram.dir/main.cpp.i

CMakeFiles/CarAgencyProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CarAgencyProgram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/main.cpp -o CMakeFiles/CarAgencyProgram.dir/main.cpp.s

CMakeFiles/CarAgencyProgram.dir/Car.cpp.o: CMakeFiles/CarAgencyProgram.dir/flags.make
CMakeFiles/CarAgencyProgram.dir/Car.cpp.o: Car.cpp
CMakeFiles/CarAgencyProgram.dir/Car.cpp.o: CMakeFiles/CarAgencyProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CarAgencyProgram.dir/Car.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CarAgencyProgram.dir/Car.cpp.o -MF CMakeFiles/CarAgencyProgram.dir/Car.cpp.o.d -o CMakeFiles/CarAgencyProgram.dir/Car.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/Car.cpp

CMakeFiles/CarAgencyProgram.dir/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CarAgencyProgram.dir/Car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/Car.cpp > CMakeFiles/CarAgencyProgram.dir/Car.cpp.i

CMakeFiles/CarAgencyProgram.dir/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CarAgencyProgram.dir/Car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/Car.cpp -o CMakeFiles/CarAgencyProgram.dir/Car.cpp.s

CMakeFiles/CarAgencyProgram.dir/User.cpp.o: CMakeFiles/CarAgencyProgram.dir/flags.make
CMakeFiles/CarAgencyProgram.dir/User.cpp.o: User.cpp
CMakeFiles/CarAgencyProgram.dir/User.cpp.o: CMakeFiles/CarAgencyProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CarAgencyProgram.dir/User.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CarAgencyProgram.dir/User.cpp.o -MF CMakeFiles/CarAgencyProgram.dir/User.cpp.o.d -o CMakeFiles/CarAgencyProgram.dir/User.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/User.cpp

CMakeFiles/CarAgencyProgram.dir/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CarAgencyProgram.dir/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/User.cpp > CMakeFiles/CarAgencyProgram.dir/User.cpp.i

CMakeFiles/CarAgencyProgram.dir/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CarAgencyProgram.dir/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/User.cpp -o CMakeFiles/CarAgencyProgram.dir/User.cpp.s

CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o: CMakeFiles/CarAgencyProgram.dir/flags.make
CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o: CarAgency.cpp
CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o: CMakeFiles/CarAgencyProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pooya/Desktop/CarAgentStore-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o -MF CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o.d -o CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o -c /home/pooya/Desktop/CarAgentStore-master/CarAgency.cpp

CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pooya/Desktop/CarAgentStore-master/CarAgency.cpp > CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.i

CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pooya/Desktop/CarAgentStore-master/CarAgency.cpp -o CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.s

# Object files for target CarAgencyProgram
CarAgencyProgram_OBJECTS = \
"CMakeFiles/CarAgencyProgram.dir/main.cpp.o" \
"CMakeFiles/CarAgencyProgram.dir/Car.cpp.o" \
"CMakeFiles/CarAgencyProgram.dir/User.cpp.o" \
"CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o"

# External object files for target CarAgencyProgram
CarAgencyProgram_EXTERNAL_OBJECTS =

output/CarAgencyProgram: CMakeFiles/CarAgencyProgram.dir/main.cpp.o
output/CarAgencyProgram: CMakeFiles/CarAgencyProgram.dir/Car.cpp.o
output/CarAgencyProgram: CMakeFiles/CarAgencyProgram.dir/User.cpp.o
output/CarAgencyProgram: CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o
output/CarAgencyProgram: CMakeFiles/CarAgencyProgram.dir/build.make
output/CarAgencyProgram: CMakeFiles/CarAgencyProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pooya/Desktop/CarAgentStore-master/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable output/CarAgencyProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CarAgencyProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CarAgencyProgram.dir/build: output/CarAgencyProgram
.PHONY : CMakeFiles/CarAgencyProgram.dir/build

CMakeFiles/CarAgencyProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CarAgencyProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CarAgencyProgram.dir/clean

CMakeFiles/CarAgencyProgram.dir/depend:
	cd /home/pooya/Desktop/CarAgentStore-master && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master /home/pooya/Desktop/CarAgentStore-master/CMakeFiles/CarAgencyProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CarAgencyProgram.dir/depend

