#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

void draw(void){
	// Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 1.0f);

	// Desenha o teapot com a cor corrente (solid)
	glutSolidTeapot(50.0f);

	// glBegin(GL_TRIANGLES);
	
	// glNormal3f(1,1,1);
	// glVertex3f(50,50,0);

	// glNormal3f(0,0,-1);
	// glVertex3f(-50,-50,0);

	// glNormal3f(0,0,-1);
	// glVertex3f(50,-50,0);

	// glEnd();

	glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void init (void){
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		  // "cor"
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0}; // "brilho"
	
	GLfloat posicaoLuz[4]={0.0, -50.0, 50.0, 1.0};// ultimo parâmeto indica se é pontual (1.0) ou direcional (0.0)

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela será branca
 	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Habilita o modelo de colorização de Gouraud
	glShadeModel(GL_SMOOTH);//GL_FLAT

	// Define o grau de especularidade do material
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	
	// Define a concentração do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// GLfloat spotDirection[3]={0.1,-0.1,-1.0};
	// glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection );
	// glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 10.0 );//0-128
	// glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 15.0 );//0-90
	// glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0 );

	// Habilita a definição da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);

	//Habilita o uso de iluminação
	glEnable(GL_LIGHTING);

	// Habilita a luz de número 0
	glEnable(GL_LIGHT0);
	
	// Habilita o z-buffer
	glEnable(GL_DEPTH_TEST);

}

// Função callback chamada quando o tamanho da janela é alterado
void resize(GLsizei w, GLsizei h){
	if ( h == 0 ) h = 1;

	// Calcula a correção de aspecto
	GLfloat fAspect = (GLfloat)w/(GLfloat)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,fAspect,0.5,500);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutCreateWindow("Light");
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	init();
	glutMainLoop();
}
