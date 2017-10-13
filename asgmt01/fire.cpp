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
	strcpy(test, this->name);
	delete test;
	//latitude = Coordinate(latDeg, latMin, latSec);
	//longitude = Coordinate(longDeg, longMin, longSec);
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
