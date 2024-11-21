cmake_minimum_required(VERSION 3.5)

project(SharedLibrary_FunctionsForTests)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O0")

file(GLOB	
		CPP_SOURCES	"${PROJECT_SOURCE_DIR}/Definition/*cpp")
include_directories(
			"${PROJECT_SOURCE_DIR}/Declaration"
			"${PROJECT_SOURCE_DIR}/../../Declaration/Sequence"
			"${PROJECT_SOURCE_DIR}/../../Declaration/TypesOfData"
			"${PROJECT_SOURCE_DIR}/../../Declaration/Sorter"
			)


																						 #libSharedLibrary_TypesOfData.so
add_library(${PROJECT_NAME} SHARED
		${CPP_SOURCES}		)

target_link_libraries(${PROJECT_NAME}
								"${PROJECT_SOURCE_DIR}/../../Definition/TypesOfData/build/libSharedLibrary_TypesOfData.so"
)
