// CSCE A211
// Graphics Framework by Matthew Devins
// This code demonstrates how to load a png image,
// display, and process it using the lodepng library
// and a wrapper pngImage class.

#include "GL/glut.h"
#include "GL/gl.h"
#include "GL/glu.h"

#include "lodepng.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <vector>
#include "pngImage.h"


using namespace std;

void init();
void display();


void *font = GLUT_BITMAP_TIMES_ROMAN_24;//GLUT_STROKE_ROMAN;
const int WIDTH = 768;
const int HEIGHT = 576;

static int screenx = 0;
static int screeny = 0;


PngImage image1;  
PngImage image2;
PngImage image3;


int main(int argc, char** argv)
{
	srand(time(NULL)); 
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_MULTISAMPLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Image processing demo");

	init();

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0, 1.0, 1.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(screenx, screenx + WIDTH, screeny + HEIGHT, screeny);
	
	char picTemp1[] = "T1.png";
	char* pic1 = picTemp1;
	
	char picTemp2[] = "T2.png";
	char* pic2 = picTemp2;

	char picTemp3[] = "T3.png";
	char* pic3 = picTemp3;

	image1.loadImage(pic1);
	image2.loadImage(pic2);
	image3.loadImage(pic3);
}

/* For this lab you only need to work in this display function */
void display()
{
	// Clear the screen
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (int j = 0; j < image1.getHeight(); j++)
		for (int i = 0; i < image1.getWidth(); i++)		
		{

			//Finds all rgb values and determines the median value of 3 choices
			int r1, g1, b1, r2, g2, b2, r3, g3, b3, mr, mg, mb;
			image1.getRGB(i, j, r1, g1, b1);
			image2.getRGB(i, j, r2, g2, b2);
			image3.getRGB(i, j, r3, g3, b3);
			

			//Considers all choices for median value and declares it as mr, mg, and mb
			if (r1 >= r2 && r1 <= r3 || r1 >= r3 && r1 <= r2)
				mr = r1;
			if (r2 >= r1 && r2 <= r3 || r2 >= r3 && r2 <= r1)
				mr = r2;
			if (r3 >= r2 && r3 <= r1 || r3 >= r1 && r3 <= r2)
				mr = r3;


			if (g1 >= g2 && g1 <= g3 || g1 >= g3 && g1 <= g2)
				mg = g1;
			if (g2 >= g1 && g2 <= g3 || g2 >= g3 && g2 <= g1)
				mg = g2;
			if (g3 >= g2 && g3 <= g1 || g3 >= g1 && g3 <= g2)
				mg = g3;


			if (b1 >= b2 && b1 <= b3 || b1 >= b3 && b1 <= b2)
				mb = b1;
			if (b2 >= b1 && b2 <= b3 || b2 >= b3 && b2 <= b1)
				mb = b2;
			if (b3 >= b2 && b3 <= b1 || b3 >= b1 && b3 <= b2)
				mb = b3;














			glColor3f((float)mr / 255, (float)mg / 255, (float)mb / 255);
			glVertex2f(i, j);
		}
	glEnd();
	
	glutSwapBuffers();
	glFlush();

	return;
}

