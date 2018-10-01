#include<iostream>
#include<cstring>
#include<fstream>
#include<string>

static const int ARRAY_SIZE = 15;

using namespace std;



void reinitializeArray(char a[ARRAY_SIZE])
{
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		a[i] = 0;
	}
}

//Vowels: A,E,I,O,U
bool isVowel(char c)
{
	c = tolower(c);
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int amountConsecutive(char c[ARRAY_SIZE])
{
	int tempConsecutive = 0;
	int maxConsecutive = 0;
	int count = 0;


	do
	{
		if (c[count] != 0)
		{
			//Checks consecutivity and adds 1
			if (isVowel(c[count]) && isVowel(c[count - 1]))
			{
				tempConsecutive++;
			}
			//checks consecutivity and makes makes temp variable 1 if there was no vowel before.
			else if (isVowel(c[count]))
			{
				tempConsecutive = 1;
			}
			//checks to see if the tempConsecutive vowel count is higher than the maxConsecutive vowel count
			else if (!isVowel(c[count]))
			{
				if (tempConsecutive > maxConsecutive)
				{
					maxConsecutive = tempConsecutive;
				}
			}
		}

		count++;

	} while (c[count] != '0');

	return maxConsecutive;
}
/*
void makeCString(char c[ARRAY_SIZE], ifstream & in)
{
	in >> c;
}
*/

int main()
{
	ifstream inStream;
	inStream.open("C:\\Users\\docto\\Desktop\\C++ Repo\\Programming_2_Repo\\JohnsonDaniel_Lab5\\bigwords.txt");
	if (inStream.fail())
	{
		cout << "failed" << endl;
		cout << "Press enter to exit the program";
		cin.get();
		return 1;
	}

	//sttores amount of largest consecutie vowels
	int maxVowel = 0;


	//stores c string with most vowels
	char mostV[15];
	reinitializeArray(mostV);
	//stores current c string
	char tempA[15];
	reinitializeArray(tempA);




	while (!(inStream.eof()))
	{
		reinitializeArray(tempA);
		inStream >> tempA;
		//checks to see if tempA has more consecutive vowels than variable holding current highest
		if (amountConsecutive(tempA) > amountConsecutive(mostV))
		{
			//sets amount of max vowels
			maxVowel = amountConsecutive(tempA);
			//sets highest vowel in c string
			for (int i = 0; i < ARRAY_SIZE; i++)
			{
				mostV[i] = tempA[i];
			}


		}
	}



	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << mostV[i];
	}
	cout << endl;
	cout << "This string has the most consecutive vowels" << endl;
	cout << "Consecutive Vowels: " << maxVowel << endl;
	

	//Pauses program
	cout << "Press enter to end the program.";
	cin.get();

}