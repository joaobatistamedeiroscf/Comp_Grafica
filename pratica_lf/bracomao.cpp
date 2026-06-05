#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

int ombro = 0, cotovelo = 0, mao = 0 ;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    {
        // OMBRO
        glRotatef(ombro, 0.0, 0.0, 1.0);

        // BRAÇO
        glPushMatrix();
        {
            glColor3f(0.5, 0.0, 0.0);
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        }
        glPopMatrix();

        // Vai para a ponta do braço
        glTranslatef(1.0, 0.0, 0.0);

        // COTOVELO
        glRotatef(cotovelo, 0.0, 0.0, 1.0);

        // Centro do antebraço
        glTranslatef(1.0, 0.0, 0.0);

        // ANTEBRAÇO
        glPushMatrix();
        {
            glColor3f(0.0, 0.0, 1.0);
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        }
        glPopMatrix();

        // Vai para a ponta do antebraço
        glTranslatef(1.0, 0.0, 0.0);

        // MÃO
        glPushMatrix();
        {
            glRotatef(mao, 0,0,1);
            glColor3f(0.0, 1.0, 0.0);
            glScalef(0.6, 0.3, 0.8);
            glutWireCube(1.0);
        }
        glPopMatrix();
    }
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(75.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);

    gluLookAt(
        0.0, 0.0, 5.0,
        0.0, 0.0, 0.0,
        0.0, 1.0, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        ombro += 5;
        break;

    case 'd':
        ombro -= 5;
        break;

    case 'w':
        cotovelo += 5;
        break;

    case 's':
        cotovelo -= 5;
        break;
    
     case 'r':
        mao += 5;
        break;

     case 'f':
        mao -= 5;
        break;


    case 27:
        exit(0);
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);

    glutCreateWindow("Braco Articulado");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glutMainLoop();

    return 0;
}