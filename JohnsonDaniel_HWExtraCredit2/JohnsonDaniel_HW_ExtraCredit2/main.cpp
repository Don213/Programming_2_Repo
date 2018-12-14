//
// Main function
//
// The main function creates the world then just prompts for an input (quit or continue with the next timestep).
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "World.h"

#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <string.h>
#include <math.h>




using std::rand;
using std::srand;
using std::cout;
using std::endl;
using std::cin;







void init();
void display();
void handleButton(int button, int state, int x, int y);
void printText(int x, int y, const char *string);

void *font = GLUT_BITMAP_TIMES_ROMAN_24;//GLUT_STROKE_ROMAN;
const int WIDTH = 1000;
const int HEIGHT = 1000;

static int screenx = 0;
static int screeny = 0;

World world;





int main(int argc, char** argv)
{
	
	char c;
	int step = 0;

	srand(time(NULL));





	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DoodleBug Simulation");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(handleButton);

	glutMainLoop();




	/*
	do
	{
		cout << "Timestep: " << step << endl;
		world.print();
		cout << "Enter 'q' to quit, any other key to simulate one time step." << endl;
		cin >> c;
		if (c != 'q')
		{
			world.simulateTick();
			step++;
		}
		cout << endl;
	} while (c != 'q');	
	*/



}





void init()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(screenx, screenx + WIDTH, screeny + HEIGHT, screeny);
}



