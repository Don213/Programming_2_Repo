#pragma once
#include <string>
using std::string;

class Rectangle
{
private:
	string name;			  // A name associated with the rectangle
	int x, y, width, height;  // Specifies a bounding rectangle for the rectangle with x,y the upper left corner
public:
	Rectangle(string name, int x, int y, int width, int height);
	Rectangle();
	~Rectangle();
	void draw();			  // Draw rectangle in the bounding rectangle
	string getName();		  // Return shape's name
	int getX();				  // Retrieve position and size
	int getY();
	int getWidth();
	int getHeight();
	bool pointInShape(int pointX, int pointY);  // Returns true if pointX,pointY is inside the rect
};
