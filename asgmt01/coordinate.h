// make NO CHANGES to this file, except you are allowed to add
// private data members to the class as needed

#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <iostream>

class Coordinate
{
public:
	Coordinate(int degrees, int minutes, int secondsTenths);
	Coordinate(void);		// default constructor
	~Coordinate(void);

	// print a coordinate
	friend std::ostream& operator<<(std::ostream& out, Coordinate& coord);

private:
	int degrees;
	int minutes;
	int secondsTenths;
	static const unsigned char		degreeChar{0xB0}; 	//WARNING: Testing using "g++ -std=c++11" and "g++ -std=gnu++11" both compile but do not display the degree symbol during operation.
									//NOTE: This will be left under the assumption the symbol will show during final compilement.
};

#endif // _COORDINATE_H_
