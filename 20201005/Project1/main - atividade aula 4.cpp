#include <windows.h>  // for MS Windows
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h

/* Global variables */
char title[] = "OpenGL-PUC PR (ANIMACAO - TESTE DE PROFUNDIDADE)";
GLfloat nRange = 20;

float rAngle = 0.0;

/* animation resources - rAngle from 0 to 360 */
void update(int value) {
	rAngle += 1.0f;
	if (rAngle > 360) rAngle -= 360;
	glutPostRedisplay(); // Inform GLUT that the display has changed
	glutTimerFunc(25, update, 0);//Call update after each 25 millisecond
}

/* Initialize OpenGL Graphics */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_FLAT);     // Enable smooth shading
}

/* Handler for window-repaint event. Called back when the window first appears and
whenever the window needs to be re-painted. */
void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);        // To operate on model-view matrix
	glLoadIdentity();                  // Reset the model-view matrix

	glRotatef(-rAngle, 0.0f, 1.0f, 0.0f);

	// Drawing XYZ Axis
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); // Red - X (to rigth)
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(+nRange, 0.0, 0.0);
	glColor3f(0.0, 1.0, 0.0); // Green - Y (to up)
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, +nRange, 0.0);
	glColor3f(0.0, 0.0, 1.0); // Blue - Z (leaving the screen)
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, +nRange);
	glEnd();

	// Drawing Triangles
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 5.0);
	glVertex3f(10.0, 0.0, 5.0);
	glVertex3f(5.0, 10.0, 5.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 15.0);
	glVertex3f(10.0, 0.0, 15.0);
	glVertex3f(5.0, 10.0, 15.0);
	glEnd();

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

/* Handler for window re-size event. Called back when the window first appears and
whenever the window is re-sized with its new width and height */
void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;
	// Especifica as dimens�es da Viewport
	glViewport(0, 0, w, h);
	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);     // Set the window's initial width & height
	glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(render);          // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);         // Register callback handler for window re-size event
	initGL();                         // Our own OpenGL initialization
	glutTimerFunc(25, update, 0);
	glutMainLoop();                   // Enter the infinite event-processing loop
	return 0;
}