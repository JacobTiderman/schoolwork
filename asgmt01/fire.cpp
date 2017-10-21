#include <iostream>
#include <cstring>
#include "fire.h"

#include <iomanip> // --- need for setw(int)

using namespace std;

const int		Fire::columnWidths[4] = { -1, -1, -1, -1 };

Fire::Fire(const District district, const char * const name,
	int latDeg, int latMin, int latSec, int longDeg, int longMin, int longSec) :
	district{district},
	latitude{Coordinate(latDeg, latMin, latSec)},
	longitude{Coordinate(longDeg, longMin, longSec)}
{
	// your code here, or in this constructor's initialization list

	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
	
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
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

Fire::~Fire()
{
	// your code here
	delete name; //memory is allocated and must be freed
}

void Fire::displayColumnHeadings(ostream& out)
{
	// your code here
	out << "name                      district        longitude        latitude\n"
	    << "-----------------------   -------------   --------------   --------------\n";
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
	//Due to the operator<< in coordinate.h being a Coordinate& and not a Coordinate*
		//out << fire->getLongitude();  does not work
	
	//std::cout.setstate(std::ios_base::goodbit);
	//cout << "test";
	
	Coordinate lon, lat;
	lon = fire->getLongitude();
	lat = fire->getLatitude();
	
	out << setw(24) << left << fire->getName() << "  "
	    << setw(13) << fire->getDistrict() << "  "
	    << right << lon << "  " << lat << "\n";
	    //<< fire->getLongitude()& << "	" << fire->getLatitude() << "\n";
	return out;
}
