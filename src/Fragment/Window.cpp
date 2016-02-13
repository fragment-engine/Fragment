//
// Created by Frank Lyder Bredland on 13/02/16.
//

#include "Fragment/Window.h"

#include <gl/glew.h>
#include <SDL.h>

namespace Fragment {

    Window::Window(int width, int height) : width(width), height(height) {

    }

    int Window::init() {
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


        return 0;
    }

    Window::~Window() {
        SDL_DestroyWindow(mainwin);
        SDL_Quit();
    }
}