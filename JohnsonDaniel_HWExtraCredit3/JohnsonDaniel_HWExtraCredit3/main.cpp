// CSCE A211
// Graphics Framework by Matthew Devins
// This code uses OpenGL and demonstrates drawing some text and some
// simple shapes, pixels, and color changes.
//
// To the reader: You only need to focus on the code in the "display" function
// for now.

#include "gl/glut.h"
#include "gl/gl.h"
#include "gl/glu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

GLsizei height = 400;
GLsizei width = 230;


int x = 0, y = 0;
float r, g, b;
int rgb[400][230][3] = { 0 };


void idle()
{

	srand(time(NULL));


	for (int i = 1; i < height; i++) {
		for (int j = 0; j < width; j++) {

			rgb[j][i][0] = 150;
			rgb[j][i][1] = 000;
			rgb[j][i][2] = 255;

		}
	}


	
	/*
	for (int j = 0; j < width; j++) {
		rgb[j][0][0] = (rand() % 50) + 205;
		rgb[j][0][1] = (rand() % 50) + 205;
		rgb[j][0][2] = 0;
	}


	for (int i = 1; i < height; i++) {
		for (int j = 0; j < width; j++) {
			//
			rgb[j][i][0] = (rgb[j - 1][i][0] + rgb[j + 1][i][0] + rgb[j - 1][i - 1][0] + rgb[j + 1][i - 1][0] + rgb[j][i - 1][0]) / 5;
			if (rand() % 2 == 1) { rgb[j][i][0] = rgb[j][i][0] - 4; }
			//
			rgb[j][i][1] = (rgb[j - 1][i][1] + rgb[j + 1][i][1] + rgb[j - 1][i - 1][1] + rgb[j + 1][i - 1][1] + rgb[j][i - 1][1]) / 5;
			if (rand() % 2 == 1) { rgb[j][i][1] = rgb[j][i][1] - 8; }
			//
			rgb[j][i][2] = 0;
			//
		}
	}
		*/



	/*
	x = rand() % 230;
	y = rand() % 400;

	r = (float)((rand() % 9)) / 8;
	g = (float)((rand() % 9)) / 8;
	b = (float)((rand() % 9)) / 8;
	*/
	glutPostRedisplay();
}
void display(void)
{
	glDrawBuffer(GL_UNSIGNED_INT);
	glDrawBuffer(CREATBuffer);
	glRasterPos2i(0, 0);
	glDrawPixels(width, height, GL_UNSIGNED_INT, GL_UNSIGNED_INT, rgb);
	
	glutSwapBuffers();
	glutSwapBuffers();
	glutSwapBuffers();


	/*
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 230.0, 0.0, 400.0);

	glColor3f(r, g, b);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();

	glFlush();
	*/
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);



	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Randomly generated points");
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMainLoop();
}







