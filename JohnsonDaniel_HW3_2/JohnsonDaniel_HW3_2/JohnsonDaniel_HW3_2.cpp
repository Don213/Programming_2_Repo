#include <iostream>
using namespace std;

//The decription key is 211
//"If you can read this you solved the problem!"




/*
void ptrArrayIncrease(char *&p, int originalLength, int newLength)
{

	// Allocate new array of 10 ints and make p point to it
	char *p2 = new char[newLength];
	// Free memory allocated to old array

	for (int i = 0; i < originalLength; i++)
	{
		p2[i] = p[i];
	}

	delete p;
	// Set pointer to new array
	p = p2;
}
*/















void encryptMessage(char *plaintext, int secretKey)
{
	int len = strlen(plaintext);
	int *ptrInt = (int *)plaintext;
	for (int i = 0; i < len / 4; i++) // Assumes 1 int per 4 char
	{
		cout << (*ptrInt) + (secretKey * secretKey * secretKey) << endl;
		ptrInt++;
	}
}



void decryptMessage(int *numSequence, int length, int secretKey)
{
	int *tempIntPtr = new int[length];
	for (int i = 0; i < length; i++)
	{
		tempIntPtr[i] = numSequence[i] - (secretKey * secretKey * secretKey);
	}

	char * ptrChar = (char *)(tempIntPtr);

	for (int i = 0; i < length * 4; i++)
	{
		cout << ptrChar[i];
	}
	delete tempIntPtr;
	//delete numSequence;
}



int main()
{
	
	int numSequence [11] = {
		2041560404,
		1672465530,
		1924121964,
		552843376,
		1945681791,
		1979633707,
		1828637227,
		552844417,
		552910719,
		1660864891,
		570211447
	};
	
	//int numSequence[3] = {1819044872,1750345519,560298277};

	/*
	int numSequence[25] = {
		1819044872,
		1750345519,
		560298277,
		544822240,
		1701668910,
		544436192,
		1768843268,
		1629516581,
		1948281646,
		544436264,
		1629518377,
		1936030432,
		1735290932,
		1920236000,
		543651113,
		544372262,
		543518516,
		1919118387,
		1830845221,
		1634957861,
		1679846439,
		2037541413,
		1869183792,
		1969628974,
		1769237038
	};
	/*
	int *numArray = new int[25];
	
	for (int i = 0; i < 25; i++)
	{
		*numArray = numSequence[i];
		numArray++;
	}
	*/
	/*
	char secretMessage[103] = "Hello There! My name is Daniel and this is a testing string for the secret message decryption function";
	encryptMessage(secretMessage, 12);
	*/

	
	for (int k = 0; k <= 255; k++)
	{
		cout << "Decryption Key:" << k << endl;
		decryptMessage(numSequence, 11, k);
		cout << endl << endl;
	}
	
	
	//decryptMessage(numSequence, 25, 12);
	

	
	
	
	
	
	
	cin.get();
}