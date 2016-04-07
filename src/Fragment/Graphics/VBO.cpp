//
// Created by Frank Lyder Bredland on 10/03/16.
//

#include "Fragment/Graphics/VBO.h"

Fragment::Graphics::VBO::VBO()
{
    glGenBuffers(1, &m_vertexbuffer);
    bind();
}

Fragment::Graphics::VBO::~VBO()
{
    glDeleteBuffers(1, &m_vertexbuffer);
}

void Fragment::Graphics::VBO::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);
}