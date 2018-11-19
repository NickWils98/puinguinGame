cmake_minimum_required(VERSION 3.9)
project(game)

set(CMAKE_CXX_STANDARD 11)

add_executable(game main.cpp)

# Extend the CMake module path to find the FindSFML.cmake
# file in {project root}/cmake/Modules
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/Modules/")

# Look for SFML >= 2.0, with the specific subcomponents listed below
FIND_PACKAGE(SFML 2 COMPONENTS system window graphics)

# The source files to compile
SET(SRC main.cpp Animation.cpp Animation.h Player.cpp Player.h Collider.cpp Collider.h Platform.cpp Platform.h)

# Add include dirs for SFML
# (The SFML_INCLUDE_DIR variable is defined by FindSFML.cmake, if SFML was found)
INCLUDE_DIRECTORIES(${SFML_INCLUDE_DIR})

# The program we're compiling with the sources set above
ADD_EXECUTABLE(game_sfml ${SRC})

# Link target to SFML libs
# (The SFML_LIBRARIES variable is defined by FindSFML.cmake, if SFML was found)
TARGET_LINK_LIBRARIES(game_sfml ${SFML_LIBRARIES})

INSTALL(TARGETS game_sfml DESTINATION ${PROJECT_SOURCE_DIR}/bin)