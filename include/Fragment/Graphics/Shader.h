//
// Created by Frank Lyder Bredland on 10/03/16.
//

#ifndef FRAGMENT_SHADER_H
#define FRAGMENT_SHADER_H

#include <string>
#include <GL/glew.h>

class ShaderProgram;

namespace Fragment {
    namespace Graphics {

        class Shader {
        public:
            Shader static fromSource(std::string source, GLenum shaderType);
            Shader static fromFile(std::string filepath, GLenum shaderType);
            ~Shader();
            friend class ShaderProgram;

        private:
            Shader(std::string source, GLenum shaderType);
            GLuint getShaderID() const;
            GLuint m_shaderID;
        };

    }
}

#endif //FRAGMENT_SHADER_H
