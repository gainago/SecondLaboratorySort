cmake_minimum_required(VERSION 3.5)

project(GUI_Second_Laboratory VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE "../../")

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

include_directories(
"${SOURCE}/Declaration/Sequence"
"${SOURCE}/Declaration/Sorter"
"${SOURCE}/Declaration/TypesOfData"
"/home/goshagaina/Qwt/qwt-6.3.0/classincludes" #Rewrite these Path!
"/home/goshagaina/Qwt/qwt-6.3.0/src"
)

set(PROJECT_SOURCES(
        main.cpp
)
        add_executable(GUI_Second_Laboratory
            ${PROJECT_SOURCES}
            uiclass.h uiclass.cpp
            memberofmodel.h memberofmodel.cpp
            enumsorters.h enumsorters.cpp
            sortertablemodel.h sortertablemodel.cpp
            ${SOURCE}/Declaration/Sorter/ShellSorter.h
            ${SOURCE}/Declaration/Sorter/QuickSorter.h
            ${SOURCE}/Declaration/Sorter/PiramidSorter.h
            ${SOURCE}/Declaration/Sorter/MergeSorter.h
            ${SOURCE}/Declaration/Sorter/InsertionSorter.h
            ${SOURCE}/Declaration/Sorter/BubbleSorter.h
            ${SOURCE}/Declaration/Sorter/BitonicSorter.h
            ${SOURCE}/Declaration/Sorter/AbstractSorter.h
            ${SOURCE}/Declaration/Sequence/DynamicArray.h
            getqstringfromnewwidget.h getqstringfromnewwidget.cpp
            syntaxhighlighter.h syntaxhighlighter.cpp
            classtosortint.h classtosortint.cpp
            ${SOURCE}/Definition/TypesOfData/Comporators.cpp
            ${SOURCE}/Declaration/TypesOfData/Comporators.h
            uiclassprintgraphics.h uiclassprintgraphics.cpp
            ScrollBar.cpp
            ScrollBar.h
            ScrollZoomer.cpp
            ScrollZoomer.h

        )

target_link_libraries(${PROJECT_NAME} PRIVATE 
	Qt6::Widgets 
	Qt6::Core 
	Qt6::Gui 
	"/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0" # change it #2
)

file(GLOB
                CPP_TYPES_OF_DATA "${SOURCE}/Definition/TypesOfData/*.cpp")

add_library(${PROJECT_NAME}_TypesOfData_lib   SHARED
                                    ${CPP_TYPES_OF_DATA})

target_link_libraries(${PROJECT_NAME} PRIVATE
                                        ${PROJECT_NAME}_TypesOfData_lib

)

target_link_libraries(${PROJECT_NAME} PRIVATE
                                         "/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0") #Rewrite these Path
