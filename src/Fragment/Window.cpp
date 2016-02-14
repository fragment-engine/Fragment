//
// Created by Frank Lyder Bredland on 13/02/16.
//

#include "Fragment/Window.h"

#include <gl/glew.h>
#include <SDL.h>
#include <iostream>

namespace Fragment {

    class Window::Impl {
    public:
        int width, height;
        SDL_Window* mainwin;
        SDL_GLContext gContext;
        std::string title;

        Impl(int width, int height, std::string title) : width(width), height(height), title(title) { }
    };

    Window::Window(int width, int height, std::string title) : _impl(new Impl(width, height, title)) {

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

        _impl->mainwin = SDL_CreateWindow(
                _impl->title.c_str(),
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                _impl->width,
                _impl->height,
                SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
        );

        _impl->gContext = SDL_GL_CreateContext(_impl->mainwin);

        glewExperimental = GL_TRUE;
        glewInit();

        // glewInit might throw and invalid enumerant error,
        // this is to be expected. Source: https://www.opengl.org/wiki/OpenGL_Loading_Library
        // Let's consume the error:
        glGetError();

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;

        return 0;
    }

    Window::~Window() {
        SDL_DestroyWindow(_impl->mainwin);
        SDL_Quit();
    }

    int Window::getWidth() {
        return _impl->width;
    }

    int Window::getHeight() {
        return _impl->height;
    }

    SDL_Window *Window::getWindow() {
        return _impl->mainwin;
    }
}