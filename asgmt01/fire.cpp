#include <iostream>
#include <cstring>
#include "fire.h"

using namespace std;

const int		Fire::columnWidths[4] = { -1, -1, -1, -1 };

Fire::Fire(const District district, const char * const name,
	int latDeg, int latMin, int latSec, int longDeg, int longMin, int longSec) :
	district{district},
	latitude{Coordinate(latDeg, latMin, latSec)},
	longitude{Coordinate(longDeg, longMin, longSec)}
{
	// your code here, or in this constructor's initialization list
	char* test = strdup(name);
		//char *strdup(const char *s) -- The strdup() function returns a pointer to a new string which is a duplicate of the string s
		//link -- https://linux.die.net/man/3/strdup
		//Intended use:
			//Due to "name" being passed in as a "const char * const", it is hard to save the value of "name" into "this->name" (provided in fire.h) which is a "char*". So strdup() will duplicate the value of "name" and reeturn it in a "char*" form which can be saved in the private variable "this->name".
	strcpy(test, this->name);
	delete test;
}

Fire::Fire(const District district, const char * const name,
		   Coordinate latitude, Coordinate longitude) :
	district{district},
	latitude{latitude},
	longitude{longitude}
{
	// your code here, or in this constructor's initialization list
	char* test = strdup(name);
	strcpy(test, this->name);
	delete test;
}

Fire::~Fire()
{
	// your code here
}

void Fire::displayColumnHeadings(ostream& out)
{
	// your code here
	std::cout << "name                     district        longitude       latitude\n"
		  << "----------------------   -------------   -------------   -------------\n";
}

std::ostream& operator<<(std::ostream& out, District district)
{
	// your code here

	return out;
}

ostream& operator<<(ostream& out, Fire* fire)
{
	// your code here

	return out;
}
