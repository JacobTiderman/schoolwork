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
	out << "name                     district        longitude       latitude\n"
	    << "----------------------   -------------   -------------   -------------\n";
}

std::ostream& operator<<(std::ostream& out, District district)
{
	// your code here
	//Note: this is not for class Fire, this is for enum class District
	switch (district) {
	case District::Astoria: 
		out << "Astoria";
		break;
	case District::Columbia_City:
		out << "Columbia City";
		break;
	case District::Dallas:
		out << "Dallas";
		break;
	case District::Forest_Grove:
		out << "Forest Grove";
		break;
	case District::Molalla:
		out << "Molalla";
		break;
	case District::Philomath:
		out << "Philomath";
		break;
	case District::Santiam:
		out << "Santiam";
		break;
	case District::Tillamook:
		out << "Tillamook";
		break;
	case District::Toledo:
		out << "Tillamook";
		break;
	default:
		out << "ERROR_FIRESWITCH";
		break;
	}
	
	return out;
}

ostream& operator<<(ostream& out, Fire* fire)
{
	// your code here
	out << fire->getName() << "	" << fire->getDistrict() << "	" << fire->getLongitude() << "	" << fire->getLatitude() << "\n";
	return out;
}
