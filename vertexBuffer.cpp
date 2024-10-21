//
// Created by mitza on 10/15/24.
//

#include "vertexBuffer.h"

vertexBuffer::vertexBuffer(const void *data, unsigned int size) {
    glGenBuffers(1, &m_bufferID);
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);

    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    m_verticesCount = size/sizeof(GLfloat);
}

vertexBuffer::vertexBuffer(const vertexBuffer &other) {
    m_bufferID = other.m_bufferID;
}

vertexBuffer::~vertexBuffer() {
    //glDeleteBuffers(1, &m_bufferID);
}

void vertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
}

void vertexBuffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

unsigned int vertexBuffer::getVerticesCount() {
    return m_verticesCount;
}
