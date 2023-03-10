cmake_minimum_required(VERSION 3.0.0)
project(TowerDefense VERSION 0.1.0)

enable_language(CXX)

# use C++ standard version 17
set(CMAKE_CXX_STANDARD 17)
# produce non-optimized code with debug symbols
set(CMAKE_BUILD_TYPE Debug)

message(STATUS "BUILD directory is ${CMAKE_BINARY_DIR}")
message(STATUS "SRC directory is ${CMAKE_SOURCE_DIR}")

# Add all .c, - files under src/ directory
file(GLOB SOURCES_C "src/*.c")
# Add all .cpp, - files under src/ directory
file(GLOB SOURCES_CPP "src/*.cpp")
# Add all .hpp, - files under src/ directory
file(GLOB SOURCES_HPP "src/*.hpp")
# Add all .h, - files under src/ directory
file(GLOB SOURCES_H "src/*.h")
set(SOURCES ${SOURCES_C} ${SOURCES_CPP} ${SOURCES_H} ${SOURCES_HPP})
message(STATUS "SRC directory source code files: \n\t-- HEADERS: ${SOURCES_H}${SOURCES_HPP}\n\t-- C SOURCES: ${SOURCES_C}\n\t-- CPP SOURCE:${SOURCES_CPP}\n\t-- ALL:${SOURCES}")

# Find SFML shared libraries
find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED
  )

add_executable(TowerDefense)

target_sources(TowerDefense PUBLIC ${SOURCES})
target_include_directories(TowerDefense PUBLIC .)
target_include_directories(TowerDefense PUBLIC src)

# Link executable to required SFML libraries
target_link_libraries(TowerDefense sfml-graphics)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)