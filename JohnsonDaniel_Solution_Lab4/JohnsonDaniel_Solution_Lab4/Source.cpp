#include <iostream>
using namespace std;

void selectionSort(int a[], int startIndex, int endIndex)
{
	// Base case or termination condition: quit if start and end are the same.
	// This would specify to sort only a single element, which is already sorted.
	if (startIndex == endIndex)
		return;

	int indexOfMin = startIndex;

	for (int i = startIndex; i <= endIndex; i++)
	{
		if (a[indexOfMin] > a[i])
		{
			swap(a[indexOfMin], a[i]);
		}
	}

	selectionSort(a, (startIndex + 1), endIndex);
}


void swap(int &x, int &y)
{
	int xTemp = x;
	int yTemp = y;


	x = yTemp;
	y = xTemp;
}




int main()
{

	int randomArray1[6] = { 4, 0, 2, 5, 1, 3 };

	int reallyRandomArray[12] = { 1, 2 ,32 ,54, 23, 1, 3, 5, 8, 12, 45, 12 };

	int randomArray2[10] = { 4, 0, 2, 5, 1, 3, 7, 9, 6, 8 };

	selectionSort(randomArray1, 0, 5);
	selectionSort(randomArray2, 0, 9);
	selectionSort(reallyRandomArray, 0, 11);

	cout << "First Array" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << randomArray1[i] << endl;
	}

	cout << endl << endl;

	cout << "Second Array" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << randomArray2[i] << endl;
	}

	cout << endl << endl;

	cout << "Really Random Array" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << reallyRandomArray[i] << endl;
	}

	system("pause");
}