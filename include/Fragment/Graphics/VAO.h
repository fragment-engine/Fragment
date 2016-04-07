//
// Created by Frank Lyder Bredland on 10/03/16.
//

#ifndef FRAGMENT_VAO_H
#define FRAGMENT_VAO_H

#include <gl/glew.h>

namespace Fragment {
    namespace Graphics {

        class VAO {
        public:
            VAO();
            ~VAO();
            void bind();

        private:
            GLuint m_VertexArrayID;
        };

    }
}

#endif //FRAGMENT_VAO_H
