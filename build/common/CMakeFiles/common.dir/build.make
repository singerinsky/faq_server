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
include common/CMakeFiles/common.dir/depend.make

# Include the progress variables for this target.
include common/CMakeFiles/common.dir/progress.make

# Include the compile flags for this target's objects.
include common/CMakeFiles/common.dir/flags.make

common/CMakeFiles/common.dir/tinyxmlerror.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/tinyxmlerror.cpp.o: ../common/tinyxmlerror.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/tinyxmlerror.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/tinyxmlerror.cpp.o -c /home/gl/faq_server/common/tinyxmlerror.cpp

common/CMakeFiles/common.dir/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/tinyxmlerror.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/tinyxmlerror.cpp > CMakeFiles/common.dir/tinyxmlerror.cpp.i

common/CMakeFiles/common.dir/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/tinyxmlerror.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/tinyxmlerror.cpp -o CMakeFiles/common.dir/tinyxmlerror.cpp.s

common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.requires

common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.provides: common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.provides

common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.provides.build: common/CMakeFiles/common.dir/tinyxmlerror.cpp.o

common/CMakeFiles/common.dir/actions_mananger.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/actions_mananger.cpp.o: ../common/actions_mananger.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/actions_mananger.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/actions_mananger.cpp.o -c /home/gl/faq_server/common/actions_mananger.cpp

common/CMakeFiles/common.dir/actions_mananger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/actions_mananger.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/actions_mananger.cpp > CMakeFiles/common.dir/actions_mananger.cpp.i

common/CMakeFiles/common.dir/actions_mananger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/actions_mananger.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/actions_mananger.cpp -o CMakeFiles/common.dir/actions_mananger.cpp.s

common/CMakeFiles/common.dir/actions_mananger.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/actions_mananger.cpp.o.requires

common/CMakeFiles/common.dir/actions_mananger.cpp.o.provides: common/CMakeFiles/common.dir/actions_mananger.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/actions_mananger.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/actions_mananger.cpp.o.provides

common/CMakeFiles/common.dir/actions_mananger.cpp.o.provides.build: common/CMakeFiles/common.dir/actions_mananger.cpp.o

common/CMakeFiles/common.dir/reactor_core.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/reactor_core.cpp.o: ../common/reactor_core.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/reactor_core.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/reactor_core.cpp.o -c /home/gl/faq_server/common/reactor_core.cpp

common/CMakeFiles/common.dir/reactor_core.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/reactor_core.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/reactor_core.cpp > CMakeFiles/common.dir/reactor_core.cpp.i

common/CMakeFiles/common.dir/reactor_core.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/reactor_core.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/reactor_core.cpp -o CMakeFiles/common.dir/reactor_core.cpp.s

common/CMakeFiles/common.dir/reactor_core.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/reactor_core.cpp.o.requires

common/CMakeFiles/common.dir/reactor_core.cpp.o.provides: common/CMakeFiles/common.dir/reactor_core.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/reactor_core.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/reactor_core.cpp.o.provides

common/CMakeFiles/common.dir/reactor_core.cpp.o.provides.build: common/CMakeFiles/common.dir/reactor_core.cpp.o

common/CMakeFiles/common.dir/tinyxmlparser.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/tinyxmlparser.cpp.o: ../common/tinyxmlparser.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/tinyxmlparser.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/tinyxmlparser.cpp.o -c /home/gl/faq_server/common/tinyxmlparser.cpp

common/CMakeFiles/common.dir/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/tinyxmlparser.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/tinyxmlparser.cpp > CMakeFiles/common.dir/tinyxmlparser.cpp.i

common/CMakeFiles/common.dir/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/tinyxmlparser.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/tinyxmlparser.cpp -o CMakeFiles/common.dir/tinyxmlparser.cpp.s

common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.requires

common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.provides: common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.provides

common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.provides.build: common/CMakeFiles/common.dir/tinyxmlparser.cpp.o

common/CMakeFiles/common.dir/job_factory.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/job_factory.cpp.o: ../common/job_factory.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/job_factory.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/job_factory.cpp.o -c /home/gl/faq_server/common/job_factory.cpp

