#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
    Node () : data(0), previous(nullptr), next(nullptr) {}
    Node (int theData, Node *previous, Node *next)
            : data(theData), previous(previous), next(next) {}
    int getData( ) const { return data; }
	Node *getPrev( ) const { return previous; }
	Node *getNext( ) const { return next; }    
    void setData(int theData) { data = theData; }
    void setPrev(Node *pointer) { previous = pointer; }
	void setNext(Node *pointer) { next = pointer; }    
	~Node(){}
private:
    int data;
    Node *previous;
	Node *next;    
};

class DoublyList
{
public:
	DoublyList(); 
		// constructor
	
	void insertFront(int newData);
		// insertFront - Inserts a node to the front of the list.
		// @param int - The data to insert in the node

	bool isEmpty() const;
		// isEmpty - Returns true if the list is empty, false otherwise.
		// @return bool - Returns true if the list is empty, false otherwise.

	bool search(int searchData) const;
		// search const - Searches a node with the given data.
		// @param int - The data to search for
		// @return bool - Returns true if the data is found, 
		//                  false otherwise.

	void deleteNode(int deleteData);
		// deleteNode - Deletes the node that contains the given data.
		// @param int - The data in the node that needs to be deleted
	
	void destroyList();
		// destroyList - Destroys all the nodes in the list.

	void print() const;

	void EndOfTheList();

	void swapFirstAndSecond();

	~DoublyList();
		// destructor - Calls the function destroyList.

private:
    Node *first;	// pointer to the first node on the list
    Node *last;		// pointer to the last node on the list
	int count;		// number of nodes in the list
};

#endif