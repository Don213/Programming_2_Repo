#pragma once
#include <iostream>
#include "World.h"
#include "Organism.h"


#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <string.h>
#include <math.h>


using namespace std;


//DoodleBug Image: https://entonation.com/wp-content/uploads/2018/01/Doodlebug.jpg


World w;


void init();
void display();
void handleButton(int button, int state, int x, int y);
void printText(int x, int y, const char *string);

void *font = GLUT_BITMAP_TIMES_ROMAN_24;//GLUT_STROKE_ROMAN;
const int WIDTH = 900;
const int HEIGHT = 900;

static int screenx = 0;
static int screeny = 0;






int main(int argc, char** argv)
{
	w = World();

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DoodleBug Simulation");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(handleButton);

	glutMainLoop();



	//cin.get();


	return 0;
}









void init()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(screenx, screenx + WIDTH, screeny + HEIGHT, screeny);
}


/* For this lab you only need to work in this display function */
void display()
{
	
	//////////////////////////Box
	glBegin(GL_LINES);
	glVertex2f(40, 40);
	glVertex2f(40, 840);
	glEnd();
	
	glBegin(GL_LINES);
	glVertex2f(40, 840);
	glVertex2f(840, 840);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(840, 840);
	glVertex2f(840, 40);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(840, 40);
	glVertex2f(40, 40);
	glEnd();
	//////////////////////////Box





	//////////////////////////Lines (Horizontal)
	glBegin(GL_LINES);
	glVertex2f(40,80);
	glVertex2f(840, 80);
	glEnd();//1

	glBegin(GL_LINES);
	glVertex2f(40, 120);
	glVertex2f(840, 120);
	glEnd();//2

	glBegin(GL_LINES);
	glVertex2f(40, 160);
	glVertex2f(840, 160);
	glEnd();//3

	glBegin(GL_LINES);
	glVertex2f(40, 200);
	glVertex2f(840, 200);
	glEnd();//4

	glBegin(GL_LINES);
	glVertex2f(40, 240);
	glVertex2f(840, 240);
	glEnd();//5

	glBegin(GL_LINES);
	glVertex2f(40, 280);
	glVertex2f(840, 280);
	glEnd();//6

	glBegin(GL_LINES);
	glVertex2f(40, 320);
	glVertex2f(840, 320);
	glEnd();//7

	glBegin(GL_LINES);
	glVertex2f(40, 360);
	glVertex2f(840, 360);
	glEnd();//8

	glBegin(GL_LINES);
	glVertex2f(40, 400);
	glVertex2f(840, 400);
	glEnd();//9

	glBegin(GL_LINES);
	glVertex2f(40, 440);
	glVertex2f(840, 440);
	glEnd();//10





	glBegin(GL_LINES);
	glVertex2f(40, 480);
	glVertex2f(840, 480);
	glEnd();//11

	glBegin(GL_LINES);
	glVertex2f(40, 520);
	glVertex2f(840, 520);
	glEnd();//12

	glBegin(GL_LINES);
	glVertex2f(40, 560);
	glVertex2f(840, 560);
	glEnd();//13

	glBegin(GL_LINES);
	glVertex2f(40, 600);
	glVertex2f(840, 600);
	glEnd();//14

	glBegin(GL_LINES);
	glVertex2f(40, 640);
	glVertex2f(840, 640);
	glEnd();//15

	glBegin(GL_LINES);
	glVertex2f(40, 680);
	glVertex2f(840, 680);
	glEnd();//16

	glBegin(GL_LINES);
	glVertex2f(40, 720);
	glVertex2f(840, 720);
	glEnd();//17

	glBegin(GL_LINES);
	glVertex2f(40, 760);
	glVertex2f(840, 760);
	glEnd();//18

	glBegin(GL_LINES);
	glVertex2f(40, 800);
	glVertex2f(840, 800);
	glEnd();//19
	//////////////////////////Lines (Horizontal)








	//////////////////////////Lines (Vertical)
	glBegin(GL_LINES);
	glVertex2f(80, 40);
	glVertex2f(80, 840);
	glEnd();//1

	glBegin(GL_LINES);
	glVertex2f(120, 40);
	glVertex2f(120, 840);
	glEnd();//2

	glBegin(GL_LINES);
	glVertex2f(160, 40);
	glVertex2f(160, 840);
	glEnd();//3

	glBegin(GL_LINES);
	glVertex2f(200, 40);
	glVertex2f(200, 840);
	glEnd();//4

	glBegin(GL_LINES);
	glVertex2f(240, 40);
	glVertex2f(240, 840);
	glEnd();//5

	glBegin(GL_LINES);
	glVertex2f(280, 40);
	glVertex2f(280, 840);
	glEnd();//6

	glBegin(GL_LINES);
	glVertex2f(320, 40);
	glVertex2f(320, 840);
	glEnd();//7

	glBegin(GL_LINES);
	glVertex2f(360, 40);
	glVertex2f(360, 840);
	glEnd();//8

	glBegin(GL_LINES);
	glVertex2f(400, 40);
	glVertex2f(400, 840);
	glEnd();//9

	glBegin(GL_LINES);
	glVertex2f(440, 40);
	glVertex2f(440, 840);
	glEnd();//10





	glBegin(GL_LINES);
	glVertex2f(480, 40);
	glVertex2f(480, 840);
	glEnd();//11

	glBegin(GL_LINES);
	glVertex2f(520, 40);
	glVertex2f(520, 840);
	glEnd();//12

	glBegin(GL_LINES);
	glVertex2f(560, 40);
	glVertex2f(560, 840);
	glEnd();//13

	glBegin(GL_LINES);
	glVertex2f(600, 40);
	glVertex2f(600, 840);
	glEnd();//14

	glBegin(GL_LINES);
	glVertex2f(640, 40);
	glVertex2f(640, 840);
	glEnd();//15

	glBegin(GL_LINES);
	glVertex2f(680, 40);
	glVertex2f(680, 840);
	glEnd();//16

	glBegin(GL_LINES);
	glVertex2f(720, 40);
	glVertex2f(720, 840);
	glEnd();//17

	glBegin(GL_LINES);
	glVertex2f(760, 40);
	glVertex2f(760, 840);
	glEnd();//18

	glBegin(GL_LINES);
	glVertex2f(800, 40);
	glVertex2f(800, 840);
	glEnd();//19
	//////////////////////////Lines (Horizontal)









	glutSwapBuffers();
	glFlush();

	return;
}

/* Handles a mouse button, not needed for this program */
void handleButton(int button, int state, int x, int y)
{
	static int index = -1;

	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			printText(30, HEIGHT / 2, "You clicked the mouse button!");
			glutSwapBuffers();
			glFlush();
			w.displayGrid();

		}
		if (state == GLUT_UP)
		{
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