cmake_minimum_required(VERSION 3.5)

project(untitled5 VERSION 0.1 LANGUAGES CXX)

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
"${PROJECT_SOURCE_DIR}/Declaration"
"${PROJECT_SOURCE_DIR}/Definition")


add_executable(untitled5
Definition/main.cpp
Declaration/realtimeplot.h Definition/realtimeplot.cpp
)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET untitled5 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation


target_link_libraries(untitled5 Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.

#include(GNUInstallDirs)
#install(TARGETS untitled5
#    BUNDLE DESTINATION .
#    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
 #   RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#)

#if(QT_VERSION_MAJOR EQUAL 6)
#    qt_finalize_executable(untitled5)
#endif()

target_link_libraries(${PROJECT_NAME}
                                         "/home/goshagaina/Qwt/qwt-6.3.0/lib/libqwt.so.6.3.0")
