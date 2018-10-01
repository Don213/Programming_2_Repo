////////////////////////////////
//
// Daniel Johnson
// Assignment HW2.3
// 9/27/2018
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program will take a maze and find a path to the end recursively while spitting
// out the instructions/moves for how to get there after it finds the solution.
//
//
////////////////////////////////




#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const int WIDTH = 20;
const int HEIGHT = 20;

// Function prototypes
void printMaze(char maze[][WIDTH], int curx, int cury);
bool validMove(char maze[][WIDTH], bool visited[][WIDTH], int newX, int newY);
bool move(char maze[][WIDTH], bool visited[][WIDTH], int &curX, int &curY, int newX, int newY);




// Return true or false if moving to the specified coordinate is valid
// Return false if we have been to this cell already
bool validMove(char maze[][WIDTH], bool visited[][WIDTH], int newX, int newY)
{
 // Check for going off the maze edges
 if (newX < 0 || newX >= WIDTH)
	return false;
 if (newY < 0 || newY >= HEIGHT)
	return false;
 // Check if target is a wall
 if (maze[newY][newX]=='X')
	return false;
 // Check if visited
 if (visited[newY][newX])
	return false;
 return true;
}

// Make the move on the maze to move to a new coordinate
// I passed curX and curY by reference so they are changed to
// the new coordinates.  Here we assume the move coordinates are valid.
// This returns true if we move onto the exit, false otherwise.
// Also update the visited array.
bool move(char maze[][WIDTH], bool visited[][WIDTH], int &curX, int &curY, int newX, int newY)
{
  bool foundExit = false;
  if (maze[newY][newX]=='E') 	// Check for exit
	foundExit = true;
  curX = newX;			// Update location
  curY = newY;
  visited[curY][curX] = true;
 
  return foundExit;
}

// Display the maze in ASCII
void printMaze(char maze[][WIDTH], int curx, int cury)
{
  for (int y=0; y < HEIGHT;y++)
  {
    for (int x=0; x < WIDTH; x++)
    {
	if ((x==curx) && (y==cury))
		cout << "@";
	else
		cout << maze[y][x];
    }
    cout << endl;
  }
}

// Recursively search from x,y until we find the exit
bool search(char maze[][WIDTH], bool visited[][WIDTH], int x, int y, int & counter, int xCoordArray[1000], int yCoordArray[1000])
{
   bool foundExit = false;

   if (maze[y][x]=='E')
	return true;
   visited[y][x]=true;

   if (validMove(maze,visited,x,y-1))
	foundExit = search(maze,visited,x,y-1, counter, xCoordArray, yCoordArray);

   if (!foundExit && (validMove(maze,visited,x,y+1)))
	foundExit = search(maze,visited,x,y+1, counter, xCoordArray, yCoordArray);

   if (!foundExit && (validMove(maze,visited,x-1,y)))
	foundExit = search(maze,visited,x-1,y, counter, xCoordArray, yCoordArray);

   if (!foundExit && (validMove(maze,visited,x+1,y)))
	foundExit = search(maze,visited,x+1,y, counter, xCoordArray, yCoordArray);

   if (foundExit)
   { 

	xCoordArray[counter] = x;
	yCoordArray[counter] = y;

	counter++;
	//printMaze(maze,x,y);
	//cout << endl;
	return true;
   }
   return false;
}






//prints out the moves in the correct order.
void printCorrectOrder(char maze[][WIDTH], int xCoordArray[1000], int yCoordArray[1000])
{
	for (int i = 999; i >= 0; i--)
	{
		if (xCoordArray[i] > -1)
		{
			printMaze(maze, xCoordArray[i], yCoordArray[i]);
		}
	}
}













int main()
{
 char maze[HEIGHT][WIDTH] = {
        {'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'},
        {'X',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ',' ','X'},
        {'X',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ',' ','X'},
        {'X',' ','X','X','X',' ','X',' ',' ','X','X',' ','X','X','X',' ','X',' ',' ','X'},
        {'X',' ',' ',' ','X',' ','X',' ','X','X','X',' ',' ',' ','X',' ','X',' ',' ','X'},
        {'X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ',' ',' ','X','X'},
        {'X',' ','X','X','X',' ',' ',' ','X',' ',' ',' ','X','X','X',' ',' ',' ','X','X'},
        {'X',' ','X','X','X',' ','X','X','X',' ',' ',' ','X','X','X',' ','X','X','X','X'},
        {'X',' ',' ','X','X',' ','X','X',' ',' ',' ',' ',' ','X','X',' ','X','X',' ','X'},
        {'X',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ','X',' ',' ','X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ','X','X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		{'X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ','X'},
		{'X',' ','X','X',' ',' ',' ',' ',' ',' ','X',' ','X','X',' ',' ',' ',' ',' ','X'},
		{'X',' ','X','X','X',' ','X',' ',' ','X','X',' ','X','X','X',' ','X',' ',' ','X'},
		{'X',' ',' ',' ','X',' ','X',' ',' ',' ',' ',' ',' ',' ','X',' ','X',' ',' ','X'},
		{'X',' ',' ',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ',' ',' ','X','X'},
		{'X',' ','X','X','X',' ',' ',' ',' ',' ',' ',' ','X','X','X',' ',' ',' ',' ','X'},
		{'X',' ','X',' ',' ',' ','X',' ',' ',' ',' ',' ','X',' ',' ',' ','X',' ',' ','X'},
		{'X',' ',' ',' ',' ',' ','X',' ',' ',' ',' ',' ',' ',' ',' ',' ','X',' ',' ','X'},
		{'X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X','X'}
 };
 bool visited[HEIGHT][WIDTH];

 //Moves are assumed to be under 1000
 //arrays will hold coordinates for reading back moves
 int xCoordArray[1000];
 int yCoordArray[1000];

 //initializes every element to -1 for comparison later
 for (int i = 0; i < 1000; i++)
 {
	 xCoordArray[i] = -1;
	 yCoordArray[i] = -1;
 }




 int counterVar = 0;//variable that will help hold places for coordinates to read back moves


 bool foundExit = false;
 srand(time(NULL));

 int x, y, ex, ey; //starting location variables & exit location variables

 do
 {
	 x = rand() % 21;
	 y = rand() % 21;
 } while (maze[y][x] == 'X');
 //Creates a new starting location every time

 do
 {
	 ex = rand() % 21;
	 ey = rand() % 21;
 } while (maze[ey][ex] == 'X');
 maze[ey][ex] = 'E';
//Creates a new exit location every time



 // Initialize visited locations to false
 for (int x = 0; x < WIDTH; x++)
 {
	 for (int y = 0; y < HEIGHT; y++)
	 {
		 visited[y][x] = false;
	 }
 }

 visited[y][x] = true;



 //runs the sorting algorithm
 cout << search(maze, visited, x, y, counterVar, xCoordArray, yCoordArray) << endl << endl;


 //prints out the reverse order the original code does.
 printCorrectOrder(maze, xCoordArray, yCoordArray);
 printMaze(maze, ex, ey);//prints last direction
 cout << "Please press enter to end the program.";
 cin.get();
}




