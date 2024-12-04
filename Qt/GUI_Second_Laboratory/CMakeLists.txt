cmake_minimum_required(VERSION 3.5)

project(GUI_Second_Laboratory VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE "../../")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

include_directories(
"${SOURCE}/Declaration/Sequence"
"${SOURCE}/Declaration/Sorter"
"${SOURCE}/Declaration/TypesOfData"
"/home/goshagaina/Qwt/qwt-6.3.0/classincludes" #Rewrite these Path!
"/home/goshagaina/Qwt/qwt-6.3.0/src"
)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(GUI_Second_Laboratory
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GUI_Second_Laboratory APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(GUI_Second_Laboratory SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
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
    endif()
endif()

target_link_libraries(GUI_Second_Laboratory PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GUI_Second_Laboratory)
endif()
set_target_properties(GUI_Second_Laboratory PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS GUI_Second_Laboratory
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(GUI_Second_Laboratory)
endif()
#----------Types OfData------
file(GLOB
                CPP_TYPES_OF_DATA "${SOURCE}/Definition/TypesOfData/*.cpp")

add_library(${PROJECT_NAME}_TypesOfData_lib   SHARED
                                    ${CPP_TYPES_OF_DATA})

target_link_libraries(${PROJECT_NAME} PRIVATE
                                        ${PROJECT_NAME}_TypesOfData_lib

)

target_link_libraries(${PROJECT_NAME} PRIVATE
                                         "/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0") #Rewrite these Path
