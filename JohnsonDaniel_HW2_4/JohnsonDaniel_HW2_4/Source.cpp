////////////////////////////////
//
// Daniel Johnson
// HW2.4
// 9/27/18
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program creates a maze from recursion techniques. It starts with a full box of X's and then
// digs them out until it cannot anymore with the guidelines given.
//
//
//
////////////////////////////////



#include <iostream>
#include <ctime>
using namespace std;

int static const WIDTH = 25, HEIGHT = 25;


//prints maze out
void printMaze(char maze[][WIDTH])
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			cout << maze[y][x];
		}
		cout << endl;
	}
}



//intitializes all X's in the maze as digging preparation 
void initializeMazeOutline(char maze[][WIDTH])
{
	//Creates a block of X's to dig through
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			maze[i][j] = 'X';
		}
	}

	maze[1][1] = ' ';
}

//Creates a random array with numbers 1-4
void initializeRandomArray(int randArray[])
{
	int randVar;
	randArray[0] = (rand() % 4) + 1;

	do
	{
		randVar = (rand() % 4) + 1;
		randArray[1] = randVar;
	} while (randVar == randArray[0]);
	do
	{
		randVar = (rand() % 4) + 1;
		randArray[2] = randVar;
	} while (randVar == randArray[0] || randVar == randArray[1]);
	do
	{
		randVar = (rand() % 4) + 1;
		randArray[3] = randVar;
	} while (randVar == randArray[0] || randVar == randArray[1] || randVar == randArray[2]);

}



//digs a tunnel through a maze that is all X's
void digTunnel(char maze[][WIDTH], int & curX, int & curY)
{
	//random array for directions
	int randArray[4];
	initializeRandomArray(randArray);

	//checks to see if the maze is unable to be dugout anymore
	if ((curY + 2 >= WIDTH || maze[curY + 2][curX] == ' ')
		&& (curY - 2 >= WIDTH || maze[curY - 2][curX] == ' ')
		&& (curX - 2 >= HEIGHT || maze[curY][curX - 2] == ' ')
		&& (curX + 2 >= HEIGHT || maze[curY][curX + 2] == ' '))
	{
		cout << "The maze is done" << endl;
		return;
	}


	//loop to go through the 4 random values symbolizing up, down, left, and right
	for (int i = 0; i < 4; i++)
	{
		switch (randArray[i])
		{

		case 1:
			if (curY - 2 >= WIDTH || curY - 2 <= 0 || maze[curY - 2][curX] == ' ')
			{
				break;
			}
			else
			{
				for (int i = 1; i < 3; i++)
				{
					maze[(curY - i)][curX] = ' ';
				}
				curY = curY - 2;
				//printMaze(maze);
				return digTunnel(maze, curX, curY);
			}
			break;

		case 2:
			if (curY + 2 >= WIDTH || maze[curY + 2][curX] == ' ')
			{
				break;
			}
			else
			{
				for (int i = 1; i < 3; i++)
				{
					maze[(curY + i)][curX] = ' ';
				}
				curY = curY + 2;
				//printMaze(maze);
				return digTunnel(maze, curX, curY);
			}
			break;

		case 3:
			if (curX + 2 >= HEIGHT || maze[curY][curX + 2] == ' ')
			{
				break;
			}
			else
			{
				for (int i = 1; i < 3; i++)
				{
					maze[curY][(curX + i)] = ' ';
				}
				curX = curX + 2;
				//printMaze(maze);
				return digTunnel(maze, curX, curY);
			}
			break;

		case 4:
			if (curX - 2 >= HEIGHT || curX - 2 <= 0 || maze[curY][curX - 2] == ' ')
			{
				break;
			}
			else
			{
				for (int i = 1; i < 3; i++)
				{
					maze[curY][(curX - i)] = ' ';
				}
				curX = curX - 2;
				//printMaze(maze);
				return digTunnel(maze, curX, curY);
			}
			break;

		default:
			return;

		}

	}

}




int main()
{
	srand(time(NULL));//seeds random
	char maze[HEIGHT][WIDTH];


	//starting location for the maze
	int startX = 1;
	int startY = 1;



	//initializes X  maze, digs the maze out, and prints the maze
	initializeMazeOutline(maze);
	digTunnel(maze, startY, startX);
	printMaze(maze);


	system("pause");

}