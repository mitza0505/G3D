//
// Created by mitza on 10/15/24.
//

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H
#include "includes.h"


class vertexBuffer {
    GLuint m_bufferID;
    unsigned int m_verticesCount;
public:

    vertexBuffer(const void* data, unsigned int size);
    vertexBuffer(const vertexBuffer& other);
    ~vertexBuffer();

    void bind();
    void unbind();
    unsigned int getVerticesCount();
};



#endif //VERTEXBUFFER_H
