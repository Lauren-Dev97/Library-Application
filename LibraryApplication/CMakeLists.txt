cmake_minimum_required(VERSION 3.16)

project(LibraryManagementSystem LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Adjust this path to your Qt6 installation
set(CMAKE_PREFIX_PATH "C:/Qt/6.9.1/msvc2019_64" ${CMAKE_PREFIX_PATH})

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

set(SOURCES
    main.cpp
    MainWindow.cpp
    LibraryItem.cpp
    Book.cpp
    Magazine.cpp
    LibraryUtils.cpp
)

set(HEADERS
    MainWindow.h
    LibraryItem.h
    Book.h
    Magazine.h
    Storage.h
    LibraryUtils.h
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
