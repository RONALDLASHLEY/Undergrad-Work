//////////////////////////////////////////////////////////////      
// ballAndTorus.cpp
//
// This program draws a snowman.
//
// Interaction:
// Press space to toggle between animation on and off.
// Press the up/down arrow keys to speed up/slow down animation.
// Press the x, X, y, Y, z, Z keys to rotate the scene.
//
// Sumanta Guha.
////////////////////////////////////////////////////////////////   

#include <iostream>

#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
/*#  include <C:/Program Files/Microsoft SDKs/Windows/v7.1/Include/gl/glew.h>
#  include <C:/Program Files/Microsoft SDKs/Windows/v7.1/Include/gl/freeglut.h>
#  include <C:/Program Files/Microsoft SDKs/Windows/v7.1/Include/gl/glext.h>
#pragma comment(lib, "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/glew32.lib")
#endif*/

#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif

using namespace std;
#define PI 3.14159265/2
#define N 40.0 // Number of vertices on the boundary of the disc.
// Globals.
static float latAngle = 0.0; // Latitudinal angle.
static float longAngle = 0.0; // Longitudinal angle.
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate scene.
static int isAnimate = 0; // Animated?
static int animationPeriod = 100; // Time interval between frames.
static float angle = 0.0; // Rotation.angle of hat.
						  //static int isAnimate = 0; // Animated?
						  //static int animationPeriod = 100; // Time interval between frames.

