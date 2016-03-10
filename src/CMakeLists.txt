CMAKE_MINIMUM_REQUIRED(VERSION 3.3)

FIND_PACKAGE("sdl2"        REQUIRED)
FIND_PACKAGE("glew"        REQUIRED)
FIND_PACKAGE("opengl"      REQUIRED)
FIND_PACKAGE("sdl_image"   REQUIRED)
FIND_PACKAGE("v8"          REQUIRED)

ADD_LIBRARY(Fragment
	Fragment/Vector2.cpp
	Fragment/Window.cpp
	Fragment/Script/ScriptEngine.cpp
	Fragment/Graphics/Shader.cpp
	Fragment/Graphics/ShaderProgram.cpp
	${Fragment_INCLUDE_DIR}/Fragment/Vector2.h
	${Fragment_INCLUDE_DIR}/Fragment/Window.h
	${Fragment_INCLUDE_DIR}/Fragment/Script/ScriptEngine.h
	${Fragment_INCLUDE_DIR}/Fragment/Graphics/Shader.h
	${Fragment_INCLUDE_DIR}/Fragment/Graphics/ShaderProgram.h
)

TARGET_INCLUDE_DIRECTORIES(Fragment PUBLIC
   ${Fragment_INCLUDE_DIR}
)

TARGET_INCLUDE_DIRECTORIES(Fragment PRIVATE
	${SDL2_INCLUDE_DIR}
	${GLEW_INCLUDE_PATH}
	${OPNGL_INCLUDE_DIR}
	${SDLIMAGE_INCLUDE_DIR}
	${V8_INCLUDE_DIR}
)

TARGET_LINK_LIBRARIES(Fragment PUBLIC
	${SDL2_LIBRARY}
	${GLEW_LIBRARY}
	${OPENGL_LIBRARY}
	${SDLIMAGE_LIBRARY}
	${V8_LIBRARY}
)
