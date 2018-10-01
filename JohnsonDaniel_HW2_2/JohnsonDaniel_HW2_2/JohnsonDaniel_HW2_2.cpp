////////////////////////////////
//
// Daniel Johnson
// Assignment HW2.2
// 9/27/2018
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program sorts out arrays and compares the time it takes for them.
// The two specific algorithms are bubbleSort and countSort.
//
//
////////////////////////////////



#include <iostream>
#include <random>
#include <ctime>
using namespace std;

static const int MAX = 1000;//The maximum value of an integer in an array

//swaps the values of two variables
void swapValue(int & num1, int & num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

//prints an array out
void printArray(int a[], int length)
{
	cout << "The contents of this array are as follows: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << endl;
	}
}

//Prints the times out for each array: 1,000 - 10,000 - 100,000 - 200,000
void printTimes(int testTime1, int testTime2, int testTime3, int testTime4, int testTime5, int testTime6, int testTime7, int testTime8)
{
	cout << "The time using bubbleSort() for the 1,000 length array is: " << testTime1 << endl;
	cout << "The time using countSort() for the 1,000 length array is: " << testTime2 << endl;

	cout << "The time using bubbleSort() for the 10,000 length array is: " << testTime3 << endl;
	cout << "The time using countSort() for the 10,000 length array is: " << testTime4 << endl;

	cout << "The time using bubbleSort() for the 100,000 length array is: " << testTime5 << endl;
	cout << "The time using countSort() for the 100,000 length array is: " << testTime6 << endl;

	cout << "The time using bubbleSort() for the 200,000 length array is: " << testTime7 << endl;
	cout << "The time using countSort() for the 200,000 length array is: " << testTime8 << endl;
}

//Populates arrays with random numbers
void populateArray(int emptyArray[], int length)
{
	for (int i = 0; i < length; i++)
	{
		emptyArray[i] = (rand() % 1001);
	}
}

//bubbleSort implementation
void bubbleSort(int mixedArray[], int length)
{
	length = length - 1;


	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length - i; j++)
		{
			if (mixedArray[j] > mixedArray[j + 1])
			{
				swapValue(mixedArray[j], mixedArray[j + 1]);
			}
		}
	}
}

//countSort implementation
void countSort(int mixedArray[], int length)
{
	int maxArray[MAX+1] = { 0 };


	for (int i = 0; i < length; i++)
	{
		maxArray[(mixedArray[i])]++;
	}

	for (int i = 0, j = 0; i <= MAX+1; i++)
	{
		while (maxArray[i] > 0)
		{
			mixedArray[j] = i;
			maxArray[i]--;
			j++;
		}
	}
}


int main()
{
	srand(time(NULL));

	//Creates variables to hold the time in seconds it takes to sort for each array with bubbleSort and countSort
	int tempTime1, tempTime2, testTime1, testTime2, testTime3, testTime4, testTime5, testTime6, testTime7, testTime8;
	

	//Creates testing arrays
	//My computer did not handle 500,000 very well so I lowered the array amount to 200,000 instead
	int testingArray1[1000];
	int testingArray2[10000];
	int testingArray3[100000];
	int testingArray4[200000];
	int testingArray5[1000];
	int testingArray6[10000];
	int testingArray7[100000];
	int testingArray8[200000];

	//puts random values from 0-1000 in the arrays (includes 1000)
	populateArray(testingArray1, 1000);
	populateArray(testingArray2, 10000);
	populateArray(testingArray3, 100000);
	populateArray(testingArray4, 200000);
	populateArray(testingArray5, 1000);
	populateArray(testingArray6, 10000);
	populateArray(testingArray7, 100000);
	populateArray(testingArray8, 200000);



	///////////////////////

	//Tests all the times for sorting

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray1, 1000);
	tempTime2 = time(NULL);
	testTime1 = tempTime2 - tempTime1;
	
	tempTime1 = time(NULL);
	countSort(testingArray5, 1000);
	tempTime2 = time(NULL);
	testTime2 = tempTime2 - tempTime1;
	///////////////////////

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray2, 10000);
	tempTime2 = time(NULL);
	testTime3 = tempTime2 - tempTime1;

	tempTime1 = time(NULL);
	countSort(testingArray6, 10000);
	tempTime2 = time(NULL);
	testTime4 = tempTime2 - tempTime1;
	///////////////////////

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray3, 100000);
	tempTime2 = time(NULL);
	testTime5 = tempTime2 - tempTime1;

	tempTime1 = time(NULL);
	countSort(testingArray7, 100000);
	tempTime2 = time(NULL);
	testTime6 = tempTime2 - tempTime1;
	///////////////////////

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray4, 200000);
	tempTime2 = time(NULL);
	testTime7 = tempTime2 - tempTime1;

	tempTime1 = time(NULL);
	countSort(testingArray8, 200000);
	tempTime2 = time(NULL);
	testTime8 = tempTime2 - tempTime1;
	///////////////////////
	
	
	//prints times out for the amount of seconds it took to sort the arrays.
	printTimes(testTime1, testTime2, testTime3, testTime4, testTime5, testTime6, testTime7, testTime8);
	

	//Debugging statement
	//printArray(testingArray5, 1000);

	system("pause");
	return 0;
}








