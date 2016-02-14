//
// Created by Frank Lyder Bredland on 13/02/16.
//

#ifndef FRAGMENT_WINDOW_H
#define FRAGMENT_WINDOW_H

#include <memory>

namespace Fragment {

    class Window {
    private:
        class Impl;
        std::unique_ptr<Impl> _impl;

    public:
        Window(int width, int height);
        ~Window();

        int init();
    };

}

#endif //FRAGMENT_WINDOW_H
