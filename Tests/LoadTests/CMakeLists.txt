cmake_minimum_required(VERSION 3.5)

project(LoadTestsLibrary VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

file(GLOB	
		CPP_SOURCES	"${PROJECT_SOURCE_DIR}/Definition/*cpp")
include_directories(
			"/home/goshagaina/Qwt/qwt-6.3.0/classincludes"
			"/home/goshagaina/Qwt/qwt-6.3.0/src"
			"${PROJECT_SOURCE_DIR}/Declaration"
			"${PROJECT_SOURCE_DIR}/../../Declaration/Sequence"
			"${PROJECT_SOURCE_DIR}/../../Declaration/TypesOfData"
			"${PROJECT_SOURCE_DIR}/../../Declaration/Sorter"
			"${PROJECT_SOURCE_DIR}/../FunctionsForTests/Declaration"
			"${PROJECT_SOURCE_DIR}/Ploat/Declaration"
			)


																						 #libSharedLibrary_TypesOfData.so
#add_library(${PROJECT_NAME} SHARED  this will be shared library later
#		${CPP_SOURCES}		)


add_library(${PROJECT_NAME}
								${CPP_SOURCES})          

#target_link_libraries(${PROJECT_NAME}
#								"${PROJECT_SOURCE_DIR}/../../Definition/TypesOfData/build/libSharedLibrary_TypesOfData.so"
#)
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)
