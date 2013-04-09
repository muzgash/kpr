CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0)

INCLUDE_DIRECTORIES( include )

ADD_DEFINITIONS( -std=c++0x )

add_library(customer SHARED
include/Customer.hpp
src/Customer.cpp
)

add_library(functions SHARED
include/DecisionFunctions.hpp
src/DecisionFunctions.cpp
)

add_library(plots SHARED
include/Plots.hpp
src/Plots.cpp
)

ADD_EXECUTABLE( kpr kpr.cpp )

target_link_libraries(kpr customer functions plots mgl gsl gslcblas)
