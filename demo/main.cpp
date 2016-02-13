#include <Fragment/Vector2.h>
#include <Fragment/Window.h>

#include <SDL.h>

int main()
{
   Fragment::Window win(640, 480);

   win.init();

   SDL_Event event;
   while (true) {
      if (SDL_PollEvent(&event)) {
         if (event.type == SDL_QUIT)
            break;
      }
   }

   return 0;
}