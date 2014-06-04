cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 OLD)

#set the lib in this os 
#if your os is ubuntu set libname as ubuntu ;if os is centos set libname as centos ;if os is qq's suse set libname as qq
set(libname "ubuntu")
#set out put path

SET(EXECUTABLE_OUTPUT_PATH ../../game_exe)


PROJECT (gate_server)
#ADD_DEFINITIONS(-D_MY_DEBUG_)
MESSAGE("Building ${CMAKE_CXX_FLAGS_DEBUG}")


INCLUDE_DIRECTORIES(../../include)
AUX_SOURCE_DIRECTORY(../ DIR_SRCS)
LINK_DIRECTORIES(/usr/local/lib)
LINK_DIRECTORIES(../../lib)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(gate_server ${DIR_SRCS})
TARGET_LINK_LIBRARIES(gate_server libevent.a gflags glog)

