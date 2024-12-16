cmake_minimum_required(VERSION 3.5)

project(untitled5 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -ggdb")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)



include_directories(

"/home/goshagaina/Qwt/qwt-6.3.0/classincludes" #Замените на свой путь!
"/home/goshagaina/Qwt/qwt-6.3.0/src"          

"${PROJECT_SOURCE_DIR}/Declaration"
"${PROJECT_SOURCE_DIR}/Definition"
"${PROJECT_SOURCE_DIR}/Tests/LoadTests/Ploat/Declaration"
"${PROJECT_SOURCE_DIR}/Tests/LoadTests/ShowGraphics"
"${PROJECT_SOURCE_DIR}/Tests/LoadTests/Declaration"
"${PROJECT_SOURCE_DIR}/Declaration/Sorter" 
"${PROJECT_SOURCE_DIR}/Declaration/Sequence"
)
#--------Library    TypesOfData 
file(GLOB
                CPP_TYPES_OF_DATA "${PROJECT_SOURCE_DIR}/Definition/TypesOfData/*.cpp")

add_library(${PROJECT_NAME}_TypesOfData_lib   SHARED
                                    ${CPP_TYPES_OF_DATA})
include_directories(
    "${PROJECT_SOURCE_DIR}/Declaration/TypesOfData"
)
#---------------------

#--------Library    FunctionsForTests
file(GLOB
                CPP_Function_For_Tests "${PROJECT_SOURCE_DIR}/Tests/FunctionsForTests/Definition/*.cpp")

add_library(${PROJECT_NAME}_Function_For_Tests_lib  SHARED
                                   ${CPP_Function_For_Tests})
                                   
include_directories(
    "${PROJECT_SOURCE_DIR}/Tests/FunctionsForTests/Declaration"
)                                  
#---------------------

#--------Library    UnitTests
file(GLOB
                CPP_UNIT_TESTS_SOURCES "${PROJECT_SOURCE_DIR}/Tests/UnitTests/Definition/*.cpp")

add_library(${PROJECT_NAME}_Unit_Tests  SHARED
                                   ${CPP_UNIT_TESTS_SOURCES})
include_directories(
    "${PROJECT_SOURCE_DIR}/Tests/UnitTests/Declaration"
)
#---------------------

#--------Library    LoadTests ---------- can not make this becaude Qt need set(CMAKE_AUTOMOC ON) 
#                                        and i can not indicate this flag to library
#file(GLOB
#                CPP_LOAD_TESTS_SOURCES "${PROJECT_SOURCE_DIR}/Tests/LoadTests/Definition/*.cpp"
#                ${PROJECT_SOURCE_DIR}/Tests/LoadTests/Ploat/Declaration/realtimeplot.h
#                ${PROJECT_SOURCE_DIR}/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp
#                )
#
#add_library(${PROJECT_NAME}_Load_Tests  SHARED
#                                   ${CPP_LOAD_TESTS_SOURCES})
include_directories(
    "${PROJECT_SOURCE_DIR}/Tests/LoadTests/Declaration"
)
#---------------------



add_executable(untitled5
Definition/main.cpp
${PROJECT_SOURCE_DIR}/Tests/LoadTests/Ploat/Declaration/realtimeplot.h ${PROJECT_SOURCE_DIR}/Tests/LoadTests/Ploat/Definition/realtimeplot.cpp
${PROJECT_SOURCE_DIR}/Tests/LoadTests/Definition/StartLoadTestsPersonFromFile.cpp
${PROJECT_SOURCE_DIR}/Tests/LoadTests/Definition/StartLoadTestsIntFromFile.cpp
${PROJECT_SOURCE_DIR}/Tests/LoadTests/Definition/LoadTestsSorted.cpp
${PROJECT_SOURCE_DIR}/Tests/LoadTests/Definition/LoadTestsReversedSorted.cpp
${PROJECT_SOURCE_DIR}/Tests/LoadTests/ShowGraphics
)

target_link_libraries(${PROJECT_NAME}
                                        ${PROJECT_NAME}_TypesOfData_lib

)  

target_link_libraries(${PROJECT_NAME}
                                        ${PROJECT_NAME}_Function_For_Tests_lib

)  

target_link_libraries(${PROJECT_NAME}
                                        ${PROJECT_NAME}_Unit_Tests)

target_link_libraries(${PROJECT_NAME}
                                        "${PROJECT_SOURCE_DIR}/Tests/LoadTests/build/libLoadTestsLibrary.a")
                                        
target_link_libraries(${PROJECT_NAME}
                                        "${PROJECT_SOURCE_DIR}/Tests/LoadTests/ShowGraphics/build/libShowGraphics.so")  




target_link_libraries(untitled5 Qt${QT_VERSION_MAJOR}::Widgets)


target_link_libraries(${PROJECT_NAME}
                                         "/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0") #Замените на свой путь
                                         
