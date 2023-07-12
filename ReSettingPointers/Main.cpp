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

	cout << "- - - Testing Function EndOfTheList - - -" << endl;
	cout << "List A before : " << endl; 
	List_A.print();

	cout << "List A after : " << endl;
	List_A.EndOfTheList();
	List_A.print();


	cout << endl << "- - - Testing Function swapFirstAndSecond - - -" << endl;
	cout << "List A before : " << endl;
	List_A.print();

	cout << "List A after : " << endl;
	List_A.swapFirstAndSecond();
	List_A.print();
	cout << endl;

	DoublyList List_B;
	List_B.insertFront(2);
	List_B.insertFront(1);

	cout << "List B before : " << endl;
	List_B.print();

	cout << "List B after : " << endl;
	List_B.swapFirstAndSecond();
	List_B.print();

	cout << endl;
	system("Pause");
	return 0;
}
