#include <iostream>
using namespace std;

void absoluteValue(int *ptrNum)
{
	if (!(*ptrNum == 0))
	{
		if (*ptrNum < 0)
		{
			*ptrNum = (*ptrNum * -1);
		}
	}
}

int main()
{
	int test1 = 24;
	int test2 = -24;

	int *tester1 = &test1;
	int *tester2 = &test2;

	absoluteValue(tester1);
	absoluteValue(tester2);


	cout << test1 << endl;
	cout << test2 << endl;
	cin.get();//pauses code
}