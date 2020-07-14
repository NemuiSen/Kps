cmake_minimum_required(VERSION 3.5)

set(EXECUTABLE_OUTPUT_PATH ../bin)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_CXX_FLAGS "-O3 -Wall -DNDEBUG")
else()
	set(CMAKE_CXX_FLAGS "-O0 -DDEBUG")
endif()

project(Kps)

file(GLOB SRC "src/*.cpp")
include_directories(include)
add_executable(${PROJECT_NAME} ${SRC})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/Core/sen/programacion/cpp_libs/sfml/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
