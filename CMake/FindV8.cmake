# Locate V8
#
# Check out: https://raw.githubusercontent.com/gwaldron/osgearth/master/CMakeModules/FindV8.cmake
#

# This module defines
# V8_LIBRARY
# V8_INCLUDE_DIR, where to find the headers


SET(V8_X64_RELEASE_FOLDER ${PROJECT_SOURCE_DIR}/deps/v8/out/x64.release)
SET(V8_LIBRARY
        ${V8_X64_RELEASE_FOLDER}/libv8_base.a
        ${V8_X64_RELEASE_FOLDER}/libv8_libbase.a
        ${V8_X64_RELEASE_FOLDER}/libv8_nosnapshot.a
        ${V8_X64_RELEASE_FOLDER}/libv8_libplatform.a
        ${V8_X64_RELEASE_FOLDER}/libicudata.a
        ${V8_X64_RELEASE_FOLDER}/libicuuc.a
        ${V8_X64_RELEASE_FOLDER}/libicui18n.a)

SET(V8_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/deps/v8/)