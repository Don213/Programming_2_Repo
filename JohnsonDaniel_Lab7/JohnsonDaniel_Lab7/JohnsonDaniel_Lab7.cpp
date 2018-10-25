#include <iostream>
#include <string>
using namespace std;

class Song 
{
	public: 
	string title;
	string artist;
	int songLength;
	 

	Song()
	{
		title = "Undefined";
		artist = "Undefined";
		songLength = 0;
	}

	Song(string t, string a, int l)
	{
		title = t;
		artist = a;
		songLength = l;
	}

	string getTitle()
	{
		return title;
	}
	void setTitle(string t)
	{
		title = t;
	}

	string getArtist()
	{
		return artist;
	}
	void setArtist(string a)
	{
		artist = a;
	}

	int getLength()
	{
		return songLength;
	}
	void setLength(int l)
	{
		songLength = l;
	}
};













































int main(int argc, char *argv[])
{
	// Creates an array of songs using the default constructor.
	// The default constructor sets the title and artist to "Undefined"
	// and the seconds to 0.
	Song songs[3];
	// Constructor setting the title, artist, and length in seconds
	Song s1("Lady Java", "Jenny Skavlan", 137);
	Song s2("Code Monkey", "Jonathan Coulton", 229);

	// Copy s1 to slot 0, s2 to slot 2, and default left at slot 1
	songs[0] = s1;
	songs[2] = s2;

	// Loop through each song and "play" them
	for (int i = 0; i < 3; i++)
	{
		cout << "Playing song " << songs[i].getTitle() <<
			" by " << songs[i].getArtist() <<
			" length: " << songs[i].getLength() / 60 <<
			" minutes, " << songs[i].getLength() % 60 <<
			" seconds." << endl;
	}
	cout << endl << endl;
	cout << "Please press enter to exit";
	cin.get();

	return 0;
}