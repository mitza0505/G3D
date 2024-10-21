//
// Created by mitza on 10/15/24.
//

#ifndef OPENGLWINDOW_H
#define OPENGLWINDOW_H

#include "includes.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexArray.h"



class openGLWindow {

private:
    std::vector<GLuint> m_vertexShaders;
    std::vector<GLuint> m_fragmentShaders;
    std::vector<GLuint> m_programs;

    std::vector<vertexArray> m_vaoId;
    std::vector<std::pair<vertexArray, indexBuffer>> m_iboId;


    GLuint compileShader(GLuint type, const GLchar* source);

    GLuint addProgram(GLuint vertexShader, GLuint fragmentShader);


  public:
    openGLWindow(int *argc, char** argv);

    static void renderFunction();

    void draw();


    static void setBackgroundColor(GLfloat, GLfloat, GLfloat);

    int pushNewShaders(const GLchar* vertexSource, const GLchar* fragmentSource);

    void useProgram(unsigned int index);

    unsigned int drawIndices(GLfloat vertices[], unsigned int vSize, GLfloat colors[], unsigned int cSize, GLuint indices[], unsigned int iSize, GLuint mode);

    unsigned int drawPoints(GLfloat vertices[], unsigned int vSize, GLfloat colors[], unsigned int cSize, GLuint mode = GL_POINTS);

     GLchar* readFile(const char* fileName);

    std::vector<std::pair<vertexArray, indexBuffer>> getIndexBuffers();

    ~openGLWindow() {
        glUseProgram(0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);

        for(auto& pair : m_iboId) {
            glDisableVertexAttribArray(1);
            glDisableVertexAttribArray(0);

            glDeleteVertexArrays(1, pair.first.getVaoID());
            glDeleteBuffers(1, pair.second.getBufferID());
        }

        for(size_t i = 0; i < m_programs.size(); i++) {
            glDetachShader(m_programs[i], m_fragmentShaders[i]);
            glDeleteShader(m_fragmentShaders[i]);

            glDetachShader(m_programs[i], m_vertexShaders[i]);
            glDeleteShader(m_vertexShaders[i]);

            glDeleteProgram(m_programs[i]);

        }

        glutCloseFunc(nullptr);
    }
};



#endif //OPENGLWINDOW_H
