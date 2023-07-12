#include "DoublyList.h"

	//constructor
DoublyList::DoublyList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

	//destructor
DoublyList::~DoublyList()
{
	destroyList();
}

	//insertFront
void DoublyList::insertFront(int newData)
{
	//Create a pointer newNode to point to a dynamic node
	Node *newNode = new Node(newData, nullptr, first);	

	if(first == nullptr) 
    {
       first = newNode;		//set "first" to be the new node
       last = newNode;		//set "last" to be the new node
    }
    else
	{
        first->setPrev(newNode);	//make first's previous link point to the new node
		first = newNode;					//set "first" to the the new node
	}

	++count;
}

	//isEmpty
bool DoublyList::isEmpty() const
{
	return (first == nullptr);
}

	//search
bool DoublyList::search(int searchData) const  
{
	Node *current = first;	//set current to point to the first node

	while (current != nullptr)	//while the pointer does not point to NULL 
	{						    //  (not the end of the list)
		if (current->getData() == searchData)	//if the data in current equals the data we need
			return true;
		else
			current = current->getNext();	//move current to next node
	}

	return false;
}

	//deleteNode
void DoublyList::deleteNode(int deleteData) 
{
	Node *current = first;		//create a pointer to traverse the list and
								//point it to the first node

	//CASE 1: The node to be deleted is the first node
    if (first->getData() == deleteData)   
	{
		first = first->getNext();	//make pointer first point to the next node

		//Case 2a: The list has only one node
		if (first == nullptr)
			last = nullptr;				
		else
			first->setPrev(nullptr);	//make first's previuos link point to NULL
				
		--count;			
		delete current;
		current = nullptr;
	}
	else //start searching the rest of the list
	{
		bool found = false;		//set a boolean value to keep track of whether 
								//the item is found or not

		while (current != nullptr && !found) //while it is not the end of the list
		{								  //  and the item has not been found

			if (current->getData() == deleteData) //if current is pointing to the 
				found = true;					  //  data that needs to be deleted
			else
				current = current->getNext(); //move current forward
		}

		if (current == nullptr)	//if we reached the end of the list, the item was not in the list
		{
			cerr << "The item to be deleted is not in the list." << endl;
		}
		else   //else the item was found somewhere in the rest of the list      
		{
			//CASE 3: The item to be deleted is in the middle of the list
			if (current != last)		//if the node to delete is in the middle of the list
			{
				//make previous node point to next node
				current->getPrev()->setNext(current->getNext());
				//make next node point to previous node
				current->getNext()->setPrev(current->getPrev());
			}
			//CASE 4: The item to be deleted is the last node
			else
			{
				last = current->getPrev();			//make "last" be the node before current 
				last->setNext(nullptr);
			}

			--count;

			//delete the node 
			delete current;
			current = nullptr;
		}
	}
}

	//destroyList - When would we use this function?
void DoublyList::destroyList()
{ 	
    while (first != nullptr)
    {
		Node  *temp = first; //pointer to delete the node
        first = first->getNext();
        delete temp;
		temp = nullptr;
    }

    last = nullptr;		// Don't forget to reset the last pointer to NULL.
	count = 0;
}

void DoublyList::print() const
{
	if (first == nullptr) // check if the list is empty
							   // you can also use: if (count < 1)
		cerr << "List is empty.";  // use cerr, rather than cout (why?)
	else
	{
		Node *current = first;   //create a pointer to traverse the list	
									  //this pointer will start with the first node in the list

		while (current != nullptr)	//while the current pointer is NOT pointing to NULL
		{						    //  that is, the current pointer has not reached the 
									//  end of the list
			cout << current->getData() << " ";	//output the data 
			current = current->getNext();		//move the pointer current forward
		}
	}
	cout << endl;
}
