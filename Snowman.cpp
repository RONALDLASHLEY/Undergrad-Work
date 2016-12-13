////////////////////////////////////////////////////////////////      
// This program draws a snowman.
//
// Interaction:
// Press space to toggle between animation on and off.
// Press the up/down arrow keys to speed up/slow down animation.
// Press the x, X, y, Y, z, Z keys to rotate the scene.
//
////////////////////////////////////////////////////////////////   

#include <iostream>

#ifdef __APPLE__
#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <OpenGL/glext.h>
#else
#  include <C:/Program Files/Microsoft SDKs/Windows/v7.1/Include/gl/glew.h>
#  include <C:/Program Files/Microsoft SDKs/Windows/v7.1/Include/gl/freeglut.h>
#  include <C:/Program Files/Microsoft SDKs/Windows/v7.1/Include/gl/glext.h>
#pragma comment(lib, "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.0A/Lib/glew32.lib")
#endif

/*#  include <GL/glew.h>
#  include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif*/

using namespace std;

// Globals.
static float latAngle = 0.0; // Latitudinal angle.
static float longAngle = 0.0; // Longitudinal angle.
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; // Angles to rotate scene.
static int isAnimate = 0; // Animated
static int animationPeriod = 100; // Time interval between frames.

// Drawing routine.
void Snowman(void)
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -25.0);
       
   // Rotate scene.
   glRotatef(Zangle, 0.0, 0.0, 1.0);
   glRotatef(Yangle, 0.0, 1.0, 0.0);
   glRotatef(Xangle, 1.0, 0.0, 0.0);

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
   glColor3f(255, 102, 0); //Orange Nose displays Yellow
   glTranslatef(0, 9, 2); // Translates nose onto Top ball of snowman
   glutSolidCone(0.5, 1.0, 20.0, 1.0); //Nose (GLdouble base, GLdouble height, GLint slices, GLint stacks);
   //End of Nose

   //Buttons Top down order
   glColor3f(0, 0, 0); //Black buttons
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
   glColor3f(0, 1, 0); //Green Eyes
   glTranslatef(1, 10, -3.75); // Translates Right eye onto Top ball of snowman
   glutSolidSphere(0.25, 20.0, 20.0); //Nose (GLdouble base, GLdouble height, GLint slices, GLint stacks);
   glTranslatef(-2, 0, 0); // Translates Left eye onto Top ball of snowman
   glutSolidSphere(0.25, 20.0, 20.0); //Nose (GLdouble base, GLdouble height, GLint slices, GLint stacks);
   
   glRotatef(270, 0, 1, 0);
   glutSwapBuffers();
   
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
   glClearColor(0.0, 0.0, 153.0, 0.0); 
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
   switch(key) 
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
      case 'x':
         Xangle += 5.0;
		 if (Xangle > 360.0) Xangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'X':
         Xangle -= 5.0;
		 if (Xangle < 0.0) Xangle += 360.0;
         glutPostRedisplay();
         break;
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
      case 'z':
         Zangle += 5.0;
		 if (Zangle > 360.0) Zangle -= 360.0;
         glutPostRedisplay();
         break;
      case 'Z':
         Zangle -= 5.0;
		 if (Zangle < 0.0) Zangle += 360.0;
         glutPostRedisplay();
         break;
      default:
         break;
   }
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
   if (key == GLUT_KEY_DOWN) animationPeriod += 5;
   if( key == GLUT_KEY_UP) if (animationPeriod > 5) animationPeriod -= 5;
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
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("Snowman.cpp"); 
   glutDisplayFunc(Snowman); 
   glutReshapeFunc(resize);  
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(specialKeyInput);

   glewExperimental = GL_TRUE; 
   glewInit(); 
   
   setup(); 

   glutMainLoop(); 
}

