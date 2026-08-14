#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat fAspect;
GLdouble rotX = 0, rotY = 0, rotHead = 0, rotBlade = 0;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLineWidth(2);

	glRotatef(rotX, 1, 0, 0);
	glRotatef(rotY, 0, 1, 0); 
	glColor3f(1.0f, 0.0f, 0.0f);

	// Base
	glPushMatrix();
	{
		glScalef(10, 2, 10);
		glutWireCube(1);
	}
	glPopMatrix();

	// Haste
	 glPushMatrix();
	 {
		glTranslated(0,5,0);
	 	glScalef(2, 10, 2);
	 	glutWireCube(1);
	 }
	 glPopMatrix();


	 //Motor
		glPushMatrix();
		{
		glColor3f(0.0,0.0,1.0);
		glTranslatef(0,12.75,-1);// 12.50 x 4 = 50
		glRotatef(rotHead,0,1,0);
     	glScalef(4, 4, 6);
		glutWireCube(1);
		}
		glPopMatrix();

 	// Ponta
	 	glPushMatrix();
	 	{
			glColor3f(0.0,0.0,1.0);
			glTranslatef(0,12.50,0);
	 		glutSolidSphere(0.5, 10, 8);
	 	}
	 	glPopMatrix();


	///Hélice 1
		glPushMatrix();
	 		{
			glColor3f(0.0,1.0,0.0);
			glTranslatef(0,12.50,0);
			glRotatef(rotHead,0,0,1);
	 		glScalef(16, 2, 1);
	 		glutWireCube(1);
	 		}
	 		glPopMatrix();

	// Hélice 2
	 	glPushMatrix();
	 		{
			glTranslatef(0,12.50,0);
			glRotatef(rotHead,0,0,1);
	 		glScalef(2, 16, 1);
			glutWireCube(1);
	 		}
	 		glPopMatrix();


	glutSwapBuffers();
}

void configProjection(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45, fAspect, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	gluLookAt(0, 0, 50, 0, 0, 0, 0, 1, 0);
}

void resize(GLsizei w, GLsizei h)
{
	if (h == 0)
		h = 1;

	fAspect = (GLfloat)w / (GLfloat)h;

	configProjection();
}

void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 27:
		exit(0);
		break;

	case 'Z':
	case 'z':
		rotHead += 10;
		break;

	case 'X':
	case 'x':
		rotHead -= 10;
		rotBlade += 10;
		break;

	case 32:
		rotHead += 10;
		rotBlade += 10;
		break;

	default:
		break;
	}

	glutPostRedisplay();
}

void specialkeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		rotX += 10;
		break;
	case GLUT_KEY_DOWN:
		rotX += 10;
		break;
	case GLUT_KEY_LEFT:
		rotY += 10;
		break;
	case GLUT_KEY_RIGHT:
		rotY -= 10;
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Avaliação 02");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeys);
	glutMainLoop();
	return 0;
}
