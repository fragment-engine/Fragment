//
// Created by Frank Lyder Bredland on 10/03/16.
//

#include "Fragment/Graphics/VAO.h"

Fragment::Graphics::VAO::VAO()
{
    glGenVertexArrays(1, &m_VertexArrayID);
    bind();
}

Fragment::Graphics::VAO::~VAO()
{
    glDeleteVertexArrays(1, &m_VertexArrayID);
}

void Fragment::Graphics::VAO::bind()
{
    glBindVertexArray(m_VertexArrayID);
}