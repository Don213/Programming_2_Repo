#include <iostream>
#include <random>
#include <ctime>
using namespace std;

static const int MAX = 1000;

void swapValue(int & num1, int & num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}


void printArray(int a[], int length)
{
	cout << "The contents of this array are as follows: " << endl;
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << endl;
	}
}


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


void populateArray(int emptyArray[], int length)
{
	for (int i = 0; i < length; i++)
	{
		emptyArray[i] = (rand() % 1001);
	}
}


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
	int testingArray1[1000];
	int testingArray2[10000];
	int testingArray3[100000];
	int testingArray4[200000];

	//puts random values from 0-1000 in the arrays (includes 1000)
	populateArray(testingArray1, 1000);
	populateArray(testingArray2, 10000);
	populateArray(testingArray3, 100000);
	populateArray(testingArray4, 200000);



	///////////////////////

	//Tests all the times for sorting

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray1, 1000);
	tempTime2 = time(NULL);
	testTime1 = tempTime2 - tempTime1;
	
	tempTime1 = time(NULL);
	countSort(testingArray1, 1000);
	tempTime2 = time(NULL);
	testTime2 = tempTime2 - tempTime1;
	///////////////////////

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray2, 10000);
	tempTime2 = time(NULL);
	testTime3 = tempTime2 - tempTime1;

	tempTime1 = time(NULL);
	countSort(testingArray2, 10000);
	tempTime2 = time(NULL);
	testTime4 = tempTime2 - tempTime1;
	///////////////////////

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray3, 100000);
	tempTime2 = time(NULL);
	testTime5 = tempTime2 - tempTime1;

	tempTime1 = time(NULL);
	countSort(testingArray3, 100000);
	tempTime2 = time(NULL);
	testTime6 = tempTime2 - tempTime1;
	///////////////////////

	///////////////////////
	tempTime1 = time(NULL);
	bubbleSort(testingArray4, 200000);
	tempTime2 = time(NULL);
	testTime7 = tempTime2 - tempTime1;

	tempTime1 = time(NULL);
	countSort(testingArray4, 200000);
	tempTime2 = time(NULL);
	testTime8 = tempTime2 - tempTime1;
	///////////////////////

	

	printTimes(testTime1, testTime2, testTime3, testTime4, testTime5, testTime6, testTime7, testTime8);

	system("pause");
	return 0;
}








