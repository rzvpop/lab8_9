cmake_minimum_required(VERSION 3.8)
project(lab8_9)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ui.cpp ui.hpp controller.cpp controller.hpp repository.cpp repository.hpp event.cpp event.hpp test.cpp comparator.cpp comparator.hpp valid.cpp valid.hpp eventlist.cpp eventlist.hpp eventlistCSV.cpp eventlistCSV.hpp eventlistHTML.cpp eventlistHTML.hpp)
add_executable(lab8_9 ${SOURCE_FILES})

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )
qt5_use_modules( lab8_9 Core Widgets Gui )