common/CMakeFiles/common.dir/job_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/job_factory.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/job_factory.cpp > CMakeFiles/common.dir/job_factory.cpp.i

common/CMakeFiles/common.dir/job_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/job_factory.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/job_factory.cpp -o CMakeFiles/common.dir/job_factory.cpp.s

common/CMakeFiles/common.dir/job_factory.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/job_factory.cpp.o.requires

common/CMakeFiles/common.dir/job_factory.cpp.o.provides: common/CMakeFiles/common.dir/job_factory.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/job_factory.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/job_factory.cpp.o.provides

common/CMakeFiles/common.dir/job_factory.cpp.o.provides.build: common/CMakeFiles/common.dir/job_factory.cpp.o

common/CMakeFiles/common.dir/mysql_connection.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/mysql_connection.cpp.o: ../common/mysql_connection.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/mysql_connection.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/mysql_connection.cpp.o -c /home/gl/faq_server/common/mysql_connection.cpp

common/CMakeFiles/common.dir/mysql_connection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/mysql_connection.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/mysql_connection.cpp > CMakeFiles/common.dir/mysql_connection.cpp.i

common/CMakeFiles/common.dir/mysql_connection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/mysql_connection.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/mysql_connection.cpp -o CMakeFiles/common.dir/mysql_connection.cpp.s

common/CMakeFiles/common.dir/mysql_connection.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/mysql_connection.cpp.o.requires

common/CMakeFiles/common.dir/mysql_connection.cpp.o.provides: common/CMakeFiles/common.dir/mysql_connection.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/mysql_connection.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/mysql_connection.cpp.o.provides

common/CMakeFiles/common.dir/mysql_connection.cpp.o.provides.build: common/CMakeFiles/common.dir/mysql_connection.cpp.o

common/CMakeFiles/common.dir/thread.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/thread.cpp.o: ../common/thread.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/thread.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/thread.cpp.o -c /home/gl/faq_server/common/thread.cpp

common/CMakeFiles/common.dir/thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/thread.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/thread.cpp > CMakeFiles/common.dir/thread.cpp.i

common/CMakeFiles/common.dir/thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/thread.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/thread.cpp -o CMakeFiles/common.dir/thread.cpp.s

common/CMakeFiles/common.dir/thread.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/thread.cpp.o.requires

common/CMakeFiles/common.dir/thread.cpp.o.provides: common/CMakeFiles/common.dir/thread.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/thread.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/thread.cpp.o.provides

common/CMakeFiles/common.dir/thread.cpp.o.provides.build: common/CMakeFiles/common.dir/thread.cpp.o

common/CMakeFiles/common.dir/tinystr.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/tinystr.cpp.o: ../common/tinystr.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/tinystr.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/tinystr.cpp.o -c /home/gl/faq_server/common/tinystr.cpp

common/CMakeFiles/common.dir/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/tinystr.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/tinystr.cpp > CMakeFiles/common.dir/tinystr.cpp.i

common/CMakeFiles/common.dir/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/tinystr.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/tinystr.cpp -o CMakeFiles/common.dir/tinystr.cpp.s

common/CMakeFiles/common.dir/tinystr.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/tinystr.cpp.o.requires

common/CMakeFiles/common.dir/tinystr.cpp.o.provides: common/CMakeFiles/common.dir/tinystr.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/tinystr.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/tinystr.cpp.o.provides

common/CMakeFiles/common.dir/tinystr.cpp.o.provides.build: common/CMakeFiles/common.dir/tinystr.cpp.o

common/CMakeFiles/common.dir/tinyxml.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/tinyxml.cpp.o: ../common/tinyxml.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/tinyxml.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/tinyxml.cpp.o -c /home/gl/faq_server/common/tinyxml.cpp

common/CMakeFiles/common.dir/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/tinyxml.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/tinyxml.cpp > CMakeFiles/common.dir/tinyxml.cpp.i

common/CMakeFiles/common.dir/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/tinyxml.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/tinyxml.cpp -o CMakeFiles/common.dir/tinyxml.cpp.s

common/CMakeFiles/common.dir/tinyxml.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/tinyxml.cpp.o.requires

