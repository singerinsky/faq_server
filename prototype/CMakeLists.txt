ADD_DEFINITIONS(-D_MY_DEBUG_)

AUX_SOURCE_DIRECTORY(. SRC_LIST)

INCLUDE_DIRECTORIES(../include)
INCLUDE_DIRECTORIES(.. )
SET(LIBRARY_OUTPUT_PATH ../../game_lib)
ADD_LIBRARY(prototype ${SRC_LIST})
ADD_LIBRARY(prototypeso SHARED ${SRC_LIST})
