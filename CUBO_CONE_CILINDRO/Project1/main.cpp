#include <windows.h>  // for MS Windows
#include <GL\freeglut.h>  // GLUT, include glu.h and gl.h
#include <math.h> // biblioteca utilizada para calcular o seno e cosseno 

char title[] = "Marcio Vinicius de Souza da Rocha - BCC - Noite";
GLfloat nRange = 20;

float rAngle = 0.0;

// ===============================================================================================================================

/* animation resources - rAngle from 0 to 360 */
void update(int value) {
	rAngle += 1.0f;
	if (rAngle > 360) rAngle -= 360;
	glutPostRedisplay(); // Inform GLUT that the display has changed
	glutTimerFunc(25, update, 0);// chama a função update(int value) a cada 25 milisegundos
} // void update(int value)

// ===============================================================================================================================

/* Inicializa OpenGL */
void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // define o plano de fundo como preto & opaco
	glClearDepth(1.0f);                   // define a cor de fundo da profundidade 
	glEnable(GL_DEPTH_TEST);   // habilita a função de GL_DEPTH_TEST para o eixo-z
	glDepthFunc(GL_LEQUAL);    // define o tipo de funcionamento do GL_DEPTH_TEST
	glShadeModel(GL_FLAT);     // habilita a sombra suave
} // void initGL() 

// ===============================================================================================================================

// função para desenhar um cubo a partir de uma malha de triangulos
void cubo(float k) {
	// k == tamanho da aresta
	/*
		* Eixo X 
			-k == esquerda
			 k == direita
		
		* Eixo Y
			-k == em baixo
			 k == em cima
		
		* Eixo Z
			-k == atras 
			 k == frente
	*/
	/* Calculando vertices */
	double Ax = -k / 2;
	double Ay = k / 2;
	double Az = k / 2;

	double Bx = -k / 2;
	double By = -k / 2;
	double Bz = k / 2;

	double Cx = k / 2;
	double Cy = k / 2;
	double Cz = k / 2;

	double Dx = k / 2;
	double Dy = -k / 2;
	double Dz = k / 2;

	double Ex = k / 2;
	double Ey = k / 2;
	double Ez = -k / 2;

	double Fx = k / 2;
	double Fy = -k / 2;
	double Fz = -k / 2;

	double Gx = -k / 2;
	double Gy = k / 2;
	double Gz = -k / 2;

	double Hx = -k / 2;
	double Hy = -k / 2;
	double Hz = -k / 2;
	/* fim do calculo dos vertices*/

	/* 
	Desenha as laterais do cubo percorrendo os pontos na seguinte ordem:
		 A -> B -> C -> D -> E -> F -> G -> H -> A -> B
	*/
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0f,0.0f,0.0f); // define a cor verde para o vertice 'A'
		glVertex3f(Ax,Ay,Az); // vertice A
		glColor3f(1.0f, 0.5f, 0.0f); // define a cor verde para o vertice 'B'
		glVertex3f(Bx,By,Bz); // vertice B
		glColor3f(1.0f, 1.0f, 0.0f); // define a cor verde para o vertice 'C'
		glVertex3f(Cx, Cy, Cz); // vertice C
		glColor3f(0.0f, 1.0f, 0.5f); // define a cor verde para o vertice 'D'
		glVertex3f(Dx, Dy, Dz); // vertice D
		glColor3f(0.0f, 1.0f, 1.0f); // define a cor verde para o vertice 'E'
		glVertex3f(Ex, Ey, Ez); // vertice E
		glColor3f(0.0f, 0.0f, 1.0f); // define a cor verde para o vertice 'F'
		glVertex3f(Fx, Fy, Fz); // vertice F
		glColor3f(0.5f, 0.0f, 1.0f); // define a cor verde para o vertice 'G'
		glVertex3f(Gx, Gy, Gz); // vértice G
		glColor3f(1.0f, 0.0f, 1.0f); // define a cor verde para o vertice 'H'
		glVertex3f(Hx, Hy, Hz); // vértice H
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(Ax, Ay, Az); // vértice A
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(Bx, By, Bz); // vértice B
	glEnd(); // fim do desenho das laterais

	/*
	Desenha a "tampa" do cubo segundo a seguinte ordem dos vertices:
		G -> A -> E -> C
	Cor da "tampa" = cinza claro
	*/
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.5f,0.5f,0.5f);
		glVertex3f(Gx,Gy,Gz);
		glVertex3f(Ax, Ay, Az);
		glVertex3f(Ex,Ey,Ez);
		glVertex3f(Cx,Cy,Cz);
	glEnd(); // fim do desenho da "tampa" do cubo

	/*
	Desenha o "fundo" do cubo segundo a seguinte ordem de vertices:
		H -> B -> F -> D
	Cor do "fundo" = cinza escuro
	*/
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25f,0.25f,0.25f);
		glVertex3f(Hx, Hy, Hz);
		glVertex3f(Bx, By, Bz);
		glVertex3f(Fx, Fy, Fz);
		glVertex3f(Dx, Dy, Dz);
	glEnd(); //fim do desenho do "fundo" do cubo
} // void cubo(float a)