common/CMakeFiles/common.dir/tinyxml.cpp.o.provides: common/CMakeFiles/common.dir/tinyxml.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/tinyxml.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/tinyxml.cpp.o.provides

common/CMakeFiles/common.dir/tinyxml.cpp.o.provides.build: common/CMakeFiles/common.dir/tinyxml.cpp.o

common/CMakeFiles/common.dir/timer.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/timer.cpp.o: ../common/timer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/timer.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/timer.cpp.o -c /home/gl/faq_server/common/timer.cpp

common/CMakeFiles/common.dir/timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/timer.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/timer.cpp > CMakeFiles/common.dir/timer.cpp.i

common/CMakeFiles/common.dir/timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/timer.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/timer.cpp -o CMakeFiles/common.dir/timer.cpp.s

common/CMakeFiles/common.dir/timer.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/timer.cpp.o.requires

common/CMakeFiles/common.dir/timer.cpp.o.provides: common/CMakeFiles/common.dir/timer.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/timer.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/timer.cpp.o.provides

common/CMakeFiles/common.dir/timer.cpp.o.provides.build: common/CMakeFiles/common.dir/timer.cpp.o

common/CMakeFiles/common.dir/server_application.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/server_application.cpp.o: ../common/server_application.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/server_application.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/server_application.cpp.o -c /home/gl/faq_server/common/server_application.cpp

common/CMakeFiles/common.dir/server_application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/server_application.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/server_application.cpp > CMakeFiles/common.dir/server_application.cpp.i

common/CMakeFiles/common.dir/server_application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/server_application.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/server_application.cpp -o CMakeFiles/common.dir/server_application.cpp.s

common/CMakeFiles/common.dir/server_application.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/server_application.cpp.o.requires

common/CMakeFiles/common.dir/server_application.cpp.o.provides: common/CMakeFiles/common.dir/server_application.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/server_application.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/server_application.cpp.o.provides

common/CMakeFiles/common.dir/server_application.cpp.o.provides.build: common/CMakeFiles/common.dir/server_application.cpp.o

common/CMakeFiles/common.dir/net_util.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/net_util.cpp.o: ../common/net_util.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/net_util.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/net_util.cpp.o -c /home/gl/faq_server/common/net_util.cpp

common/CMakeFiles/common.dir/net_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/net_util.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/net_util.cpp > CMakeFiles/common.dir/net_util.cpp.i

common/CMakeFiles/common.dir/net_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/net_util.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/net_util.cpp -o CMakeFiles/common.dir/net_util.cpp.s

common/CMakeFiles/common.dir/net_util.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/net_util.cpp.o.requires

common/CMakeFiles/common.dir/net_util.cpp.o.provides: common/CMakeFiles/common.dir/net_util.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/net_util.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/net_util.cpp.o.provides

common/CMakeFiles/common.dir/net_util.cpp.o.provides.build: common/CMakeFiles/common.dir/net_util.cpp.o

common/CMakeFiles/common.dir/game_packet.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/game_packet.cpp.o: ../common/game_packet.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/game_packet.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/game_packet.cpp.o -c /home/gl/faq_server/common/game_packet.cpp

common/CMakeFiles/common.dir/game_packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/game_packet.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/game_packet.cpp > CMakeFiles/common.dir/game_packet.cpp.i

common/CMakeFiles/common.dir/game_packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/game_packet.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/game_packet.cpp -o CMakeFiles/common.dir/game_packet.cpp.s

common/CMakeFiles/common.dir/game_packet.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/game_packet.cpp.o.requires

common/CMakeFiles/common.dir/game_packet.cpp.o.provides: common/CMakeFiles/common.dir/game_packet.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/game_packet.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/game_packet.cpp.o.provides

common/CMakeFiles/common.dir/game_packet.cpp.o.provides.build: common/CMakeFiles/common.dir/game_packet.cpp.o

common/CMakeFiles/common.dir/socket.cpp.o: common/CMakeFiles/common.dir/flags.make
common/CMakeFiles/common.dir/socket.cpp.o: ../common/socket.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/gl/faq_server/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object common/CMakeFiles/common.dir/socket.cpp.o"
	cd /home/gl/faq_server/build/common && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/common.dir/socket.cpp.o -c /home/gl/faq_server/common/socket.cpp

