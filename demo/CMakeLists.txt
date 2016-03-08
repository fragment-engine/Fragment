CMAKE_MINIMUM_REQUIRED(VERSION 3.3)

SET(V8_X64_RELEASE_FOLDER ${PROJECT_SOURCE_DIR}/deps/v8/out/x64.release)
SET(V8_A_FILES
        ${V8_X64_RELEASE_FOLDER}/libv8_base.a
        ${V8_X64_RELEASE_FOLDER}/libv8_libbase.a
        ${V8_X64_RELEASE_FOLDER}/libv8_nosnapshot.a
        ${V8_X64_RELEASE_FOLDER}/libv8_libplatform.a
        ${V8_X64_RELEASE_FOLDER}/libicudata.a
        ${V8_X64_RELEASE_FOLDER}/libicuuc.a
        ${V8_X64_RELEASE_FOLDER}/libicui18n.a)

ADD_EXECUTABLE(FragmentDemo main.cpp)
TARGET_LINK_LIBRARIES(FragmentDemo ${V8_A_FILES})

FIND_PACKAGE("sdl2"        REQUIRED)
FIND_PACKAGE("opengl"      REQUIRED)
FIND_PACKAGE("glew"        REQUIRED)

#SET(V8_DIR ${PROJECT_SOURCE_DIR}/deps/v8/out/x64.release/)
#FIND_PACKAGE("v8"          REQUIRED)

TARGET_INCLUDE_DIRECTORIES(FragmentDemo PRIVATE
        ${SDL2_INCLUDE_DIR}
        ${OPENGL_LIBRARY}
        ${GLEW_INCLUDE_PATH}
        ${PROJECT_SOURCE_DIR}/deps/v8/
        ${Fragment_INCLUDE_DIR})

#TARGET_LINK_LIBRARIES(FragmentDemo PUBLIC Fragment ${V8_LIBRARY})