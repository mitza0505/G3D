//
// Created by mitza on 10/15/24.
//

#include "indexBuffer.h"

indexBuffer::indexBuffer(const unsigned int* data, unsigned int count, unsigned int drawMode) {

    m_drawMode = drawMode;

    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count, data, GL_STATIC_DRAW);
    m_indexCount = count/sizeof(GLuint);
}

indexBuffer::~indexBuffer() {
    //glDeleteBuffers(1, &m_bufferID);
}

void indexBuffer::bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}

void indexBuffer::unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

GLuint indexBuffer::getIndexCount() {
    return m_indexCount;
}

GLuint indexBuffer::getDrawMode() {
    return m_drawMode;
}

const GLuint *indexBuffer::getBufferID() {
    return &m_bufferID;
}
