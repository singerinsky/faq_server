CMAKE_MINIMUM_REQUIRED(VERSION 2.8)    

PROJECT(faq_server)              

MESSAGE(STATUS "Project: Server")            

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -std=c++11 -O0 -Wall -g -D_GNU_SOURCE -fPIC")

SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -std=c++11 -O2 -Wall -g -D_GNU_SOURCE -fPIC")

INCLUDE_DIRECTORIES(./include )

#set build targe
#SET(CMAKE_BUILD_TYPE DEBUG)
SET(CMAKE_BUILD_TYPE RELEASE)

MESSAGE(${PROJECT_SOURCE_DIR})
ADD_SUBDIRECTORY(message)
ADD_SUBDIRECTORY(common)
ADD_SUBDIRECTORY(prototype)
ADD_SUBDIRECTORY(gate_server)                             
ADD_SUBDIRECTORY(db_server)                             
#ADD_SUBDIRECTORY(unit_test)                             
