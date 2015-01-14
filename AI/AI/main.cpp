#include "Headers.h"
#include "Scene.h"
#include "Obstacle.h"
#include "Zombie.h"

bool* keyStates = new bool[256];
Scene scene;
Zombie *z = new Zombie(0.0, 0.0);

void init(){
	srand(time(NULL));
	unsigned char i = 'a';
	do{
		keyStates[i] = false;
		i++;
	} while (i != 'a');
	scene.AddObject(z);
	scene.AddObject(new Obstacle(15.0, 15.0, 7.00));
	scene.AddObject(new Obstacle(-12.0, -17.0, 9.00));
	scene.AddObject(new Obstacle(12.0, -6.0, 5.00));
	scene.AddObject(new Obstacle(-16.0, 15.0, 6.00));
}

void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glPushMatrix();

		glScalef(0.03f, 0.03f, 1.0f);
		scene.InitDraw();

	glPopMatrix();

	glutSwapBuffers();
}

void idle(int i){
	
	//system("cls");
	
	//cout << *z;

	//system("pause");
	//glutPostRedisplay();
	//system("pause");
}

void idle(){
	static long long int old_time = 0;

	long long int time_since_start = glutGet(GLUT_ELAPSED_TIME);
	double dt = (time_since_start - old_time) * 0.001f;
	old_time = time_since_start;

	scene.Draw(dt);
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
	glMatrixMode(GL_MODELVIEW);
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