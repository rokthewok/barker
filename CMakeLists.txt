cmake_minimum_required(VERSION 3.8)
project(barker)

set(CMAKE_CXX_STANDARD 11)

include_directories(./include)
set(SOURCE_FILES
        main.cpp
        include/barker_event.h
        src/barker_event.cpp include/barker_eventqueue.h src/barker_eventqueue.cpp)
add_executable(barker ${SOURCE_FILES})