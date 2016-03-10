//
// Created by Frank Lyder Bredland on 10/03/16.
//

#include "Fragment/Graphics/Shader.h"

#include <gl/glew.h>
#include <vector>
#include <iostream>
#include <fstream>

using Fragment::Graphics::Shader;

Shader::Shader(std::string source, GLenum shaderType)
{
    m_shaderID = glCreateShader(shaderType);

    // Compile Vertex Shader
    char const * ptrSource = source.c_str();
    glShaderSource(m_shaderID, 1, &ptrSource, NULL);
    glCompileShader(m_shaderID);

    // Check Vertex Shader
    GLint Result = GL_FALSE;
    int InfoLogLength;
    glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &Result);
    glGetShaderiv(m_shaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    std::vector<char> shaderErrorMessage(InfoLogLength);
    glGetShaderInfoLog(m_shaderID, InfoLogLength, NULL, &shaderErrorMessage[0]);
    fprintf(stderr, "%s\n", &shaderErrorMessage[0]);
}

Shader Shader::fromSource(std::string source, GLenum shaderType)
{
    std::cout << "Compiling source" << std::endl;
    return Shader(source, shaderType);
}

Shader Shader::fromFile(std::string filepath, GLenum shaderType)
{
    std::ifstream fileStream(filepath, std::ios::in);
    if(fileStream.is_open())
    {
        std::string source(
                (std::istreambuf_iterator<char>(fileStream)),
                std::istreambuf_iterator<char>()
        );

        std::cout << "Compiling shader: " << filepath << std::endl;
        return Shader(source, shaderType);
    }
    else
    {
        throw "File could not be opened.";
    }
}

Shader::~Shader()
{
    glDeleteShader(m_shaderID);
}

GLuint Shader::getShaderID() const
{
    return m_shaderID;
}
