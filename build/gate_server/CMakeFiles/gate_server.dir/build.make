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
CMAKE_SOURCE_DIR = /home/gl/faq_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gl/faq_server/build

# Include any dependencies generated for this target.
include gate_server/CMakeFiles/gate_server.dir/depend.make

# Include the progress variables for this target.
include gate_server/CMakeFiles/gate_server.dir/progress.make

# Include the compile flags for this target's objects.
include gate_server/CMakeFiles/gate_server.dir/flags.make

gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o: ../gate_server/db_connection.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/db_connection.cpp.o -c /home/gl/faq_server/gate_server/db_connection.cpp

gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/db_connection.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/db_connection.cpp > CMakeFiles/gate_server.dir/db_connection.cpp.i

gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/db_connection.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/db_connection.cpp -o CMakeFiles/gate_server.dir/db_connection.cpp.s

gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o

gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o: ../gate_server/gate_application.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/gate_application.cpp.o -c /home/gl/faq_server/gate_server/gate_application.cpp

gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/gate_application.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/gate_application.cpp > CMakeFiles/gate_server.dir/gate_application.cpp.i

gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/gate_application.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/gate_application.cpp -o CMakeFiles/gate_server.dir/gate_application.cpp.s

gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o

gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o: ../gate_server/action_heart_message.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/action_heart_message.cpp.o -c /home/gl/faq_server/gate_server/action_heart_message.cpp

gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/action_heart_message.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/action_heart_message.cpp > CMakeFiles/gate_server.dir/action_heart_message.cpp.i

gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/action_heart_message.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/action_heart_message.cpp -o CMakeFiles/gate_server.dir/action_heart_message.cpp.s

gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o

gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o: ../gate_server/npc_object.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/npc_object.cpp.o -c /home/gl/faq_server/gate_server/npc_object.cpp

gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/npc_object.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/npc_object.cpp > CMakeFiles/gate_server.dir/npc_object.cpp.i

gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/npc_object.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/npc_object.cpp -o CMakeFiles/gate_server.dir/npc_object.cpp.s

gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o

gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o: ../gate_server/action_login_message.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/action_login_message.cpp.o -c /home/gl/faq_server/gate_server/action_login_message.cpp

gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/action_login_message.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/action_login_message.cpp > CMakeFiles/gate_server.dir/action_login_message.cpp.i

gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/action_login_message.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/action_login_message.cpp -o CMakeFiles/gate_server.dir/action_login_message.cpp.s

gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o

gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o: ../gate_server/logic_player.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/logic_player.cpp.o -c /home/gl/faq_server/gate_server/logic_player.cpp

gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/logic_player.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/logic_player.cpp > CMakeFiles/gate_server.dir/logic_player.cpp.i

gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/logic_player.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/logic_player.cpp -o CMakeFiles/gate_server.dir/logic_player.cpp.s

gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o

gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o: ../gate_server/action_move_message.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/action_move_message.cpp.o -c /home/gl/faq_server/gate_server/action_move_message.cpp

gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/action_move_message.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/action_move_message.cpp > CMakeFiles/gate_server.dir/action_move_message.cpp.i

gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/action_move_message.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/action_move_message.cpp -o CMakeFiles/gate_server.dir/action_move_message.cpp.s

gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o

gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o: ../gate_server/client_service.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/client_service.cpp.o -c /home/gl/faq_server/gate_server/client_service.cpp

gate_server/CMakeFiles/gate_server.dir/client_service.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/client_service.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/client_service.cpp > CMakeFiles/gate_server.dir/client_service.cpp.i

gate_server/CMakeFiles/gate_server.dir/client_service.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/client_service.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/client_service.cpp -o CMakeFiles/gate_server.dir/client_service.cpp.s

gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o

gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o: ../gate_server/gate_client.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/gate_client.cpp.o -c /home/gl/faq_server/gate_server/gate_client.cpp

gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/gate_client.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/gate_client.cpp > CMakeFiles/gate_server.dir/gate_client.cpp.i

gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/gate_client.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/gate_client.cpp -o CMakeFiles/gate_server.dir/gate_client.cpp.s

gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o

gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o: gate_server/CMakeFiles/gate_server.dir/flags.make
gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o: ../gate_server/map_manager.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gate_server.dir/map_manager.cpp.o -c /home/gl/faq_server/gate_server/map_manager.cpp

gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gate_server.dir/map_manager.cpp.i"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/gate_server/map_manager.cpp > CMakeFiles/gate_server.dir/map_manager.cpp.i

gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gate_server.dir/map_manager.cpp.s"
	cd /home/gl/faq_server/build/gate_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/gate_server/map_manager.cpp -o CMakeFiles/gate_server.dir/map_manager.cpp.s

gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.requires:
.PHONY : gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.requires

gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.provides: gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.requires
	$(MAKE) -f gate_server/CMakeFiles/gate_server.dir/build.make gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.provides.build
.PHONY : gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.provides

gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.provides.build: gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o

# Object files for target gate_server
gate_server_OBJECTS = \
"CMakeFiles/gate_server.dir/db_connection.cpp.o" \
"CMakeFiles/gate_server.dir/gate_application.cpp.o" \
"CMakeFiles/gate_server.dir/action_heart_message.cpp.o" \
"CMakeFiles/gate_server.dir/npc_object.cpp.o" \
"CMakeFiles/gate_server.dir/action_login_message.cpp.o" \
"CMakeFiles/gate_server.dir/logic_player.cpp.o" \
"CMakeFiles/gate_server.dir/action_move_message.cpp.o" \
"CMakeFiles/gate_server.dir/client_service.cpp.o" \
"CMakeFiles/gate_server.dir/gate_client.cpp.o" \
"CMakeFiles/gate_server.dir/map_manager.cpp.o"

# External object files for target gate_server
gate_server_EXTERNAL_OBJECTS =

../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/build.make
../game_exe/gate_server: ../game_lib/libcommon.a
../game_exe/gate_server: game_lib/libmessage_lib.a
../game_exe/gate_server: gate_server/CMakeFiles/gate_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../game_exe/gate_server"
	cd /home/gl/faq_server/build/gate_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gate_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
gate_server/CMakeFiles/gate_server.dir/build: ../game_exe/gate_server
.PHONY : gate_server/CMakeFiles/gate_server.dir/build

gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/db_connection.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/gate_application.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/action_heart_message.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/npc_object.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/action_login_message.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/logic_player.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/action_move_message.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/client_service.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/gate_client.cpp.o.requires
gate_server/CMakeFiles/gate_server.dir/requires: gate_server/CMakeFiles/gate_server.dir/map_manager.cpp.o.requires
.PHONY : gate_server/CMakeFiles/gate_server.dir/requires

gate_server/CMakeFiles/gate_server.dir/clean:
	cd /home/gl/faq_server/build/gate_server && $(CMAKE_COMMAND) -P CMakeFiles/gate_server.dir/cmake_clean.cmake
.PHONY : gate_server/CMakeFiles/gate_server.dir/clean

gate_server/CMakeFiles/gate_server.dir/depend:
	cd /home/gl/faq_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gl/faq_server /home/gl/faq_server/gate_server /home/gl/faq_server/build /home/gl/faq_server/build/gate_server /home/gl/faq_server/build/gate_server/CMakeFiles/gate_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : gate_server/CMakeFiles/gate_server.dir/depend

