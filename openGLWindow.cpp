//
// Created by mitza on 10/15/24.
//

#include "openGLWindow.h"

#include <string.h>

openGLWindow *ctx = nullptr;




 openGLWindow::openGLWindow(int *argc, char** argv) {
    glutInit(argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);

    glutInitWindowPosition(100, 100);


    glutCreateWindow("Primul Triunghi - OpenGL <<nou>>");
    std::cout << "OpenGL version supported by this platform: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLSL version supported by this platform: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

    glewInit();
    this->setBackgroundColor(0.3f, 0.3f, 0.3f);

     ctx = this;
}

GLuint openGLWindow::compileShader(GLuint type, const GLchar *source) {
    GLuint shaderId = glCreateShader(type);
    glShaderSource(shaderId, 1, &source, NULL);
    glCompileShader(shaderId);

    int result;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
    if(result == GL_FALSE) {
        int length;
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);
        char message[length];
        glGetShaderInfoLog(shaderId, length, &length, message);
        std::cout << "Failed to compile " << ((type == GL_VERTEX_SHADER) ? "vertex" : "fragment") << " shader!\n" << message << std::endl;
        glDeleteShader(shaderId);
        return 0;
    }
    return shaderId;
}

GLuint openGLWindow::addProgram(GLuint vertexShader, GLuint fragmentShader) {

    GLuint programId = glCreateProgram();
    glAttachShader(programId, vertexShader);
    glAttachShader(programId, fragmentShader);

    glLinkProgram(programId);

    return programId;
}


void openGLWindow::renderFunction() {

    glClear(GL_COLOR_BUFFER_BIT);

    for(size_t i = 0; i < ctx->m_iboId.size(); i++) {

        ctx->m_iboId[i].first.bind();
        ctx->m_iboId[i].second.bind();

       glDrawElements(ctx->m_iboId[i].second.getDrawMode(), ctx->m_iboId[i].second.getIndexCount(), GL_UNSIGNED_INT, NULL);

        ctx->m_iboId[i].first.unbind();
        ctx->m_iboId[i].second.unbind();
    }

     for(size_t i = 0; i < ctx->m_vaoId.size(); i++) {
         ctx->m_vaoId[i].getVbo()->bind();
         ctx->m_vaoId[i].getCbo()->bind();
         ctx->m_vaoId[i].bind();

         glPointSize(20.0f);
         glDrawArrays(GL_POINTS, 0, ctx->m_vaoId[i].getVbo()->getVerticesCount()/4);

         ctx->m_vaoId[i].unbind();
         ctx->m_vaoId[i].getVbo()->unbind();
         ctx->m_vaoId[i].getCbo()->unbind();
     }

    glFlush();
}

void openGLWindow::draw() {
    glutDisplayFunc(openGLWindow::renderFunction);
}

void openGLWindow::setBackgroundColor(GLfloat r, GLfloat g, GLfloat b) {
    glClearColor(r, g, b, 1.f);
}

int openGLWindow::pushNewShaders(const GLchar *vertexSource, const GLchar *fragmentSource) {
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);
    GLuint programObject = addProgram(vertexShader, fragmentShader);

    m_vertexShaders.emplace_back(vertexShader);
    m_fragmentShaders.emplace_back(fragmentShader);
    m_programs.emplace_back(programObject);

    glUseProgram(programObject);

     delete[] vertexSource;
     delete[] fragmentSource;
    return m_vertexShaders.size() - 1;
}

void openGLWindow::useProgram(unsigned int index) {
    glUseProgram(m_programs[index]);
}

unsigned int openGLWindow::drawIndices(GLfloat vertices[], unsigned int vSize, GLfloat colors[], unsigned int cSize, GLuint indices[], unsigned int iSize, GLuint mode) {

    vertexBuffer vbo(vertices, vSize);
    vertexBuffer cbo(colors, cSize);

    vertexArray vao(vbo, cbo);
    indexBuffer ibo(indices, iSize, mode);

     m_iboId.emplace_back(vao, ibo);
    return m_iboId.size() - 1;
}

unsigned int openGLWindow::drawPoints(GLfloat vertices[], unsigned int vSize, GLfloat colors[], unsigned int cSize, GLuint mode) {
     vertexBuffer vbo(vertices, vSize);
     vertexBuffer cbo(colors, cSize);
     vertexArray vao(vbo, cbo);

     m_vaoId.emplace_back(vao);
     return m_vaoId.size() - 1;
}

GLchar * openGLWindow::readFile(const char *fileName) {
    std::ifstream fin(fileName);
    std::string buf;

    std::string line;
    while(!fin.eof()) {
        std::getline(fin, line);
        buf+=line;
        buf+='\n';
    }
    fin.close();
    GLchar *shaderSource = new GLchar[buf.length()];
    strcpy(shaderSource, buf.c_str());
    return shaderSource;
}

std::vector<std::pair<vertexArray, indexBuffer>> openGLWindow::getIndexBuffers() {
    return m_iboId;
}
