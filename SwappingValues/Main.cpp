#include "DoublyList.h"

#include <iostream>
using namespace std;

int main()
{
	DoublyList List_A;

	List_A.insertFront(7);
	List_A.insertFront(6);
	List_A.insertFront(5);
	List_A.insertFront(4);
	List_A.insertFront(3);
	List_A.insertFront(2);
	List_A.insertFront(1);

	List_A.print();
	List_A.swapValues();
	List_A.print();



	cout << endl ;
	system("Pause");
	return 0;
}