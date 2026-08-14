#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void display() {

    glClearColor(0.9f, 0.9f, 0.9f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // =========================
    // PAREDE ESQUERDA
    // =========================
    glColor3f(0.7f, 0.15f, 0.3f);

    glBegin(GL_QUADS);
        glVertex2f(-0.9f, -0.5f);
        glVertex2f(-0.3f, -0.5f);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(-0.9f, 0.2f);
    glEnd();

    // =========================
    // PAREDE DIREITA
    // =========================
    glColor3f(0.1f, 0.2f, 0.3f);

    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.5f);
        glVertex2f(0.9f, -0.5f);
        glVertex2f(0.9f, 0.2f);
        glVertex2f(-0.3f, 0.2f);
    glEnd();

    // =========================
    // TELHADO ESQUERDO
    // =========================
    glColor3f(0.0f, 0.6f, 0.0f);

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.9f, 0.2f);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(-0.6f, 0.8f);
    glEnd();

    // =========================
    // TELHADO DIREITO
    // =========================
    glColor3f(0.35f, 0.5f, 0.8f);

    glBegin(GL_POLYGON);
        glVertex2f(-0.3f, 0.2f);
        glVertex2f(0.9f, 0.2f);
        glVertex2f(0.6f, 0.8f);
        glVertex2f(-0.6f, 0.8f);
    glEnd();

    // =========================
    // PORTA
    // =========================
    glColor3f(0.7f, 0.2f, 0.9f);

    glBegin(GL_QUADS);
        glVertex2f(-0.75f, -0.5f);
        glVertex2f(-0.45f, -0.5f);
        glVertex2f(-0.45f, -0.05f);
        glVertex2f(-0.75f, -0.05f);
    glEnd();

    // MAÇANETA
    glPointSize(8);

    glBegin(GL_POINTS);
        glColor3f(0.3f, 0.8f, 1.0f);
        glVertex2f(-0.6f, -0.25f);
    glEnd();

    // =========================
    // JANELA 1
    // =========================
    glColor3f(0.2f, 0.4f, 0.3f);

    glBegin(GL_QUADS);
        glVertex2f(-0.2f, -0.1f);
        glVertex2f(0.15f, -0.1f);
        glVertex2f(0.15f, 0.1f);
        glVertex2f(-0.2f, 0.1f);
    glEnd();

    // =========================
    // JANELA 2
    // =========================
    glBegin(GL_QUADS);
        glVertex2f(0.4f, -0.1f);
        glVertex2f(0.75f, -0.1f);
        glVertex2f(0.75f, 0.1f);
        glVertex2f(0.4f, 0.1f);
    glEnd();

    // =========================
    // LINHAS DAS JANELAS
    // =========================
    glLineWidth(3);
    glColor3f(0.0f, 1.0f, 0.7f);

    glBegin(GL_LINES);

        // janela esquerda
        glVertex2f(-0.025f, -0.1f);
        glVertex2f(-0.025f, 0.1f);

        glVertex2f(-0.2f, 0.0f);
        glVertex2f(0.15f, 0.0f);

        // janela direita
        glVertex2f(0.575f, -0.1f);
        glVertex2f(0.575f, 0.1f);

        glVertex2f(0.4f, 0.0f);
        glVertex2f(0.75f, 0.0f);

    glEnd();

    // =========================
    // SOMBRA
    // =========================
    glColor3f(0.35f, 0.55f, 0.75f);

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.9f, -0.5f);
        glVertex2f(-0.55f, -0.5f);
        glVertex2f(-1.05f, -0.85f);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(900, 500);

    glutCreateWindow("Casa OpenGL");

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}