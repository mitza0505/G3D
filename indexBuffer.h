//
// Created by mitza on 10/15/24.
//

#ifndef INDEXBUFFER_H
#define INDEXBUFFER_H
#include "includes.h"


class indexBuffer {
private:
    GLuint m_bufferID;
    GLuint m_indexCount;
    GLuint m_drawMode;
    public:

    indexBuffer(const unsigned int* data, unsigned int count, unsigned int drawMode);
    ~indexBuffer();

    void bind();
    void unbind();
    GLuint getIndexCount();
    GLuint getDrawMode();

    const GLuint *getBufferID();

};



#endif //INDEXBUFFER_H
