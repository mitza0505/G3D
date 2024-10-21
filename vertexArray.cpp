//
// Created by mitza on 10/15/24.
//

#include "vertexArray.h"

vertexArray::vertexArray(vertexBuffer &vbo, vertexBuffer &cbo) :     m_vbo{&vbo
}, m_cbo{&cbo} {


    glGenVertexArrays(1, &m_vaoId);
    glBindVertexArray(m_vaoId);

    vbo.bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    cbo.bind();
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

}

vertexArray::~vertexArray() {
    //glDeleteVertexArrays(1, &m_vaoId);
}

void vertexArray::bind() {
    glBindVertexArray(m_vaoId);
}

void vertexArray::unbind() {
    glBindVertexArray(0);
}

const GLuint *vertexArray::getVaoID() {
    return &m_vaoId;
}

vertexBuffer *vertexArray::getVbo() {
    return m_vbo;


}

vertexBuffer *vertexArray::getCbo() {
    return m_cbo;
}
