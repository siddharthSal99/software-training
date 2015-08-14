cmake_minimum_required(VERSION 2.8.3)
project(software-training)

find_package(OpenCV)

find_package(Boost REQUIRED system)

link_libraries(${Boost_LIBRARIES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(1-Basic-CPP)

add_subdirectory(4-Serial-Comm)

if(OpenCV_FOUND)
message("Building OpenCV-dependant projects.")
link_libraries(${OpenCV_LIBS})

add_subdirectory(5-CV-Turret)
else()
message("OpenCV not found, not building OpenCV-dependant projects.")
endif()