#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

float angleCamera = 45.0f;
float fAspect;
float xCamera = 0;
float yCamera = 5;

float anguloBracoPrincipal;
float anguloBracoSecundario;

void init(){
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glEnable(GL_DEPTH_TEST);
}

void configProjection(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angleCamera, fAspect, 0.5, 500);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(xCamera,yCamera,20, 0, 0, 0, 0, 1, 0);
}

void resize(int w, int h){
    if(h == 0){
        h = 1;
    }
    fAspect = (float)w / (float)h;
    glViewport(0, 0, w, h);
    configProjection();
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:
            exit(0);
            break;
        
        case 'w':
            yCamera += 1;
            break;
        case 's':
            yCamera -= 1;
            break;

        case 'a':
            xCamera -= 1;
            break;
        
        case 'd':
            xCamera += 1;
            break;

        case ' ':
            xCamera = 0;
            yCamera = 5;
            break;

        case 'i':
            anguloBracoPrincipal += 1;
            break;
        
        case 'k':
            anguloBracoPrincipal -= 1;
            break;

       case 'u':
            anguloBracoSecundario += 1;
            break;
        
        case 'j':
            anguloBracoSecundario -= 1;
            break;
    }
    glutPostRedisplay();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    configProjection();

    //DESENHO DO GUINDASTE

    //BASE CINZA
    glPushMatrix();
    glTranslatef(0, -4, 0);
    glColor3f(0.23f, 0.23f, 0.23f);
    glScalef(4.0f, 0.5f, 2.5f );
    glutSolidCube(1);
    glPopMatrix();

    //BASE AMARELA
    glPushMatrix();
    glTranslatef(0, -3.75, 0);
    glColor3f(0.94, 0.84, 0.05);
    glScalef(2.0f, 0.5f, 1.5f);
    glutSolidCube(1);
    glPopMatrix();

    //Haste principal
    glPushMatrix();
    glScalef(0.75f, 7.0f, 0.75f);
    glutSolidCube(1);
    glPopMatrix();


    //Braco principal 
    glPushMatrix();
    glTranslatef(0, 3.1f, 0);
    glRotatef(anguloBracoPrincipal, 0, 0, 1);
    glTranslatef(2.25f, 0, 0);
    glRotatef(-90.0, 0, 0, 1);
    glPushMatrix();
    glScalef(0.7f, 4.5f, 0.7f);
    glutSolidCube(1);
    glPopMatrix();

    //braco secundario


    glTranslatef(0, 2.25, 0);
    glRotatef(anguloBracoSecundario, 0, 0, 1);
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glScalef(0.25, 2, 0.25);
    glutSolidCube(1);
    glPopMatrix();

    //linha

    glTranslatef(0, 2, 0);
    glRotatef(-(anguloBracoPrincipal + anguloBracoSecundario), 0, 0, 1);
    glTranslatef(1.5f, 0, 0);
    glPushMatrix();
    glScalef(3.0f, 0.1f, 0.1f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glutSolidCube(1);
    glPopMatrix();

    //Ponta
    glPushMatrix();
    glTranslatef(1.5f, 0, 0);
    glScalef(0.25, 0.25, 0.25);
    glutSolidCube(1);
    glPopMatrix();

    glPopMatrix();

    

    glutSwapBuffers();
}

int main (int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Base");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

