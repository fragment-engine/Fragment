cmake_minimum_required(VERSION 3.3)
project(Fragment)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    src/main.cpp)

add_executable(Fragment ${SOURCE_FILES})

# Dependencies
find_package("sdl2" REQUIRED)

set(include_directories PUBLIC
		${SDL2_INCLUDE_DIR}
)

set(link_libraries PUBLIC
		${SDL2_LIBRARY}
)

target_include_directories(Fragment ${include_directories})
target_link_libraries(Fragment ${link_libraries})
