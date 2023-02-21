# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/cmake-gui -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pooya/Desktop/CarAgentStore-master/CMakeFiles /home/pooya/Desktop/CarAgentStore-master//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/pooya/Desktop/CarAgentStore-master/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named CarAgencyProgram

# Build rule for target.
CarAgencyProgram: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 CarAgencyProgram
.PHONY : CarAgencyProgram

# fast build rule for target.
CarAgencyProgram/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/build
.PHONY : CarAgencyProgram/fast

Car.o: Car.cpp.o
.PHONY : Car.o

# target to build an object file
Car.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/Car.cpp.o
.PHONY : Car.cpp.o

Car.i: Car.cpp.i
.PHONY : Car.i

# target to preprocess a source file
Car.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/Car.cpp.i
.PHONY : Car.cpp.i

Car.s: Car.cpp.s
.PHONY : Car.s

# target to generate assembly for a file
Car.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/Car.cpp.s
.PHONY : Car.cpp.s

CarAgency.o: CarAgency.cpp.o
.PHONY : CarAgency.o

# target to build an object file
CarAgency.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.o
.PHONY : CarAgency.cpp.o

CarAgency.i: CarAgency.cpp.i
.PHONY : CarAgency.i

# target to preprocess a source file
CarAgency.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.i
.PHONY : CarAgency.cpp.i

CarAgency.s: CarAgency.cpp.s
.PHONY : CarAgency.s

# target to generate assembly for a file
CarAgency.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/CarAgency.cpp.s
.PHONY : CarAgency.cpp.s

User.o: User.cpp.o
.PHONY : User.o

# target to build an object file
User.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/User.cpp.o
.PHONY : User.cpp.o

User.i: User.cpp.i
.PHONY : User.i

# target to preprocess a source file
User.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/User.cpp.i
.PHONY : User.cpp.i

User.s: User.cpp.s
.PHONY : User.s

# target to generate assembly for a file
User.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/User.cpp.s
.PHONY : User.cpp.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/CarAgencyProgram.dir/build.make CMakeFiles/CarAgencyProgram.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... CarAgencyProgram"
	@echo "... Car.o"
	@echo "... Car.i"
	@echo "... Car.s"
	@echo "... CarAgency.o"
	@echo "... CarAgency.i"
	@echo "... CarAgency.s"
	@echo "... User.o"
	@echo "... User.i"
	@echo "... User.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

