# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/gl/workspace/faq_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gl/workspace/faq_server

# Include any dependencies generated for this target.
include prototype/CMakeFiles/prototype.dir/depend.make

# Include the progress variables for this target.
include prototype/CMakeFiles/prototype.dir/progress.make

# Include the compile flags for this target's objects.
include prototype/CMakeFiles/prototype.dir/flags.make

prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o: prototype/CMakeFiles/prototype.dir/flags.make
prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o: prototype/item_data.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/faq_server/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/prototype.dir/item_data.pb.cc.o -c /home/gl/workspace/faq_server/prototype/item_data.pb.cc

prototype/CMakeFiles/prototype.dir/item_data.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prototype.dir/item_data.pb.cc.i"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/workspace/faq_server/prototype/item_data.pb.cc > CMakeFiles/prototype.dir/item_data.pb.cc.i

prototype/CMakeFiles/prototype.dir/item_data.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prototype.dir/item_data.pb.cc.s"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/workspace/faq_server/prototype/item_data.pb.cc -o CMakeFiles/prototype.dir/item_data.pb.cc.s

prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.requires:
.PHONY : prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.requires

prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.provides: prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.requires
	$(MAKE) -f prototype/CMakeFiles/prototype.dir/build.make prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.provides.build
.PHONY : prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.provides

prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.provides.build: prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o

prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o: prototype/CMakeFiles/prototype.dir/flags.make
prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o: prototype/item_prototype.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/faq_server/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/prototype.dir/item_prototype.cpp.o -c /home/gl/workspace/faq_server/prototype/item_prototype.cpp

prototype/CMakeFiles/prototype.dir/item_prototype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prototype.dir/item_prototype.cpp.i"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/workspace/faq_server/prototype/item_prototype.cpp > CMakeFiles/prototype.dir/item_prototype.cpp.i

prototype/CMakeFiles/prototype.dir/item_prototype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prototype.dir/item_prototype.cpp.s"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/workspace/faq_server/prototype/item_prototype.cpp -o CMakeFiles/prototype.dir/item_prototype.cpp.s

prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.requires:
.PHONY : prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.requires

prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.provides: prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.requires
	$(MAKE) -f prototype/CMakeFiles/prototype.dir/build.make prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.provides.build
.PHONY : prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.provides

prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.provides.build: prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o

prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o: prototype/CMakeFiles/prototype.dir/flags.make
prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o: prototype/npc_data_prototype.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/faq_server/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/prototype.dir/npc_data_prototype.cpp.o -c /home/gl/workspace/faq_server/prototype/npc_data_prototype.cpp

prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prototype.dir/npc_data_prototype.cpp.i"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/workspace/faq_server/prototype/npc_data_prototype.cpp > CMakeFiles/prototype.dir/npc_data_prototype.cpp.i

prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prototype.dir/npc_data_prototype.cpp.s"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/workspace/faq_server/prototype/npc_data_prototype.cpp -o CMakeFiles/prototype.dir/npc_data_prototype.cpp.s

prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.requires:
.PHONY : prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.requires

prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.provides: prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.requires
	$(MAKE) -f prototype/CMakeFiles/prototype.dir/build.make prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.provides.build
.PHONY : prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.provides

prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.provides.build: prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o

prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o: prototype/CMakeFiles/prototype.dir/flags.make
prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o: prototype/game_prototype.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/faq_server/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/prototype.dir/game_prototype.cpp.o -c /home/gl/workspace/faq_server/prototype/game_prototype.cpp

prototype/CMakeFiles/prototype.dir/game_prototype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prototype.dir/game_prototype.cpp.i"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/workspace/faq_server/prototype/game_prototype.cpp > CMakeFiles/prototype.dir/game_prototype.cpp.i

prototype/CMakeFiles/prototype.dir/game_prototype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prototype.dir/game_prototype.cpp.s"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/workspace/faq_server/prototype/game_prototype.cpp -o CMakeFiles/prototype.dir/game_prototype.cpp.s

prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.requires:
.PHONY : prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.requires

prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.provides: prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.requires
	$(MAKE) -f prototype/CMakeFiles/prototype.dir/build.make prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.provides.build
.PHONY : prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.provides

prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.provides.build: prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o

prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o: prototype/CMakeFiles/prototype.dir/flags.make
prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o: prototype/npc_data.pb.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/workspace/faq_server/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/prototype.dir/npc_data.pb.cc.o -c /home/gl/workspace/faq_server/prototype/npc_data.pb.cc

prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/prototype.dir/npc_data.pb.cc.i"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/workspace/faq_server/prototype/npc_data.pb.cc > CMakeFiles/prototype.dir/npc_data.pb.cc.i

prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/prototype.dir/npc_data.pb.cc.s"
	cd /home/gl/workspace/faq_server/prototype && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/workspace/faq_server/prototype/npc_data.pb.cc -o CMakeFiles/prototype.dir/npc_data.pb.cc.s

prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.requires:
.PHONY : prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.requires

prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.provides: prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.requires
	$(MAKE) -f prototype/CMakeFiles/prototype.dir/build.make prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.provides.build
.PHONY : prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.provides

prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.provides.build: prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o

# Object files for target prototype
prototype_OBJECTS = \
"CMakeFiles/prototype.dir/item_data.pb.cc.o" \
"CMakeFiles/prototype.dir/item_prototype.cpp.o" \
"CMakeFiles/prototype.dir/npc_data_prototype.cpp.o" \
"CMakeFiles/prototype.dir/game_prototype.cpp.o" \
"CMakeFiles/prototype.dir/npc_data.pb.cc.o"

# External object files for target prototype
prototype_EXTERNAL_OBJECTS =

/home/gl/workspace/game_lib/libprototype.a: prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o
/home/gl/workspace/game_lib/libprototype.a: prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o
/home/gl/workspace/game_lib/libprototype.a: prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o
/home/gl/workspace/game_lib/libprototype.a: prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o
/home/gl/workspace/game_lib/libprototype.a: prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o
/home/gl/workspace/game_lib/libprototype.a: prototype/CMakeFiles/prototype.dir/build.make
/home/gl/workspace/game_lib/libprototype.a: prototype/CMakeFiles/prototype.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library /home/gl/workspace/game_lib/libprototype.a"
	cd /home/gl/workspace/faq_server/prototype && $(CMAKE_COMMAND) -P CMakeFiles/prototype.dir/cmake_clean_target.cmake
	cd /home/gl/workspace/faq_server/prototype && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prototype.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
prototype/CMakeFiles/prototype.dir/build: /home/gl/workspace/game_lib/libprototype.a
.PHONY : prototype/CMakeFiles/prototype.dir/build

prototype/CMakeFiles/prototype.dir/requires: prototype/CMakeFiles/prototype.dir/item_data.pb.cc.o.requires
prototype/CMakeFiles/prototype.dir/requires: prototype/CMakeFiles/prototype.dir/item_prototype.cpp.o.requires
prototype/CMakeFiles/prototype.dir/requires: prototype/CMakeFiles/prototype.dir/npc_data_prototype.cpp.o.requires
prototype/CMakeFiles/prototype.dir/requires: prototype/CMakeFiles/prototype.dir/game_prototype.cpp.o.requires
prototype/CMakeFiles/prototype.dir/requires: prototype/CMakeFiles/prototype.dir/npc_data.pb.cc.o.requires
.PHONY : prototype/CMakeFiles/prototype.dir/requires

prototype/CMakeFiles/prototype.dir/clean:
	cd /home/gl/workspace/faq_server/prototype && $(CMAKE_COMMAND) -P CMakeFiles/prototype.dir/cmake_clean.cmake
.PHONY : prototype/CMakeFiles/prototype.dir/clean

prototype/CMakeFiles/prototype.dir/depend:
	cd /home/gl/workspace/faq_server && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gl/workspace/faq_server /home/gl/workspace/faq_server/prototype /home/gl/workspace/faq_server /home/gl/workspace/faq_server/prototype /home/gl/workspace/faq_server/prototype/CMakeFiles/prototype.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : prototype/CMakeFiles/prototype.dir/depend

