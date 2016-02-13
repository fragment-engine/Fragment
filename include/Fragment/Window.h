//
// Created by Frank Lyder Bredland on 13/02/16.
//

#ifndef FRAGMENT_WINDOW_H
#define FRAGMENT_WINDOW_H

class SDL_Window;
typedef void *SDL_GLContext;

namespace Fragment {

    class Window {
    private:
        int width, height;
        SDL_Window* mainwin;
        SDL_GLContext gContext;

    public:
        Window(int width, int height);
        ~Window();

        int init();
    };

}

#endif //FRAGMENT_WINDOW_H
