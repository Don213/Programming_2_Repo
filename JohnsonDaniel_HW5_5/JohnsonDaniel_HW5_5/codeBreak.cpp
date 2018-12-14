// Modified code breaking program
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <thread>
#include <stdlib.h>
/*
using std::cout;
using std::cin;
using std::endl;
*/
using namespace std;














// This is the secret key, much larger than the previous assignment
const int KEY = 399999999;

// This is the function that was used to encrypt a message.
// It assumes the message
// to encrypt has length in chars that is a multiple of 4.  This is convenient
// because it takes 4 chars to make up one 32 bit int.  So we end up with one
// int per 4 characters. The resulting ints are added into the encrypted
// array.  We assume the encrypted array is big enough to hold the data.
void encryptMessage(char *plaintext, int secretKey, int encrypted[], int &size)
{
	int len = strlen(plaintext);
	int *ptrInt = (int *)plaintext;
	size = 0;
	for (int i = 0; i < len / 4; i++) // Assumes 1 int per 4 char
	{
		encrypted[size++] = (*ptrInt) + (secretKey * secretKey * secretKey);
		ptrInt++;
	}
}

// This function takes a pointer to an array of ints, the size of the array,
// and a (potential) secret key.  It decrypts the message by:
// 1) Looping through each integer
//   2) Subtracting off the secret key cubed
//   3) Outputting the 4 chars that make up the integer.  It does this by
//      typecasting a char pointer to the int, then outputting *p and then moving on
//      to the next three chars (i.e. pChar[0], pChar[1], pChar[2] and pChar[3]
// We assume the decrypted array is big enough to hold the data.
void decryptMessage(int *encrypted, int size, int secretKey, char *decrypted)
{
	char *pChar;
	//cout << "Trying key=" << secretKey << " ";
	for (int i = 0; i < size; i++)
	{
		int num = encrypted[i];
		num -= (secretKey * secretKey * secretKey);
		pChar = (char *)&num;  // Point to the integer as if it is an array of 4 chars
		for (int j = 0; j < 4; j++)
		{
			*decrypted = pChar[j];
			decrypted++;
		}
	}
	*decrypted = '\0';
}


int main()
{
	char plaintext[] = "Attack at dawn!!";
	int encrypted[20];  // Big enough to hold encrypted array of numbers
	int size;           // Number of entries in the encrypted array
	char decrypted[17]; // Big enough to hold plaintext + \0
	int choice;

	// Encrypt our sample message
	encryptMessage(plaintext, KEY, encrypted, size);

	/* Main Menu */
	do
	{
		cout << endl;
		cout << "Decryption and Random Stuff Demo" << endl;
		cout << endl;
		cout << "Select an option:" << endl;
		cout << "1. Print encrypted data for '" << plaintext << "'" << endl;
		cout << "2. Print holiday greeting" << endl;
		cout << "3. Decrypt by brute force" << endl;
		cout << "4. Quit program" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "The encrypted data is: " << endl;
			for (int i = 0; i < size; i++)
				cout << encrypted[i] << " ";
			cout << endl;
			break;
		case 2:
			cout << "Happy holidays!" << endl;
			break;
		case 3:
			std::thread t1{[&](){ 
				cout << "Trying all possible keys..." << endl;
				for (int i = 1; i < INT_MAX; i++)
				{
					decryptMessage(encrypted, size, i, decrypted);
					if (strstr(decrypted, "Attack") != NULL)
					{
						cout << "Found " << decrypted <<
						" with key = " << i << endl;
						break;
					}
				}
			}};
			t1.detach();
			break;
		}
	} while (choice != 4);
}




