#include "DoublyList.h"

void DoublyList::swapValues()
{
	int firstValue = first->getData();
	int secondValue = first->getNext()->getData();

	Node * current = first;

	while (current->getNext()->getNext() != nullptr)
	{
		current->setData(current->getNext()->getNext()->getData());
		current = current->getNext();

	}
	current->setData(firstValue);
	current->getNext()->setData(secondValue);

}