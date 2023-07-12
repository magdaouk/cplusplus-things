#include "DoublyList.h" 

void DoublyList::EndOfTheList()
{
	if (count == 0)
	{
		cerr << "List is empty.";
	}

	// If there are at least 4 nodes
	else if (count > 3)
	{
		// Find third Node
		Node * current = first->getNext()->getNext();

		// Connect the needed nodes
		first->setPrev(last);
		last->setNext(first);

		// Move Pointers First and Last
		first = current->getNext();
		last = current;

		// And then disconnect
		current->getNext()->setPrev(nullptr);
		current->setNext(nullptr);
	}
}

void DoublyList::swapFirstAndSecond()
{
	if (count == 0)
	{
		cerr << "List is empty.";
	}

	else if (count == 2)
	{
		last->setNext(first);
		last->setPrev(nullptr);

		first->setNext(nullptr);
		first->setPrev(last);

		last = last->getNext();
		first = first->getPrev();
		
	}

	else 
	{
		first->setPrev(first->getNext());
		first->setNext(first->getNext()->getNext());

		first->getNext()->setPrev(first);
		first->getPrev()->setNext(first);

		first->getPrev()->setPrev(nullptr);

		first = first->getPrev();
	}
}