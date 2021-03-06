////////////////////////////////
//
// Daniel Johnson
// Assignment HW2.1
// 9/27/2018
//
////////////////////////////////


////////////////////////////////
//
// DESCRIPTION: This program will tell you how many pidgeys you can evolve with a certain number of candies.
// There are various examples demonstrated when the program is run.
//
////////////////////////////////






#include <iostream>
using namespace std;

static const int EVOLUTION_CANDY_NUMBER = 12;//sets the candy number for pidgey evolutions


//Evolves pidgeys with candies
int pidgey_evolution(int starting_candy)
{

	if (starting_candy / EVOLUTION_CANDY_NUMBER != 0)
	{
		int pidgey_amount = starting_candy / EVOLUTION_CANDY_NUMBER; //generates the amount of pidgeys evolved from current candy
		int leftover_candy = starting_candy % EVOLUTION_CANDY_NUMBER; //accounts for leftover candy
		leftover_candy = leftover_candy + 2 * pidgey_amount; //accounts for evolution candy and transfer candy
		return (pidgey_evolution(leftover_candy) + pidgey_amount);//returns add to form the amount of evolutions
	}
	else { return 0; }
}



int main()
{

	//pidgey_evolution(80);


	//tests the function with the same numbers in the homework examples
	cout << "You can evolve " << pidgey_evolution(80) << " pidgeys with 80 candy" << endl;
	cout << "You can evolve " << pidgey_evolution(140) << " pidgeys with 140 candy" << endl;
	cout << "You can evolve " << pidgey_evolution(230) << " pidgeys with 230 candy" << endl;
	cout << "You can evolve " << pidgey_evolution(300) << " pidgeys with 300 candy" << endl;
	cout << "You can evolve " << pidgey_evolution(6613) << " pidgeys with 6613 candy" << endl;
	cout << "Press enter to exit the program." << endl;
	cin.get();
	return 0;

}