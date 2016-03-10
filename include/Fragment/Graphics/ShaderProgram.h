//
// Created by Frank Lyder Bredland on 10/03/16.
//

#ifndef FRAGMENT_SHADERPROGRAM_H
#define FRAGMENT_SHADERPROGRAM_H

#include <string>
#include <GL/glew.h>

namespace Fragment {
    namespace Graphics {

        class Shader;

        class ShaderProgram {
        public:
            ShaderProgram();
            ~ShaderProgram();
            void attachShader(const Shader * s);
            void linkProgram();
            void useProgram();
            GLuint programID();
            GLuint getUniformLocation(std::string name);

        private:
            GLuint m_ProgramID;
        };

    }
}

#endif //FRAGMENT_SHADERPROGRAM_H
