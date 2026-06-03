#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif 

// Desenvolva um programa OpenGL que desenhe uma casa composta por:

// Corpo da casa usando GL_QUADS
// Telhado usando GL_TRIANGLES
// Porta usando GL_QUADS
// Janela usando GL_QUADS

// Requisitos:

// Fundo azul claro.
// Casa marrom.
// Telhado vermelho.
// Janela azul.

void display() {

    // limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);
 
    glPushMatrix();

    glColor3f(1.0,0.0,0.0);

    glBegin(GL_TRIANGLES);
        glVertex2f(0.0,0.2);//A
        glVertex2f(-0.1,0.0);//B
        glVertex2f(0.1,0.0);//C

    glEnd();

    glPopMatrix();


    glPushMatrix();

    glColor3f(0.6f, 0.3f, 0.1f);//cor marron

    glBegin(GL_QUADS);
        glVertex2f(-0.1,0.0);
        glVertex2f(0.1,0.0);
        glVertex2f(0.1,-0.2);
        glVertex2f(-0.1,-0.2);


    glEnd();

    glPopMatrix();

    glPushMatrix();
    
    glColor3f(0.0,0.0,1.0);

    glBegin(GL_QUADS);
        glVertex2f(-0.08,-0.05);
        glVertex2f(-0.05,-0.05);    
        glVertex2f(-0.05,-0.08);    
        glVertex2f(-0.08,-0.08);    

    glEnd();

    glPopMatrix();

    glPushMatrix();

    glColor3d(0.0,0.0,0.0);

    glBegin(GL_QUADS);
        glVertex2f(0.025,-0.050);    
        glVertex2f(0.060,-0.050);    
        glVertex2f(0.060,-0.2);    
        glVertex2f(0.025,-0.2);
    glEnd();
    
    glPopMatrix();
    
    // envia para tela
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800,800);

    glutCreateWindow("OpenGL");

    // cor do fundo
    glClearColor(0.6,0.8,1.0,1.0);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}