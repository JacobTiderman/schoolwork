#include <cstring>
#include <iomanip>
#include "stock.h"

using namespace std;

Stock::Stock(char const * const symbol, char const * const name, int sharePrice, Date priceDate)
	: symbol{strcpy(new char[strlen(symbol)+1], symbol)},
	name{strcpy(new char[strlen(name)+1], name)},
	sharePrice{sharePrice},
	priceDate{priceDate}
{
}

Stock::Stock(void) :
	symbol{NULL},
	name{NULL},
	sharePrice{0}
{
}

Stock::~Stock(void)
{
	delete symbol;
	delete name;
}

char const * const Stock::getSymbol(void) const
{
	return symbol;	// change this to return the actual stock symbol
}

/*
you can choose to implement any of the next 3 items if necessary --
if not, feel free not to implement them

Stock::Stock(const Stock& s)
{
}

Stock& Stock::operator=(const Stock& s)
{
	return *this;
}

Stock& Stock::operator=(Stock const * const s)
{
	return *this;
}
*/

// display column headers for printout of stocks
void Stock::displayHeaders(ostream& out)
{
	// print something like this:
	//
	//  symbol  name                                      price   date
	//  ------  ----                                      -----   ----
	
	
	out << "symbol  name                                      price   date\n";
	out << "------  ----                                      -----   ----\n";
}

// print share price as DOLLARS
// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00)
ostream& operator<<(ostream& out, const Stock& s)
{
	out << s.sharePrice;
	return out;
}
