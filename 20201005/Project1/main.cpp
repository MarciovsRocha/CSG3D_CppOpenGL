#include <windows.h>      // for MS Windows
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h

GLfloat angleV, fAspect;
GLfloat angle = 0.0f, angle1 = 0.0f;
char title[] = "Title";
GLfloat nRange = 25.0;


void initGL(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_EQUAL);
	glShadeModel(GL_FLAT);
}

// Função callback chamada para fazer o desenho
void render(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// rotaciona o cubo 
	glRotatef(15.0f,1.0f,1.0f,1.0f);
	
	// desenha o cubo
	glutWireCube(1.5*nRange);

	// desenha as linhas
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0,0.0,0.0);
			glVertex3f(+nRange, 0.0, 0.0);
		glColor3f(0.0f,1.0f,0.0);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0, +nRange, 0.0);
		glColor3f(0.0f,0.0f,1.0f);
			glVertex3f(0.0f,0.0f,0.0f);
			glVertex3f(0.0f,0.0f,+nRange);			
	glEnd();

	// desenha o triangulo
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,1.0f,1.0f);
		glVertex3f(0.0f,0.0f,0.5f);
		glVertex3f(10.0f,0.0f,0.5f);
		glVertex3f(5.0f,10.0f,0.5f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
		
		// primeiro triangulo
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,+10.0f);
		glVertex3f(0.0f,+10.0f,+10.0f);
		glVertex3f(+10.0f,0.0f,+10.0f);
		
		//segundo triangulo
		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(0.0f, -10.0f, +10.0f);

		// terceiro triangulo
		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(-10.0f,0.0f,+10.0f);

		// quarto triangulo
		glColor3f(1.0f,1.0f,0.0f);
		glVertex3f(0.0f, +10.0f, +10.0f);
	glEnd();


	glFlush();
}

void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1; // avoid division by zero
	glViewport(0, 0, w, h);  // set Viewport dimensions
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA); // Define buffered mode
	glutInitWindowSize(500, 500);     // Set the window's initial width & height
	glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(render);          // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);         // Register callback handler for window re-size event
	initGL();                         // Our own OpenGL initialization
	glutMainLoop();                   // Enter the infinite event-processing loop
	return 0;
}