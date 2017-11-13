#include "date.h"

using namespace std;

Date::Date(Month month, int day, int year) :
	this->month{month},
	this->day{day},
	this->year{year}
{
}

Date::Date() :
	this->month{Month::INVALID},
	this->day{0},
	this->year{0}
{
}

Date::~Date(void)
{
	//Not needed
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d.month << " " << d.day << ", " << year;
	return out;
}
