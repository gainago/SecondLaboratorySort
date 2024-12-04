cmake_minimum_required(VERSION 3.5)

project(ShowGraphics VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
"/home/goshagaina/Qwt/qwt-6.3.0/classincludes"
"/home/goshagaina/Qwt/qwt-6.3.0/src"
"${PROJECT_SOURCE_DIR}/../../../Declaration/TypesOfData")

file(GLOB           SOURCES "${PROJECT_SOURCE_DIR}/*.h"
                            "${PROJECT_SOURCE_DIR}/*.cpp"

)

#-------------------------------- create library Types Of Data 

#file(GLOB           SOURCES_Types_Of_Data 
#                            "${PROJECT_SOURCE_DIR}/../../../Definition/TypesOfData/*.cpp"
#
#)

#add_library(${PROJECT_NAME}_Types_Of_Data_lib
#                                                ${SOURCES_Types_Of_Data})
#------------------------------------------------
#add_executable(${PROJECT_NAME}
#
#                                   ${SOURCES})
#
add_library( ${PROJECT_NAME} SHARED
                                        ${SOURCES})
                                        
target_link_libraries(${PROJECT_NAME} Qt${QT_VERSION_MAJOR}::Widgets)

target_link_libraries(${PROJECT_NAME}
                                         "/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0")

#target_link_libraries(${PROJECT_NAME}
#${PROJECT_NAME}_Types_Of_Data_lib)