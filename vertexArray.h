//
// Created by mitza on 10/15/24.
//

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H
#include "includes.h"
#include "vertexBuffer.h"


class vertexArray {
private:
    GLuint m_vaoId;
    vertexBuffer *m_vbo;
    vertexBuffer *m_cbo;

public:
    vertexArray(vertexBuffer &vbo, vertexBuffer& cbo);

    ~vertexArray();

    void bind();
    void unbind();

    const GLuint *getVaoID();
     vertexBuffer *getVbo();
     vertexBuffer *getCbo();


};



#endif //VERTEXARRAY_H
