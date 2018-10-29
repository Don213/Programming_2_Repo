////////////////////////////////
//
// Daniel Johnson
// Assignment 3.4 (Using class)
// 10/19/18
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program uses the Movie class I made to create and array of movie objects and then sorts
// and outputs the sorted list for the user to see.
//
////////////////////////////////




#include <iostream>
#include <string>
#include "Movie.h"
using namespace std;


int main()
{

	//object created to use function.
	Movie m1 = Movie();
	//



	Movie *movieA = new Movie[7];
	//array of movie objects
	Movie movieArray[7] =
	{
		Movie("Goosebumps 2: Haunted Halloween", "PG"),
		Movie("Halloween", "R"),
		Movie("Bohemian Rhapsody", "PG - 13"),
		Movie("The Grinch", "PG"),
		Movie("Ralph Breaks the Internet", "PG"),
		Movie("Anna and the Apocalypse", "R"),
		Movie("Fantastic Beasts : The Crimes of Grindelwald", "PG - 13")
	};

	//This was probably uneeded and the movieArray could be passed instead, but I did it anyways.
	for (int i = 0; i < 7; i++)
	{
		movieA[i] = movieArray[i];
	}

	m1.sortMovieList(movieA, 7);//sorts list of movies


	cout << endl << endl << "Please press enter to exit the program." << endl << endl;
	cin.get();//Pauses the program.
	

}