#include "DoublyList.h"

#include <iostream>
using namespace std;


int main()
{
	DoublyList List_A;
	DoublyList List_B;

	List_A.insertFront(5); 
	List_A.insertFront(4); 
	List_A.insertFront(3); 
	List_A.insertFront(2); 
	List_A.insertFront(1);

	List_B.insertFront(60);
	List_B.insertFront(50);
	List_B.insertFront(40);
	List_B.insertFront(30);
	List_B.insertFront(20);
	List_B.insertFront(10);

	List_A.print();
	List_B.print();

	List_A.swapNodes(List_B);

	List_A.print();
	List_B.print();

	cout << endl ;
	system("Pause");
	return 0;
}

