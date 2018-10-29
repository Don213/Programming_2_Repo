////////////////////////////////
//
// Daniel Johnson
// Assignment 3.2
// 10/19/2018
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program decrypts a secret message with a random key.
//
// The part that checked every key is commented out to simplify the output 
// and only show the intended message with the correct key.
//
//
//
//
//
// The decription key is 211
// "If you can read this you solved the problem!"
//
////////////////////////////////
#include <iostream>
using namespace std;





//Was used for testing purposes.
/*
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
*/


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
}



int main()
{
	
	//Said to write a program that puts the encoded numbers into and array or ints.
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
	



	//////Goes through every key value
	/*
	for (int k = 0; k <= 255; k++)
	{
		cout << "Decryption Key:" << k << endl;
		decryptMessage(numSequence, 11, k);
		cout << endl << endl;
	}
	*/
	//////
	cout << "The decryption key is 211" << endl;
	decryptMessage(numSequence, 11, 211);
	cout << endl << endl;
	

	cout << "Please press enter to end the program." << endl << endl;
	cin.get();//pauses the program to look at input.
	
}