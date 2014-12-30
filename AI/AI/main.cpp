#include "Headers.h"
#include "Scene.h"
#include "Obstacle.h"
#include "Zombie.h"

bool* keyStates = new bool[256];
Scene scene;

void init(){
	srand(time(NULL));
	unsigned char i = 'a';
	do{
		keyStates[i] = false;
		i++;
	} while (i != 'a');
	scene.AddObject(new Zombie(0.0, 0.0));
	scene.AddObject(new Obstacle(-0.50, -0.60, 0.35));
	scene.AddObject(new Obstacle(-0.40,  0.35, 0.25));
	scene.AddObject(new Obstacle( 0.50, -0.30, 0.30));
	scene.AddObject(new Obstacle( 0.45,  0.45, 0.15));


}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();
		//glScalef(0.5f, 0.5f, 1.0f);
		scene.InitDraw();
	glPopMatrix();

	glutSwapBuffers();
}

void idle(int i){
	scene.Draw(0.01);
	//glutPostRedisplay();
}

void idle(){
	//Sleep(70);
	//randoming position on the circle
	//(10, idle, 1);//
	glutTimerFunc(100, idle, 10);
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
	//gluPerspective(60, 1, 1, 300);
	//gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);
	glutCreateWindow("Basic AI");

	//Initial implementation of objects
	init();

	// register callbacks
	glutDisplayFunc(renderScene);
	//glutIdleFunc(idle);

	//Keyboard input
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}