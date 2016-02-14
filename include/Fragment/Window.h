//
// Created by Frank Lyder Bredland on 13/02/16.
//

#ifndef FRAGMENT_WINDOW_H
#define FRAGMENT_WINDOW_H

#include <memory>
#include <string>

class SDL_Window;

namespace Fragment {

    class Window {
    private:
        class Impl;
        std::unique_ptr<Impl> _impl;

    public:
        Window(int width, int height, std::string title);
        ~Window();
        int getWidth();
        int getHeight();
        SDL_Window* getWindow();

        int init();
    };

}

#endif //FRAGMENT_WINDOW_H