void display()
{

	//////////////////////////Box
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 880);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(0, 880);
	glVertex2f(880, 880);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(880, 880);
	glVertex2f(880, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(880, 0);
	glVertex2f(0, 0);
	glEnd();
	//////////////////////////Box





	//////////////////////////Lines (Horizontal)
	glBegin(GL_LINES);
	glVertex2f(0, 40);
	glVertex2f(880, 40);
	glEnd();//0

	glBegin(GL_LINES);
	glVertex2f(0, 80);
	glVertex2f(880, 80);
	glEnd();//1

	glBegin(GL_LINES);
	glVertex2f(0, 120);
	glVertex2f(880, 120);
	glEnd();//2

	glBegin(GL_LINES);
	glVertex2f(0, 160);
	glVertex2f(880, 160);
	glEnd();//3

	glBegin(GL_LINES);
	glVertex2f(0, 200);
	glVertex2f(880, 200);
	glEnd();//4

	glBegin(GL_LINES);
	glVertex2f(0, 240);
	glVertex2f(880, 240);
	glEnd();//5

	glBegin(GL_LINES);
	glVertex2f(0, 280);
	glVertex2f(880, 280);
	glEnd();//6

	glBegin(GL_LINES);
	glVertex2f(0, 320);
	glVertex2f(880, 320);
	glEnd();//7

	glBegin(GL_LINES);
	glVertex2f(0, 360);
	glVertex2f(880, 360);
	glEnd();//8

	glBegin(GL_LINES);
	glVertex2f(0, 400);
	glVertex2f(880, 400);
	glEnd();//9

	glBegin(GL_LINES);
	glVertex2f(0, 440);
	glVertex2f(880, 440);
	glEnd();//10





	glBegin(GL_LINES);
	glVertex2f(0, 480);
	glVertex2f(880, 480);
	glEnd();//11

	glBegin(GL_LINES);
	glVertex2f(0, 520);
	glVertex2f(880, 520);
	glEnd();//12

	glBegin(GL_LINES);
	glVertex2f(0, 560);
	glVertex2f(880, 560);
	glEnd();//13

	glBegin(GL_LINES);
	glVertex2f(0, 600);
	glVertex2f(880, 600);
	glEnd();//14

	glBegin(GL_LINES);
	glVertex2f(0, 640);
	glVertex2f(880, 640);
	glEnd();//15

	glBegin(GL_LINES);
	glVertex2f(0, 680);
	glVertex2f(880, 680);
	glEnd();//16

	glBegin(GL_LINES);
	glVertex2f(0, 720);
	glVertex2f(880, 720);
	glEnd();//17

	glBegin(GL_LINES);
	glVertex2f(0, 760);
	glVertex2f(880, 760);
	glEnd();//18

	glBegin(GL_LINES);
	glVertex2f(0, 800);
	glVertex2f(880, 800);
	glEnd();//19

	glBegin(GL_LINES);
	glVertex2f(0, 840);
	glVertex2f(880, 840);
	glEnd();//20
	//////////////////////////Lines (Horizontal)








	//////////////////////////Lines (Vertical)
	glBegin(GL_LINES);
	glVertex2f(40, 0);
	glVertex2f(40, 880);
	glEnd();//0

	glBegin(GL_LINES);
	glVertex2f(80, 0);
	glVertex2f(80, 880);
	glEnd();//1

	glBegin(GL_LINES);
	glVertex2f(120, 0);
	glVertex2f(120, 880);
	glEnd();//2

	glBegin(GL_LINES);
	glVertex2f(160, 0);
	glVertex2f(160, 880);
	glEnd();//3

	glBegin(GL_LINES);
	glVertex2f(200, 0);
	glVertex2f(200, 880);
	glEnd();//4

	glBegin(GL_LINES);
	glVertex2f(240, 0);
	glVertex2f(240, 880);
	glEnd();//5

	glBegin(GL_LINES);
	glVertex2f(280, 0);
	glVertex2f(280, 880);
	glEnd();//6

	glBegin(GL_LINES);
	glVertex2f(320, 0);
	glVertex2f(320, 880);
	glEnd();//7

	glBegin(GL_LINES);
	glVertex2f(360, 0);
	glVertex2f(360, 880);
	glEnd();//8

	glBegin(GL_LINES);
	glVertex2f(400, 0);
	glVertex2f(400, 880);
	glEnd();//9

	glBegin(GL_LINES);
	glVertex2f(440, 0);
	glVertex2f(440, 880);
	glEnd();//10





	glBegin(GL_LINES);
	glVertex2f(480, 0);
	glVertex2f(480, 880);
	glEnd();//11

	glBegin(GL_LINES);
	glVertex2f(520, 0);
	glVertex2f(520, 880);
	glEnd();//12

	glBegin(GL_LINES);
	glVertex2f(560, 0);
	glVertex2f(560, 880);
	glEnd();//13

	glBegin(GL_LINES);
	glVertex2f(600, 0);
	glVertex2f(600, 880);
	glEnd();//14

	glBegin(GL_LINES);
	glVertex2f(640, 0);
	glVertex2f(640, 880);
	glEnd();//15

	glBegin(GL_LINES);
	glVertex2f(680, 0);
	glVertex2f(680, 880);
	glEnd();//16

	glBegin(GL_LINES);
	glVertex2f(720, 0);
	glVertex2f(720, 880);
	glEnd();//17

	glBegin(GL_LINES);
	glVertex2f(760, 0);
	glVertex2f(760, 880);
	glEnd();//18

	glBegin(GL_LINES);
	glVertex2f(800, 0);
	glVertex2f(800, 880);
	glEnd();//19

	glBegin(GL_LINES);
	glVertex2f(840, 0);
	glVertex2f(840, 880);
	glEnd();//20
	//////////////////////////Lines (Horizontal)









	glutSwapBuffers();
	glFlush();

	return;
}

/* Handles a mouse button, not needed for this program */
void handleButton(int button, int state, int x, int y)
{
	//static int index = -1;

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			
			//glClear(GL_COLOR_BUFFER_BIT);
			//printText(30, HEIGHT / 2, "You clicked the mouse button!");
			//glutSwapBuffers();
			//glFlush();

			
			world.simulateTick();


		}
		if (state == GLUT_UP)
		{
			glColor3f(0.0f, 0.2f, 0.6f);
			display();
		}

	}
}

// This function prints a string of text on the screen at coordinate x,y
void printText(int x, int y, const char *string)
{
	int i, length;

	glRasterPos2f(x, y);
	length = (int)strlen(string);
	for (i = 0; i < length; i++)
	{
		glutBitmapCharacter(font, string[i]);
	}
}




















