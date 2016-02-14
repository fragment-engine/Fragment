#include <Fragment/Vector2.h>
#include <Fragment/Window.h>

#include <SDL.h>
#include <gl/glew.h>
#include <iostream>

void _assertGlErrors(GLenum err, std::string file, int line)
{
   if( err != GL_NO_ERROR ) {
      std::string error;

      switch(err) {
         case GL_INVALID_OPERATION:              error="INVALID_OPERATION";      break;
         case GL_INVALID_ENUM:                   error="INVALID_ENUM";           break;
         case GL_INVALID_VALUE:                  error="INVALID_VALUE";          break;
         case GL_OUT_OF_MEMORY:                  error="OUT_OF_MEMORY";          break;
         case GL_INVALID_FRAMEBUFFER_OPERATION:  error="INVALID_FRAMEBUFFER_OPERATION";  break;
      }

      std::cerr << line << "@" << file<< ": OpenGL error: " << error << " (" << err << ")" << std::endl;
   }
}

#define assertGlErrors() _assertGlErrors(glGetError(), __FILE__, __LINE__)


int main()
{
   Fragment::Window win(640, 480, "Fragment Demo");
   win.init();

   assertGlErrors();

   SDL_Event event;
   while (true) {

      //assertGlErrors();

      //Clear color buffer
      glClear( GL_COLOR_BUFFER_BIT );

      //Update screen
      SDL_GL_SwapWindow( win.getWindow() );

      if (SDL_PollEvent(&event)) {
         if (event.type == SDL_QUIT)
            break;
      }
   }

   return 0;
}