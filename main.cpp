
#include "openGLWindow.h"

int main(int argc, char** argv) {

    srand (static_cast <unsigned> (time(0)));


    openGLWindow ctx(&argc, argv);

    GLuint program = ctx.pushNewShaders(ctx.readFile("../vertShader.glsl"),ctx.readFile("../fragShader.glsl"));
    ctx.useProgram(program);


    // GLfloat vertices[] = {
    //     -0.8f, 0.8f, 0.0f, 1.f,
    //     0.8f, 0.8f, 0.0f, 1.f,
    //     0.0f, 0.0f, 0.0f, 1.f,
    //     -0.8f, -0.8f, 0.0f, 1.f,
    //     0.8f, -0.8f, 0.0f, 1.f,
    //
    // };
    //
    // GLfloat colors[] = {
    //     0.0f, 1.0f, 0.0f, 1.f,
    //     0.0f, 1.0f, 0.0f, 1.f,
    //     0.0f, 1.0f, 0.0f, 1.f,
    //     0.0f, 1.0f, 0.0f, 1.f,
    //     0.0f, 1.0f, 0.0f, 1.f,
    // };
    //
    // openGLWindow::setBackgroundColor(0.0f, 0.0f, 0.8f);
    // ctx.drawPoints(vertices, sizeof(vertices), colors, sizeof(colors));

    // GLfloat vertices[] = {
    //     0.0f, -0.8f, 0.0f, 1.f,
    //     0.0f, 0.0f, 0.0f, 1.f,
    //     0.0f, 0.8f, 0.0f, 1.f,
    // };
    //
    // GLfloat colors[] = {
    //     0.0f, 1.0f, 0.0f, 1.f,
    //     0.0f, 1.0f, 0.0f, 1.f,
    //     0.0f, 1.0f, 0.0f, 1.f,
    // };
    //
    // openGLWindow::setBackgroundColor(0.8f, 0.0f, 0.0f);
    // ctx.drawPoints(vertices, sizeof(vertices), colors, sizeof(colors));

    ctx.draw();

    GLfloat vertices2[] = {
        -0.3f, -0.3f, 0.f, 1.f,
        0.1f, -0.2f, 0.f, 1.f,
        0.f, 0.f, 0.f, 1.f,
        0.3f, 0.f, 0.f, 1.f,
        0.1f, 0.2f, 0.f, 1.f,
        -0.3f, 0.3f, 0.f, 1.f
        };

    GLfloat colors2[] = {
        0.f, 0.f, 0.f, 1.f,
        1.f, 1.f, 0.f, 1.f,
        1.f, 0.f, 0.f, 1.f,
        1.f, 1.f, 0.f, 1.f,
        0.f, 1.f, 0.f, 1.f,
        0.f, 0.f, 1.f, 1.f,

        };

    GLuint indices[] = {
        0, 1, 2,
        1, 2, 3,
        2, 4, 3,
        2, 5, 4,
        0, 2, 5
    };


    ctx.drawIndices(vertices2, sizeof(vertices2), colors2, sizeof(colors2), indices, sizeof(indices), GL_TRIANGLES);

    GLfloat vertices22[] = {
        -0.8f, -0.8f, 0.f, 1.f,
        0.1f, -0.8f, 0.f, 1.f,
        -0.8f, 0.1f, 0.f, 1.f,
        0.1f, 0.1f, 0.f, 1.f,

        };

    GLfloat colors22[] = {
        1.f, 0.f, 1.f, 1.f,
        1.f, 0.f, 1.f, 1.f,
        1.f, 0.f, 1.f, 1.f,
        1.f, 0.f, 1.f, 1.f,

        };

    GLuint indices2[] = {
        0, 1, 2,
        2, 3, 1
    };



    ctx.drawIndices(vertices22, sizeof(vertices22), colors22, sizeof(colors22), indices2, sizeof(indices2), GL_TRIANGLES);



    glutMainLoop();

    return 0;
}