// CSCE A211
// Graphics Framework by Matthew Devins
// This code uses OpenGL and demonstrates drawing some text and some
// simple shapes, pixels, and color changes.
//
// To the reader: You only need to focus on the code in the "display" function
// for now.

#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void init();
void display();
//void startScreen();
void handleButton(int button, int state, int x, int y);
void printText(int x, int y, const char *string);


void *font = GLUT_BITMAP_TIMES_ROMAN_24;//GLUT_STROKE_ROMAN;
const int WIDTH = 230;
const int HEIGHT = 400;
static int screenx = 0;
static int screeny = 0;


int rgb[HEIGHT][WIDTH][3] = { 0 };




int main(int argc, char** argv)
{
	
	srand(time(NULL));
	
	int fifty = 0;

	for (int i = 0; i < WIDTH; i++) {
		rgb[0][i][0] = ((rand() % 50) + 205);
		rgb[0][i][1] = ((rand() % 50) + 205);
		//rgb[0][i][2] = 0;
	}

	for (int j = 1; j < HEIGHT; j++) {
		for (int i = 0; i < WIDTH; i++) {
			rgb[HEIGHT][WIDTH][0] = (rgb[HEIGHT][WIDTH - 1][0] + rgb[HEIGHT][WIDTH + 1][0] + rgb[HEIGHT - 1][WIDTH - 1][0] + rgb[HEIGHT - 1][WIDTH + 1][0] + rgb[HEIGHT - 1][WIDTH][0]) / 5;
			fifty = (rand() % 2);
			if (fifty == 0) { rgb[HEIGHT][WIDTH][0] = rgb[HEIGHT][WIDTH][0] - ((rand()%4)+1); }
			rgb[HEIGHT][WIDTH][1] = (rgb[HEIGHT][WIDTH - 1][1] + rgb[HEIGHT][WIDTH + 1][1] + rgb[HEIGHT - 1][WIDTH - 1][1] + rgb[HEIGHT - 1][WIDTH + 1][1] + rgb[HEIGHT - 1][WIDTH][1]) / 5;
			fifty = (rand() % 2);
			if (fifty == 0) { rgb[HEIGHT][WIDTH][1] = rgb[HEIGHT][WIDTH][1] - ((rand() % 8) + 1); }
			rgb[HEIGHT][WIDTH][2] = 0;
		}
	}
	
			







	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Just A Window");

	init();
	glutIdleFunc(display);
	glutMouseFunc(handleButton);

	glutMainLoop();

	return 0;
}

void init()
{

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3d(255, 0, 100);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(screenx, screenx + WIDTH, screeny + HEIGHT, screeny);
}


/* For this lab you only need to work in this display function */
void display()
{

	glDrawPixels(WIDTH, HEIGHT, GL_RGB, GL_UNSIGNED_INT, rgb);

	glutSwapBuffers();
	//glFlush();

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