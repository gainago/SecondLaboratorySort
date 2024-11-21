cmake_minimum_required(VERSION 3.5)

project(SharedLibrary_TypesOfData)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O0")

file(GLOB	
		CPP_SOURCES	"${PROJECT_SOURCE_DIR}/*.cpp")
include_directories(
			"${PROJECT_SOURCE_DIR}/../../Declaration/TypesOfData"
			
			)
add_library(${PROJECT_NAME} SHARED
		${CPP_SOURCES}	)