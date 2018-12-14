#include <iostream>
#include <thread>

using namespace std;

int counter;

void increment()
{
	counter++;
}

int main()
{
	counter = 0;
	cout << "The value in counter is : " << counter << endl;

	thread tarr[30000];
	for (int i = 0; i < 30000; i++)
		tarr[i] = thread(increment);
	for (int i = 0; i < 30000; i++)
		tarr[i].join();

	cout << "After running 30,000 threads ";
	cout << "the value in counter is : " << counter << endl;
	cin.get();
	return 0;
}