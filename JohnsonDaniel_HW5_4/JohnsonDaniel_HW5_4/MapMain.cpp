#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;


map<string, float> mappy;


// Count how many times variable "word" has been seen.  Each word
// is stored in words[] and the number of times it has been added
// is stored in wordCount[].
void addWord(string word)
{

	map<string, float>::iterator it = mappy.begin();
	bool wasContained = false;
	for (; it != mappy.end(); it++)
	{
		if (word == it->first)
		{
			mappy.at(word) = (it->second + 1);
			wasContained = true;
			break;
		}
	}
	if (!wasContained) {
		mappy[word] = (1);
	}


}







int main()
{

	string paragraph = "Here is a story about a man who had too much power, and a man who took too much, but don't worry; I'm not going political on you. The man who had the power was named James Kidder and the other was his banker.";







	// Strip out anything that isn't a letter
	string stripped = "";
	for (int i = 0; i < paragraph.length(); i++)
		if (isalpha(paragraph[i]))
			stripped += tolower(paragraph[i]);
		else if (paragraph[i] == ' ')
			stripped += " ";


	// Get each word
	std::stringstream ss(stripped);
	string token;
	while (getline(ss, token, ' ')) {
		// token set to each word in the paragraph
		// cout << token << endl;
		addWord(token);
	}



	map<string, float>::iterator it = mappy.begin();
	for (; it != mappy.end(); it++) {
		cout << it->first << " appeared " << it->second << " times." << endl;
	}


	cin.get();
	return 0;
}