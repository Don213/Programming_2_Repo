//Movie functions are defined here
#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;

//swaps movie object values
void Movie::swapValue(Movie &a1, Movie &a2)
{
	Movie temp = a1;
	a1 = a2;
	a2 = temp;
}






//default constructor created for movie class
Movie::Movie()
{
	movieName = "undefined";
	MPAARating = "undefined";
}
//constructor that sets the variables of the movie class from given arguments
Movie::Movie(string mn, string mpaa)
{
	movieName = mn;
	MPAARating = mpaa;
}
//returns the movie name
string Movie::getMovieName()
{
	return movieName;
}
//sets the movie name
void Movie::setMovieName(string mn)
{
	movieName = mn;
}
//returns the MPAARating
string Movie::getMPAARating()
{
	return MPAARating;
}
//sets the MPAARating
void Movie::setMPAARating(string mpaa)
{
	movieName = mpaa;
}


//sorts a list of movie objects with a given length and prints them out.
void Movie::sortMovieList(Movie a[], int aLength)
{
	int temp1, temp2;


	for (int i = 0; i < aLength; i++)
	{
		for (int j = 0; j < (aLength - 1) - i; j++)
		{
			temp1 = (int)toupper(a[j].getMovieName()[0]);
			temp2 = (int)toupper(a[j + 1].getMovieName()[0]);

			if (temp1 > temp2)
			{
				swapValue(a[j], a[j + 1]);
			}
		}
	}


	cout << "The sorted list is as follows: " << endl << endl;

	for (int i = 0; i < aLength; i++)
	{
		cout << a[i].getMovieName() << ", " << a[i].getMPAARating() << endl;

	}



}
