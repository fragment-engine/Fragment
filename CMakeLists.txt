CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
PROJECT(Fragment)

# Set global variables
IF(UNIX)
   SET(CMAKE_CXX_FLAGS 
      "${CMAKE_CXX_FLAGS} -std=c++11"
   )
ENDIF(UNIX)

SET(CMAKE_MODULE_PATH 
   ${CMAKE_SOURCE_DIR}/cmake/
)

SET(Fragment_SOURCE_DIR 
   ${PROJECT_SOURCE_DIR}/src
)

SET(Fragment_INCLUDE_DIR 
   ${Fragment_SOURCE_DIR}/include
)

SET(Fragment_HEADER_FILES
   ${Fragment_INCLUDE_DIR}/Fragment/Vector2.h
)

# Find package dependencies 
FIND_PACKAGE("sdl2"        REQUIRED)
FIND_PACKAGE("glew"        REQUIRED)
FIND_PACKAGE("opengl"      REQUIRED)
FIND_PACKAGE("unittestpp"  REQUIRED)

# Add sub directories
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
ADD_SUBDIRECTORY(demo)