#include "DoublyList.h"

void DoublyList::swapValues(const DoublyList& parameterList) const
{
	if (count == 0 or parameterList.count == 0)
	{
		cerr << "A list is empty." << endl;
	}

	else 
	{
		int lastNumber = parameterList.last->getData();
		parameterList.last->setData(first->getData());
		first->setData(lastNumber);
	}
}
