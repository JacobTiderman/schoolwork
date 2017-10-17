#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[]{/*"I. Forgot"*/ "Jacob Tiderman"};

List::List()
{
	// your code here, or in this constructor's initialization list
	//Linked list help
		//Need a refresher as to how linked lists worked, so I did a little bit of research
		//link -- https://www.codeproject.com/articles/24684/how-to-create-linked-list-using-c-c
	headByName = nullptr; //No nodes in the list yet
	headByDistrict = nullptr; //No nodes in the list yet
}

List::~List()
{
	// your code here
	//Each Node has a Fire, and two pointers
		//Before freeing memory, both pointers need to be straightened out.
		//The list is double linked, so each node has two different figuretive strings running through connecting them.
		//The first action will be to eliminate one of those.
	
	while(headByName != nullptr) {
		Node *temp = headByName; //temp is a pointer that points to the first Node in the list
		headByName->nextByDistrict = nullptr; //As we work through the list the headByDistrict thread will be dissolved
		headByName = headByName->nextByName; //Shift headByName Node to the next Node in the list
		temp->nextByName = nullptr; //set the second pointer in the Node to null
		free(temp);
	}
	
	free(headByName);
}

/*
You will need to uncomment this constructor and write the code for it.
*/

List::Node::Node(const Fire& fire) :
	// your initialization list here
	item{fire}
{
	// your code here
	//None needed - JACOB
}


void List::displayByName(ostream& out) const
{
	// your code here
	Node *current;
	current = headByName; //Create a current pointer pointing at head
	while(current != nullptr) {
		out << current->item;
		current = current->nextByName;
	}
	delete current;
}

void List::displayByDistrict(ostream& out) const
{
	// your code here
	Node *current;
	current = headByDistrict;
	while(current != nullptr) {
		out << current->item;
		current = current->nextByDistrict;
	}
	delete current;
}

void List::insert(const Fire& fire)
{
	// your code here
	Node node = (Node*)malloc(sizeof(Node)); //Create a Node called node, and allocate memory for node
	node.item = fire; //move fire object into node
	node.nextByName = headByName;
	headByName = node;
	node.nextByDistrict = headByDistrict;
	headByDistrict = node;
	//Thread inorder by name
	/*Node *temp = headByName;
	while(temp != nullptr) {
		if(strcmp(temp->item.getName(), fire.getName()) == 0) { //in the event of a duplicate
			
		} else {
			
		}
	}*/
}

Fire* const List::find(const char * const name) const
{
	// your code here, return the appropriate value

	return nullptr;
}

bool List::remove(const char * const name)
{
	// your code here, return the appropriate value

	return false;
}
