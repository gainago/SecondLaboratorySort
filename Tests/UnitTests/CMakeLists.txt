cmake_minimum_required(VERSION 3.5)

project(Shared_Library_Unit_Tests)

file(GLOB 
		CPP_SOURCES "${PROJECT_SOURCE_DIR}/Definition/*.cpp")
		
include_directories(
	"${PROJECT_SOURCE_DIR}/../../Declaration/Sequence"
	"${PROJECT_SOURCE_DIR}/../../Declaration/TypesOfData"
	"${PROJECT_SOURCE_DIR}/../../Declaration/Sorter"
	"${PROJECT_SOURCE_DIR}/../FunctionsForTests/Declaration"
	"${PROJECT_SOURCE_DIR}/Declaration"
)

add_library(${PROJECT_NAME} SHARED
	${CPP_SOURCES})

target_link_libraries(${PROJECT_NAME}
							"${PROJECT_SOURCE_DIR}/../FunctionsForTests/build/libSharedLibrary_FunctionsForTests.so")
							#SecondLaboratorySort/Tests/FunctionsForTests/build/libSharedLibrary_FunctionForTests.so
	
#target_include_directories(${PROJECT_NAME} PUBLIC $#{PROJECT_SOURCE_DIR})
