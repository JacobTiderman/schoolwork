// add code to these functions to make Quack do something useful

#include "quack.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]{"Jacob Tiderman"};

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION{false};

Quack::Quack(int capacity, int growBy) :
	// replace these initializations with the ones you actually need
	items{new char[capacity]},
	capacity{capacity}, //the array is empty at init
	front{0}, 
	back{0},
	isData{false} //no data in the array at init
{
	initArray();	// you are required to call this function here, and
					// it must be the first thing in the constructor body
}

Quack::~Quack(void)
{
	delete[] items;
}

// items are pushed to successively LOWER slots in the circular array
// (except for when the beginning of the array "wraps around" to the end)
bool Quack::pushFront(const char ch)
{	
	if(isData) {
		if(front == back) return false;
		if(front == 0) { 
			items[capacity - 1] = ch;
			front = capacity - 1;
		} else {
			items[front] = ch;
			front -= 1;
		}
	} else {
		items[front] = ch;
		if(front == 0) {front = capacity - 1; }
		else {front -= 1;}
		isData = true;
	}
	return true;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch)
{

	if(isData) {
		if(front == back) return false;
		if(back == capacity) {
			back = 0;
			items[back] = ch;
		} else {
			back += 1;
			items[back] = ch;
		}
	} else {
		items[back] = ch;
		if(back == capacity) {back = 0;}
		else {back += 1;}
		isData = true;
	}
	return true;

	return false;
}

bool Quack::popFront(char& ch)
{
	return false;
}

bool Quack::popBack(char& ch)
{
	return false;
}

void Quack::rotate(int r)
{
}

void Quack::reverse(void)
{
}

int	Quack::itemCount(void)
{
	return 0;
}

ostream& operator<<(ostream& out, Quack *q)
{
	out << "quack: empty" << endl << endl;

	// returning out is ALWAYS required for an operator<< overload
	return out;
}
