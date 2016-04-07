//
// Created by Frank Lyder Bredland on 10/03/16.
//

#ifndef FRAGMENT_VBO_H
#define FRAGMENT_VBO_H

#include <gl/glew.h>

namespace Fragment {
    namespace Graphics {

        class VBO {
        public:
            VBO();
            ~VBO();
            void bind();

        private:
            GLuint m_vertexbuffer;
        };

    }
}

#endif //FRAGMENT_VBO_H
