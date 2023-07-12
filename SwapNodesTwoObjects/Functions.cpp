#include "DoublyList.h"

void DoublyList::swapNodes(DoublyList& paramList)
{
	Node * secondNodeCalling = first->getNext();
	Node * fourthNodeParameter = paramList.last->getPrev(); 

	fourthNodeParameter->setNext(first);
	first->setPrev(fourthNodeParameter);
	
	paramList.last->setNext(secondNodeCalling);
	secondNodeCalling->setPrev(paramList.last);

	first = secondNodeCalling->getPrev();
	paramList.last = fourthNodeParameter->getNext();

	paramList.last->setNext(nullptr);
	first->setPrev(nullptr);
}