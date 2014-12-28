#include <cmath>
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include "Zombie.h"

using namespace std;


#define PI 3.14159265358979323846

bool* keyStates = new bool[256];
static float a = 0.0f, b=0.0f; // position
static float oa = 0.0f, ob = 0.3f; // orientation
float speed = 0.05f;
float angle = 0.f;
//Zombie z;

static float objects[4][3];


void init(){
	srand(time(NULL));
	unsigned char i = 'a';
	do{
		keyStates[i] = false;
		i++;
	}while (i != 255);
	//z = Zombie(0.0f, 0.0f, 40.0f);
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glPushMatrix();
	glScalef(0.5f, 0.5f, 1.0f);
	
	//z.Draw();

	glPopMatrix();
	glutSwapBuffers();
}

bool collision(float x, float y){
	bool state=true;
	float xx=0.0, yy=0.0, test=0.0, test2=0.0;
	for (int i = 0; i < 4; i++){
		xx = objects[i][0] - (a + x); 
		yy = objects[i][1] - (b + y); 
		test = sqrt(xx*xx + yy*yy); 
		test2 = objects[i][2] + 0.1;
		if (test < test2)
			state=false;
	}
	return state;
}

void idle(int i){	
	//z.wander();
	//glutPostRedisplay();
}

void idle(){
	//Sleep(70);
	//randoming position on the circle
	//(10, idle, 1);//
	glutTimerFunc(100, idle, 1);
	glutPostRedisplay();
}

void keyPressed(unsigned char key, int x, int y) {
	keyStates[key] = true; // Set the state of the current key to pressed  
	/*if (key == 'a' && collision(-0.01, 0.0)) a -= 0.01; 
	if (key == 's' && collision(0.0, -0.01)) b -= 0.01; 
	if (key == 'd' && collision(0.01, 0.0)) a += 0.01; 
	if (key == 'w' && collision(0.0, 0.01)) b += 0.01;
	glutTimerFunc(1, idle, 1);*/
}

void keyUp(unsigned char key, int x, int y){
	keyStates[key] = false;
}

int main(int argc, char **argv)
{
	
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(700, 700);
	gluPerspective(60, 1, 1, 300);
	gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
	glutCreateWindow("Basic AI");
	
	//Initial implementation of objects
	init();

	// register callbacks
	glutDisplayFunc(renderScene);
	glutIdleFunc(idle);

	//Keyboard input
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}