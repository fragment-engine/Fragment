#include <Fragment\Vector2.h>

#include <SDL.h>
#include <gl/glew.h>
#include <iostream>

namespace Fragment
{

Vector2::Vector2()
   : x(0), y(0)
{ }

Vector2::Vector2(double a_x, double a_y)
   : x(a_x), y(a_y)
{ }

int Vector2::run()
{
   int width = 640,
      height = 480;

   SDL_Window* mainwin;
   SDL_GLContext gContext;

   int code = SDL_Init(SDL_INIT_VIDEO);

   // Initialize SDL
   if (code < 0)
   {
      return 1;
   }

   SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
   SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

   mainwin = SDL_CreateWindow(
      "Test game",
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
      );

   gContext = SDL_GL_CreateContext(mainwin);

   glewExperimental = GL_TRUE;
   int glew_init = glewInit();

   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LESS);

   SDL_Event event;
   while (true) {
      if (SDL_PollEvent(&event)) {
         if (event.type == SDL_QUIT)
            break;
      }
   }

   SDL_DestroyWindow(mainwin);
   SDL_Quit();

   return 0;
}

} // Fragment