// ===============================================================================================================================
void disco(float Cx, float Cy, float Cz, float raio) {
	float pi = 3.14156;
	float x, y = 0;
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.25f, 0.40f, 0.25f);
		for (float angle = 0.0; angle < (2 * pi); angle += (pi / 18)) {
			x = raio * sin(angle);
			y = raio * cos(angle);
			glVertex3f((Cx + x), (Cy + y), Cz);
			glVertex3f(Cx, Cy, Cz);
		} // for ( float angle = 0.0; angle < (2 * pi);angle +=(pi/18) )
	glEnd();
}

// ===============================================================================================================================

// funcao para desenhar	um cone com uma malha de triangulos
void cone(float Cx, float Cy, float Cz, float altura, float raio) {
	float pi = 3.14156;
	float x,y = 0.0f;
	// desenha a base do cone de acordo com o raio definido
	disco(Cx,Cy,Cz,raio);
	
	// desenha a lateral do cone de acordo com o raio e altura passados
	glBegin(GL_TRIANGLE_STRIP);
		for (float angle = 0.0f; angle < (2 * pi);angle +=(pi/18)) {
			glColor3f(0.5f,0.45f,0.9f);
			x = raio * sin(angle);
			y = raio * cos(angle);
			glVertex3f((Cx+x),(Cy+y),Cz);
			glVertex3f(Cx,Cy,(Cz+altura));
		} // for (float angle = 0.0f; angle < (2 * pi);angle +=(pi/18))
	glEnd();
} // void cone(float k)

// ===============================================================================================================================
void cilindro(float Cx, float Cy, float Cz, int altura, float raio) {
	/*
		Cx, Cy, Cz sao as coordenadas do centro da base do cilindro
	*/
	float x,y,pAux = 0.0f;
	float pi = 3.14156;
	
	disco(Cx, Cy, Cz, raio); // base do cilindro
	disco(Cx, Cy, (Cz+altura), raio); // "tampa" do cilindro

	// desenha a lateral do cilindro
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f(0.3f,0.8f,0.1f);
		// primeiro laco for eh pra desenhar n'linhas
		for (float linhas = 0.1f; linhas <= altura; linhas +=0.1f) {
			for ( float angulo = 0.0f; angulo < (2 * pi); angulo += (pi/18) ) {
				x = raio * sin(angulo);
				y = raio * cos(angulo);
				pAux = (x +(pi / 18));
				glVertex3f((Cx+x),(Cy+y),Cz);
				glVertex3f((Cx + x), (Cy + y), (Cz+linhas));
				glVertex3f((Cx + pAux), (Cy + y), Cz);
				glVertex3f((Cx + pAux), (Cy + y), (Cz+linhas));
			} // for ( float angulo = 0.0f; angulo < (2 * pi); angulo += (pi/18) )
		} // for ( float angulo = 0.0f; angulo < (2 * pi); angulo += (pi/18) )
	glEnd();// fim do desenho da base do cilindro

} // void cilindro(float altura, float raio)
// ===============================================================================================================================

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glMatrixMode(GL_MODELVIEW);        // To operate on model-view matrix
	glLoadIdentity();                  // Reset the model-view matrix
	glTranslatef(5.0f,5.0f,5.0f);
	glRotatef(-rAngle, 0, +rAngle/2, 0);
	cubo(3);
	glRotatef(-rAngle, -rAngle, 0.0f, -rAngle);
	cone(5.0f, -10.0f, 3.5f,5.0f,4.0f);
	glRotatef(-rAngle, (+rAngle*2), (+rAngle+1), (-rAngle*.05));
	cilindro(10.0f,10.0f,3.0f,7,4.0f);
	
	// XYZ Axis
	glTranslatef(0.0f,0.0f,0.0f);
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

	glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
} // void render()


// ===============================================================================================================================

void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;
	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);
	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange, nRange);
} // void reshape(GLsizei w, GLsizei h)

// ===============================================================================================================================

int main(int argc, char** argv) {
	glutInit(&argc, argv);            // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
	glutInitWindowSize(640, 480);     // Set the window's initial width & height
	glutInitWindowPosition(50, 50);   // Position the window's initial top-left corner
	glutCreateWindow(title);          // Create window with the given title
	glutDisplayFunc(render);          // Register callback handler for window re-paint event
	glutReshapeFunc(reshape);         // Register callback handler for window re-size event
	initGL();                         // Inicialização da OpenGL
	glutTimerFunc(25, update, 0);
	glutMainLoop();                   // event-processing loop
	return 0;
} // int main(int argc, char** argv)

/*
	Reaproveitado código disponibilizado como exemplo da aula para 
	realizacao da atividade solicitada

	@by: Marcio Vinicius de Souza da Rocha
*/