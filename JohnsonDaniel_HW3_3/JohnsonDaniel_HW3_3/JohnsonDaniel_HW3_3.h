#pragma once

#include <iostream>
#include <algorithm>
using namespace std;



class Month
{
private:
	int month;

public:
	Month();
	Month(int m);
	Month(string m);
	int getMonth();
	string getMonthString();
	Month getNextMonth();
};


Month::Month()
{
	month = 1;
}
Month::Month(int m)
{
	month = m;
}
Month::Month(string m)
{
	transform(m.begin(), m.end(), m.begin(), ::tolower);
	if (m == "jan")
	{
		month = 1;
	}
	else if (m == "feb")
	{
		month = 2;
	}
	else if (m == "mar")
	{
		month = 3;
	}
	else if (m == "apr")
	{
		month = 4;
	}
	else if (m == "may")
	{
		month = 5;
	}
	else if (m == "jun")
	{
		month = 6;
	}
	else if (m == "jul")
	{
		month = 7;
	}
	else if (m == "aug")
	{
		month = 8;
	}
	else if (m == "sep")
	{
		month = 9;
	}
	else if (m == "oct")
	{
		month = 10;
	}
	else if (m == "nov")
	{
		month = 11;
	}
	else if (m == "dec")
	{
		month = 12;
	}
	else { cout << "An invalid month was given. The constructor will automatically set the month to 1." << endl; }
}

int Month::getMonth()
{
	return month;
}
string Month::getMonthString()
{
	switch (month)
	{
	case 1:
		return "Jan";
		break;
	case 2:
		return "Feb";
		break;
	case 3:
		return "Mar";
		break;
	case 4:
		return "Apr";
		break;
	case 5:
		return "May";
		break;
	case 6:
		return "Jun";
		break;
	case 7:
		return "Jul";
		break;
	case 8:
		return "Aug";
		break;
	case 9:
		return "Sep";
		break;
	case 10:
		return "Oct";
		break;
	case 11:
		return "Nov";
		break;
	case 12:
		return "Dec";
		break;
	}
}
Month Month::getNextMonth()
{
	if (month != 12)
	{
		return Month((month + 1));
	}
	return Month();
}




