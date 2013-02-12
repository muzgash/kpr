CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)


INCLUDE_DIRECTORIES( include )

#ADD_DEFINITIONS( -std=c++0x )

add_library(agents SHARED
include/Agents.hpp
src/Agents.cpp
)

ADD_EXECUTABLE( kpr kpr.cpp )

target_link_libraries(kpr agents )
