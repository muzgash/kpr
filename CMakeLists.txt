CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)


INCLUDE_DIRECTORIES( include )

#ADD_DEFINITIONS( -std=c++0x )

add_library(customer SHARED
include/Customer.hpp
src/Customer.cpp
)

ADD_EXECUTABLE( kpr kpr.cpp )

target_link_libraries(kpr customer )
