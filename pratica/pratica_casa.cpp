#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif 

void display() {

    // limpa a tela
    glClear(GL_COLOR_BUFFER_BIT);

    // cor vermelha
    glColor3f(0.0, 0.0, 1.0);

    // desenha triangulo
    glBegin(GL_TRIANGLES);

        glVertex2f(0.0, 0.2);//A
        glVertex2f(-0.2, -0.2);//B
        glVertex2f(0.2,-0.2);//C
        

    glEnd();

    //cor verde 
    glColor3f(0.0,1.0,0.0);

    glBegin(GL_QUADS);
        glVertex2f(-0.2,-0.2);//B
        glVertex2f(0.2,-0.2);//C
        glVertex2f(0.2,-0.6); //D
        glVertex2f(-0.2, -0.6);//E

    glEnd();

    //cor vermelha
    glColor3f(1.0,0.0,0.0);
    //porta
    glBegin(GL_QUADS);
        glVertex2f(0.0,-0.3);//A
        glVertex2f(0.1,-0.3);//B
        glVertex2f(0.1,-0.6);//C
        glVertex2f(0.0,-0.6);//D

    glEnd();

    //cor azul
    glColor3f(0.0,0.0,1.0);

    glBegin(GL_QUADS);
        glVertex2f(0.0025,-0.4);//A
        glVertex2f(0.0080,-0.4);//B
        glVertex2f(0.0080,-0.42);//C
        glVertex2f(0.0025,-0.42);//D                          

    glEnd();
    //quadrado verde para me ter noção 
    //  glBegin(GL_QUADS);
    //     glVertex2f(-0.2,-0.2);//B
    //     glVertex2f(0.2,-0.2);//C
    //     glVertex2f(0.2,-0.6); //D
    //     glVertex2f(-0.2, -0.6);//E

    // glEnd();

    //cor vermelho
    //quadrado vermelho
    glColor3f(1.0,0.0,0.0);

    glBegin(GL_QUADS);
        glVertex2f(0.2,-0.2);//C
        glVertex2f(0.6,-0.2);//E
        glVertex2f(0.6,-0.6);//F
        glVertex2f(0.2,-0.6);//G

    glEnd();

    //cor azul
    glColor3f(0,0,1);

    glBegin(GL_QUADS);
        glVertex2f(0.25,-0.35);//A
        glVertex2f(0.35,-0.35);//B
        glVertex2f(0.35,-0.45);//C
        glVertex2f(0.25,-0.45);//D

    glEnd();

     glColor3f(0,0,1);

    glBegin(GL_QUADS);
        glVertex2f(0.4,-0.35);//A
        glVertex2f(0.5,-0.35);//B
        glVertex2f(0.5,-0.45);//C
        glVertex2f(0.4,-0.45);//D

    glEnd();
    //
    //   // desenha triangulo
    // glBegin(GL_TRIANGLES);

    //     glVertex2f(0.0, 0.2);//A
    //     glVertex2f(-0.2, -0.2);//B
    //     glVertex2f(0.2,-0.2);//C
         

    // glEnd();


    glColor3f(1.0,1.0,0.0);

    glBegin(GL_QUAD_STRIP);
        glVertex2f(0.0,0.2);//A OK
        glVertex2f(0.2,-0.2);//D OK

        glVertex2f(0.45,0.2);//B
        glVertex2f(0.6,-0.2);//C
     

        glEnd();

    
    
    // envia para tela
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800,800);

    glutCreateWindow("OpenGL");

    // cor do fundo
    glClearColor(1.0,1.0,1.0,1.0);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}