void writeBitmapString(void *font, char *string)
{
	char *c;
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Routine to draw a stroke character string.
void writeStrokeString(void *font, char *string)
{
	char *c;
	for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

void drawDisc(float R, float X, float Y, float Z)
{
	float t;
	int i;

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(X, Y, Z);
	for (i = 0; i <= N; ++i)
	{
		t = 2 * PI * i / N;
		glVertex3f(X + cos(t) * R, Y + sin(t) * R, Z);
	}
	glEnd();
}


// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -25.0);

	// Rotate scene.
	//glRotatef(Zangle, 0.0, 0.0, 1.0);
	glRotatef(Yangle, 0.0, 1.0, 0.0);
	//glRotatef(Xangle, 1.0, 0.0, 0.0);
	
	glColor3f(192, 192, 192);
	//Snowman Body Top down order
	glTranslatef(0.0, -3.0, 0.0); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(2.0, 20.0, 20.0); //Top Ball (GLdouble radius,GLint slices, GLint stacks)
	glTranslatef(0.0, -5.0, 0.0); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(4.0, 20.0, 20.0); //Middle Ball (GLdouble radius,GLint slices, GLint stacks)
	glTranslatef(0.0, -4.0, 0.0); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(5.0, 20.0, 20.0); //Bottom Ball (GLdouble radius,GLint slices, GLint stacks)
									  //End of Snowman Body
									  // End revolving ball.

									  //Nose
	glColor3f(1, 0, 0);
	glTranslatef(0, 9, 2); // Translates nose onto Top ball of snowman
	glutSolidCone(0.5, 1.0, 20.0, 1.0); //Nose (GLdouble base, GLdouble height, GLint slices, GLint stacks);
										//End of Nose

										//Buttons Top down order
	glColor3f(0, 0, 0);
	glTranslatef(0.0, -3.0, 1.50); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(.25, 20.0, 20.0); //Bottom Ball (GLdouble radius,GLint slices, GLint stacks)
	glTranslatef(0.0, -1.0, 0.25); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(.25, 20.0, 20.0); //Bottom Ball (GLdouble radius,GLint slices, GLint stacks)

	glTranslatef(0.0, -3.0, 0.75); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(.25, 20.0, 20.0); //Bottom Ball (GLdouble radius,GLint slices, GLint stacks)
	glTranslatef(0.0, -1.0, 0.40); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(.25, 20.0, 20.0); //Bottom Ball (GLdouble radius,GLint slices, GLint stacks)
	glTranslatef(0.0, -1.0, .20); //(GLfloat x,GLfloat y,GLfloat z)
	glutSolidSphere(.25, 20.0, 20.0); //Bottom Ball (GLdouble radius,GLint slices, GLint stacks)

									  //Eyes
	glColor3f(0, 1, 0);
	glTranslatef(1, 10, -3.75); // Translates Right eye onto Top ball of snowman
	glutSolidSphere(0.25, 20.0, 20.0); //Nose (GLdouble base, GLdouble height, GLint slices, GLint stacks);
	glTranslatef(-2, 0, 0); // Translates Left eye onto Top ball of snowman
	glutSolidSphere(0.25, 20.0, 20.0); //Nose (GLdouble base, GLdouble height, GLint slices, GLint stacks);
									   //roland

									   //Conelius
									   //*** clown1.cpp starts here. ***
									   // Place scene in frustum.
	glTranslatef(0.0, 25.0, -9.0);


	//*** clown2.cpp starts here. ***
	glPushMatrix();

	// Tree Position.
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(6.0, 0.0, -2.0);

	// Tree
	glColor3f(0.0, 1.0, 0.0);
	glutSolidCone(2.0, 6.0, 40, 40);

	// Brim and trunk.
	glutSolidTorus(0.2, 2.2, 10, 25);
	glColor3f(0.5, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -2.0);
	glutSolidCylinder(1.0, 2.0, 20.0, 9.0);

	glPopMatrix();
	//------------------------------------------------------------------------
	glPushMatrix();
	// Tree Position.2
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(3.0, 6.0, -2.0);

	// Tree.2
	glColor3f(0.0, 1.0, 0.0);
	glutSolidCone(2.0, 6.0, 40, 40);

	// Brim and trunk.
	glutSolidTorus(0.2, 2.2, 10, 25);
	glColor3f(0.5, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -2.0);
	glutSolidCylinder(1.0, 2.0, 20.0, 9.0);

	glPopMatrix();
	//-------------------------------------------------------------------------

	glPushMatrix();
	// Tree Position.3
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-4.0, 15.0, -2.0);

	// Tree.3
	glColor3f(0.0, 1.0, 0.0);
	glutSolidCone(2.0, 6.0, 40, 40);

	// Brim and trunk.
	glutSolidTorus(0.2, 2.2, 10, 25);
	glColor3f(0.5, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -2.0);
	glutSolidCylinder(1.0, 2.0, 20.0, 9.0);

	glPopMatrix();
	//----------------------------------------------------------------------------------

	glPushMatrix();
	// Tree Position.4
	glRotatef(angle, 0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	glTranslatef(-6.0, -1.0, -2.0);

	// Tree.4
	glColor3f(0.0, 1.0, 0.0);
	glutSolidCone(2.0, 6.0, 40, 40);

	// Brim and trunk.
	glutSolidTorus(0.2, 2.2, 10, 25);
	glColor3f(0.5, 0.0, 0.0);
	glTranslatef(0.0, 0.0, -2.0);
	glutSolidCylinder(1.0, 2.0, 20.0, 9.0);

	glPopMatrix();




	//*** clown3.cpp ends here. ***
	/**/
	//Cornelius
	//glTranslatef(70.0, 7.0, 10.0);
	//Josh
	glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads

	glColor3f(0.0f, 1.0f, 0.0f);     // Green
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);

	// Bottom face (y = -1.0f)
	glColor3f(1.0f, 0.5f, 0.0f);     // Orange
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Front face  (z = 1.0f)
	glColor3f(1.0f, 0.0f, 10.0f);     // Red
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);

	// Back face (z = -1.0f)
	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	// Left face (x = -1.0f)
	glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Right face (x = 1.0f)
	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);
	glEnd();  // End of drawing color-cube
	//josh
	//MAB
	glTranslatef(-75.0, -65.0, -25.0);
	glPolygonMode(GL_FRONT, GL_FILL);

	// first
	glColor3f(1.0, 0.0, 0.0);
	drawDisc(5.0, 25.0, 35.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	drawDisc(2.5, 25.0, 35.0, 0.5);

	// second
	glColor3f(1.0, 0.0, 0.0);
	drawDisc(5.0, 50.0, 35.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	drawDisc(2.5, 50.0, 35.0, 0.5);

	// third
	glColor3f(1.0, 0.0, 0.0);
	drawDisc(5.0, 50.0, 65.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	drawDisc(2.5, 50.0, 65.0, 0.5);

	//first
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(22.5, 20.0, 0.0);
	glVertex3f(22.5, 35.0, 0.0);
	glVertex3f(20.0, 35.0, 0.0);
	glEnd();

	//second
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(45.0, 20.0, 0.0);
	glVertex3f(47.5, 20.0, 0.0);
	glVertex3f(47.5, 35.0, 0.0);
	glVertex3f(45.0, 35.0, 0.0);
	glEnd();

	//third
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(45.0, 50.0, 0.0);
	glVertex3f(47.5, 50.0, 0.0);
	glVertex3f(47.5, 65.0, 0.0);
	glVertex3f(45.0, 65.0, 0.0);
	glEnd();
	//MAB
	
	//fiyin
	glRotatef(10.0, 0.0, 10.0, 0.0);
	glColor3f(1.0, 1.0, 0.8);
	glTranslatef(65.0, 25.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 50.0, 0.0);
	glVertex3f(60.0, 50.0, 0.0);
	glVertex3f(70.0, 35.0, 0.0);
	glVertex3f(30.0, 35.0, 0.0);

	glEnd();
	// Top of Front Wall
	glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(20.0, 50.0, 0.0);
	glVertex3f(10.0, 35.0, 0.0);
	glVertex3f(30.0, 35.0, 0.0);
	glEnd();
	// Front Wall
	glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(10.0, 35.0, 0.0);
	glVertex3f(30.0, 35.0, 0.0);
	glVertex3f(30.0, 10.0, 0.0);
	glVertex3f(10.0, 10.0, 0.0);

	glEnd();
	// Front Door
	glColor3f(0.4, 0.2, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(15.0, 25.0, 0.0);
	glVertex3f(25.0, 25.0, 0.0);
	glVertex3f(25.0, 10.0, 0.0);
	glVertex3f(15.0, 10.0, 0.0);
	glEnd();

	// Front Door Lock
	glColor3f(0.3, 0.7, 0.9);
	glPointSize(15);
	glBegin(GL_POINTS);
	//glVertex2i(170, 170);
	glVertex3f(17.0, 17.0, 0.0);
	glEnd();

	//side Wall
	glColor3f(0.6, 0.3, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(30.0, 35.0, 0.0);
	glVertex3f(70.0, 35.0, 0.0);
	glVertex3f(70.0, 10.0, 0.0);
	glVertex3f(30.0, 10.0, 0.0);
	glEnd();
	// window one
	glColor3f(1.0, 0.6, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(33.0, 32.0, 0.0);
	glVertex3f(45.0, 32.0, 0.0);
	glVertex3f(45.0, 23.0, 0.0);
	glVertex3f(33.0, 23.0, 0.0);
	glEnd();
	// line of window one
	glColor3f(0.6, 0.3, 0.0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(39.0, 32.0, 0.0);
	glVertex3f(39.0, 23.0, 0.0);
	glVertex3f(33.0, 27.3, 0.0);
	glVertex3f(45.0, 27.3, 0.0);
	glEnd();
	// window two
	glColor3f(1.0, 0.6, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(53.0, 32.0, 0.0);
	glVertex3f(65.0, 32.0, 0.0);
	glVertex3f(65.0, 23.0, 0.0);
	glVertex3f(53.0, 23.0, 0.0);
	glEnd();
	// lines of window two
	glColor3f(0.6, 0.3, 0.0);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(59.0, 32.0, 0.0);
	glVertex3f(59.0, 23.0, 0.0);
	glVertex3f(53.0, 27.3, 0.0);
	glVertex3f(65.0, 27.3, 0.0);
	glEnd();

	// Entrance Path
	glColor3f(0.3, 0.5, 0.7);
	glLineWidth(3);
	glBegin(GL_POLYGON);
	/*glVertex2i(150, 100);
	glVertex2i(250, 100);
	glVertex2i(210, 0);
	glVertex2i(40, 0);*/
	glEnd();
	//fiyin

	glutSwapBuffers();

	glPushMatrix();
	glTranslatef(40.0, 40.0, 0.0);
	glRotatef(-30.0, 0.0, 0.0, 1.0);
	glScalef(0.025, 0.025, 0.025);
	writeStrokeString(GLUT_STROKE_MONO_ROMAN, "GLUT_STROKE_MONO_ROMAN");
	glPopMatrix();

	glFlush();
}

// Timer function.
void animate(int value)
{
	if (isAnimate)
	{
		latAngle += 5.0;
		if (latAngle > 360.0) latAngle -= 360.0;
		longAngle += 1.0;
		if (longAngle > 360.0) longAngle -= 360.0;

		glutPostRedisplay();
		glutTimerFunc(animationPeriod, animate, 1);
	}
}

// Initialization routine.
void setup(void)
{
	glClearColor(00.0, 128.0, 70.0, 70.0);
	glEnable(GL_DEPTH_TEST); // Enable depth testing.
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case ' ':
		if (isAnimate) isAnimate = 0;
		else
		{
			isAnimate = 1;
			animate(1);
		}
		break;
		/*case 'x':
		Xangle += 5.0;
		if (Xangle > 360.0) Xangle -= 360.0;
		glutPostRedisplay();
		break;
		case 'X':
		Xangle -= 5.0;
		if (Xangle < 0.0) Xangle += 360.0;
		glutPostRedisplay();
		break;
		*/
	case 'y':
		Yangle += 5.0;
		if (Yangle > 360.0) Yangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'Y':
		Yangle -= 5.0;
		if (Yangle < 0.0) Yangle += 360.0;
		glutPostRedisplay();
		break;
		/*case 'z':
		Zangle += 5.0;
		if (Zangle > 360.0) Zangle -= 360.0;
		glutPostRedisplay();
		break;
		case 'Z':
		Zangle -= 5.0;
		if (Zangle < 0.0) Zangle += 360.0;
		glutPostRedisplay();
		break;
		*/
	default:
		break;
	}
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN) animationPeriod += 5;
	if (key == GLUT_KEY_UP) if (animationPeriod > 5) animationPeriod -= 5;
	glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	cout << "Interaction:" << endl;
	cout << "Press space to toggle between animation on and off." << endl
		<< "Press the up/down arrow keys to speed up/slow down animation." << endl
		<< "Press the x, X, y, Y, z, Z keys to rotate the scene." << endl;
}

// Main routine.
int main(int argc, char **argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Chrismas Card.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}