common/CMakeFiles/common.dir/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/common.dir/socket.cpp.i"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/gl/faq_server/common/socket.cpp > CMakeFiles/common.dir/socket.cpp.i

common/CMakeFiles/common.dir/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/common.dir/socket.cpp.s"
	cd /home/gl/faq_server/build/common && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/gl/faq_server/common/socket.cpp -o CMakeFiles/common.dir/socket.cpp.s

common/CMakeFiles/common.dir/socket.cpp.o.requires:
.PHONY : common/CMakeFiles/common.dir/socket.cpp.o.requires

common/CMakeFiles/common.dir/socket.cpp.o.provides: common/CMakeFiles/common.dir/socket.cpp.o.requires
	$(MAKE) -f common/CMakeFiles/common.dir/build.make common/CMakeFiles/common.dir/socket.cpp.o.provides.build
.PHONY : common/CMakeFiles/common.dir/socket.cpp.o.provides

common/CMakeFiles/common.dir/socket.cpp.o.provides.build: common/CMakeFiles/common.dir/socket.cpp.o

# Object files for target common
common_OBJECTS = \
"CMakeFiles/common.dir/tinyxmlerror.cpp.o" \
"CMakeFiles/common.dir/actions_mananger.cpp.o" \
"CMakeFiles/common.dir/reactor_core.cpp.o" \
"CMakeFiles/common.dir/tinyxmlparser.cpp.o" \
"CMakeFiles/common.dir/job_factory.cpp.o" \
"CMakeFiles/common.dir/mysql_connection.cpp.o" \
"CMakeFiles/common.dir/thread.cpp.o" \
"CMakeFiles/common.dir/tinystr.cpp.o" \
"CMakeFiles/common.dir/tinyxml.cpp.o" \
"CMakeFiles/common.dir/timer.cpp.o" \
"CMakeFiles/common.dir/server_application.cpp.o" \
"CMakeFiles/common.dir/net_util.cpp.o" \
"CMakeFiles/common.dir/game_packet.cpp.o" \
"CMakeFiles/common.dir/socket.cpp.o"

# External object files for target common
common_EXTERNAL_OBJECTS =

../game_lib/libcommon.a: common/CMakeFiles/common.dir/tinyxmlerror.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/actions_mananger.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/reactor_core.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/tinyxmlparser.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/job_factory.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/mysql_connection.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/thread.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/tinystr.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/tinyxml.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/timer.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/server_application.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/net_util.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/game_packet.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/socket.cpp.o
../game_lib/libcommon.a: common/CMakeFiles/common.dir/build.make
../game_lib/libcommon.a: common/CMakeFiles/common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../game_lib/libcommon.a"
	cd /home/gl/faq_server/build/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean_target.cmake
	cd /home/gl/faq_server/build/common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
common/CMakeFiles/common.dir/build: ../game_lib/libcommon.a
.PHONY : common/CMakeFiles/common.dir/build

common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/tinyxmlerror.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/actions_mananger.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/reactor_core.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/tinyxmlparser.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/job_factory.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/mysql_connection.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/thread.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/tinystr.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/tinyxml.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/timer.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/server_application.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/net_util.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/game_packet.cpp.o.requires
common/CMakeFiles/common.dir/requires: common/CMakeFiles/common.dir/socket.cpp.o.requires
.PHONY : common/CMakeFiles/common.dir/requires

common/CMakeFiles/common.dir/clean:
	cd /home/gl/faq_server/build/common && $(CMAKE_COMMAND) -P CMakeFiles/common.dir/cmake_clean.cmake
.PHONY : common/CMakeFiles/common.dir/clean

common/CMakeFiles/common.dir/depend:
	cd /home/gl/faq_server/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gl/faq_server /home/gl/faq_server/common /home/gl/faq_server/build /home/gl/faq_server/build/common /home/gl/faq_server/build/common/CMakeFiles/common.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : common/CMakeFiles/common.dir/depend

