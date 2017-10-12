#include <iostream>
#include "coordinate.h"

using namespace std;

Coordinate::Coordinate(int degrees, int minutes, int secondsTenths) : 
	degrees{degrees},
	minutes{minutes},
	secondsTenths{secondsTenths}
{
	// your code here, or in this constructor's initialization list
	// NO CODE - JACOB
}

Coordinate::Coordinate(void) :
	degrees{0},
	minutes{0},
	secondsTenths{0}
{
	// your code here, or in this constructor's initialization list
	// NO CODE - JACOB
}

Coordinate::~Coordinate(void)
{
	// your code here
	// NO CODE - JACOB
}

ostream& operator<<(ostream& out, Coordinate& coord)
{
	// your code here
	return out << coord.degrees << coord.degreeChar << " " << coord.minutes << "\' " << coord.secondsTenths << "\"";
}
