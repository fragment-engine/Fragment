//
// Created by Frank Lyder Bredland on 10/03/16.
//

#ifndef FRAGMENT_SHADER_H
#define FRAGMENT_SHADER_H

#include <string>
#include <exception>
#include <GL/glew.h>

namespace Fragment {
    namespace Graphics {

        class ShaderProgram;

        struct FileNotFoundException : public std::exception
        {
            std::string filename;

            FileNotFoundException(const std::string &filename) : filename(filename) { }

            virtual const char* what() const _NOEXCEPT override {
                return "File not found";
            }
        };

        class Shader {
        public:
            std::shared_ptr<Shader> static fromSource(std::string source, GLenum shaderType);
            std::shared_ptr<Shader> static fromFile(std::string filepath, GLenum shaderType);
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
