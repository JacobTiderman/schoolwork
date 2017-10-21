#include <iostream>
#include "coordinate.h"

#include<iomanip> // -- Needed to include for setw(int)

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
return out << setw(4) << coord.degrees << coord.degreeChar 
	   << " "
	   << setw(3) << coord.minutes << "\'" 
	   << " "
	   << setw(4) << coord.secondsTenths << "\"";
}
