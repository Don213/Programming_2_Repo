#pragma once
#include <string>
using std::string;

class Oval
{
private:
	string name;			  // A name associated with the oval
	int x, y, width, height;  // Specifies a bounding rectangle for the oval with x,y the upper left corner
public:
	Oval(string name, int x, int y, int width, int height);
	Oval();
	~Oval();
	void draw();			  // Draw oval in the bounding rectangle
	string getName();		  // Return shape's name
	int getX();				  // Retrieve position and size
	int getY();
	int getWidth();
	int getHeight();
	bool pointInShape(int pointX, int pointY);  // Returns true if pointX,pointY is inside the oval
};
