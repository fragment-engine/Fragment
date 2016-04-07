//
// Created by Frank Lyder Bredland on 10/03/16.
//

#include "Fragment/Graphics/ShaderProgram.h"
#include "Fragment/Graphics/Shader.h"

#include <gl/glew.h>

using Fragment::Graphics::Shader;

Fragment::Graphics::ShaderProgram::ShaderProgram()
{
    m_ProgramID = glCreateProgram();
}

Fragment::Graphics::ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(m_ProgramID);
}

void Fragment::Graphics::ShaderProgram::attachShader(const Shader * s)
{
    glAttachShader(m_ProgramID, s->getShaderID());
}

void Fragment::Graphics::ShaderProgram::linkProgram()
{
    glLinkProgram(m_ProgramID);
}

void Fragment::Graphics::ShaderProgram::useProgram()
{
    glUseProgram(m_ProgramID);
}

GLuint Fragment::Graphics::ShaderProgram::programID()
{
    return m_ProgramID;
}

GLint Fragment::Graphics::ShaderProgram::getUniformLocation(std::string name)
{
    return glGetUniformLocation(programID(), name.c_str());
}