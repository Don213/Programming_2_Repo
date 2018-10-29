////////////////////////////////
//
// Daniel Johnson
// Assignment 3.4 (Class)
// 10/19/18
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This is the movie class. It allows setting of the 
// name of the movie and the MPAA rating of the movie.
//
// Some functions (get and set) are created but not used because it was not required.
//
// Movie Function defined in Movie.cpp
////////////////////////////////


#pragma once
#include <iostream>
#include <string>
#include <array>
using namespace std;



class Movie
{
private:
	string movieName;
	string MPAARating;
	void swapValue(Movie &a1, Movie &a2);
public:
	Movie();
	Movie(string mn, string mpaa);

	string getMovieName();
	void setMovieName(string mn);

	string getMPAARating();
	void setMPAARating(string mpaa);

	void sortMovieList(Movie a[], int aLength);
};



