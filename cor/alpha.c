#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

GLfloat angle, fAspect;
GLdouble rotX = 0, rotY = 0, rotZ = 0;

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glLineWidth(2);

	glPushMatrix();
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
	glRotatef(rotZ,0,0,1);

	//Cabeca
	glPushMatrix();
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(0,25,0);
		glutSolidCube(20);
		glutWireCube(20);
	glPopMatrix();

	//Braco 1
	glPushMatrix();
		glTranslatef(-20,10,0);
		glRotatef(-90,0,0,1);
		glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
		glutSolidCube(10);
		glutWireCube(10);
		glPushMatrix();
			glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
			glTranslatef(0,-10,0);
			glutSolidCube(10);
			glutWireCube(10);
		glPopMatrix();
	glPopMatrix();

	//Braco 2
	glPushMatrix();
		glTranslatef(20,10,0);
		glColor4f(0.0f, 1.0f, 1.0f,0.3f);
		glutSolidCube(10);
		glutWireCube(10);
		glPushMatrix();
			glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
			glTranslatef(0,-10,0);
			glutSolidCube(10);
			glutWireCube(10);
		glPopMatrix();
	glPopMatrix();

	//Perna 1
	glPushMatrix();
		glTranslatef(-10,-20,0);
		glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
		glutSolidCube(10);
		glutWireCube(10);
		glPushMatrix();
			glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
			glTranslatef(0,-10,0);
			glutSolidCube(10);
			glutWireCube(10);
		glPopMatrix();
	glPopMatrix();

	//Perna 2
	glPushMatrix();
		glTranslatef(10,-20,0);
		glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
		glutSolidCube(10);
		glutWireCube(10);
		glPushMatrix();
			glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
			glTranslatef(0,-10,0);
			glutSolidCube(10);
			glutWireCube(10);
		glPopMatrix();
	glPopMatrix();

	//Corpo
	glColor4f(0.0f, 0.0f, 1.0f,0.5f);
	glutSolidCube(30);
	glutWireCube(30);

	glPopMatrix();

	glutSwapBuffers();
}

void init() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	angle = 45;
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	// glCullFace(GL_FRONT);
}

void configProjection(void) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(angle, fAspect, 0.5, 500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
}

void resize(GLsizei w, GLsizei h) {
	if (h == 0)
		h = 1;

	fAspect = (GLfloat) w / (GLfloat) h;

	configProjection();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-in
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {  // Zoom-out
			if (angle <= 130)
				angle += 5;
		}
	configProjection();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	switch (key) {
	case 27:
		exit(0);
		break;
	case 'a':
		rotX -= 10;
		break;
	case 'd':
		rotX += 10;
		break;
	case 'w':
		rotY += 10;
		break;
	case 's':
		rotY -= 10;
		break;
	case 'q':
		rotZ += 10;
		break;
	case 'e':
		rotZ -= 10;
		break;
	case 32:
		rotX = 0;
		rotY = 0;
		rotZ = 0;
		break;
	default:
		break;
	}
	configProjection();
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA |GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}
