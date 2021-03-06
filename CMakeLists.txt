cmake_minimum_required(VERSION 3.17)
project(loisFirst)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(SOURCE
        source/Validation.h
        source/Validation.cpp
        source/DNF.h
        source/DNF.cpp)

set(TESTS
        tests/testValidation.cpp
        tests/testKNF.cpp)

add_executable(${PROJECT_NAME} ${SOURCE} main.cpp)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})