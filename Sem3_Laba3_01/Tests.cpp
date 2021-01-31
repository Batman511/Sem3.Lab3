#pragma once
#include "ArraySequence.h"
#include "List_Sequence.h"
#include "Graph.h"
#include "Tests.h"
#include <string>
using namespace std;

void interface_Tests() {
	string choose1{ "0" };
	int choose(0);

	cout << "Choose the Test:\n"
		<< "1. Test_Array_Sequence \n2. Test_Dynamic_Array \n3. Test_Linked_list \n4. Test_List_Sequence \n";
	do {
		if (choose1 == "0") cin >> choose1;
		else if (choose1 != "1" && choose1 != "2" && choose1 != "3" && choose1 != "4") {
			std::cout << "ERROR. You need choose a number from 1 to 4 \n";
			cin >> choose1;
		}
	} while (choose1 != "1" && choose1 != "2" && choose1 != "3" && choose1 != "4");
	choose = stoi(choose1);
	cout << "\n";
	switch (choose) {
	case 1:
		Test_Array_Sequence();
		break;
	case 2:
		Test_Dynamic_Array();
		break;
	case 3:
		Test_Linked_list();
		break;
	case 4:
		Test_List_Sequence();
		break;
	default: std::cout << "ERROR. You kill me.";
	}
	cout << "-----------------------------------\n";
}

int Test_Array_Sequence() {
	int* pr{ new int[5] {11,12,13,14,15} };
	ArraySequence<int> mas1(pr, 5);

	int* priv{ new int[3] {23,16,4} };
	ArraySequence<int> mas2(priv, 3);

	if (mas1[1] == 12 && mas1[4] == 15)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (mas1.GetFirst() == 11)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (mas1.GetLast() == 15)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (mas1.GetLength() == 5)
		std::cout << "Test GetSize: success" << "\n";
	else {
		std::cout << "Test GetSize: fail" << "\n";
	};

	if (mas1.Get(3) == 14)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.Append(76);
	if (mas1.GetFirst() == 76)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	mas1.Prepend(8);
	if (mas1.GetLast() == 8)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};


	mas1.GetSubSequence(2, 5);
	if (mas1[2] == 12 && mas1[3] == 13 && mas1[4] == 14 && mas1[5] == 8)
		std::cout << "Test GetSubSequence: success" << "\n";
	else {
		std::cout << "Test GetSubSequence: fail" << "\n";
	};


	int data = 44;
	mas1.InsertAt(data, 4);
	if (mas1[4] == 44)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	ArraySequence<int>* p2 = mas1.Concat(&mas2);
	if (p2->Get(0) == 76 && p2->Get(1) == 11 && p2->Get(2) == 12 && p2->Get(3) == 13
		&& p2->Get(4) == 44 && p2->Get(5) == 8 && p2->Get(6) == 23 && p2->Get(7) == 16
		&& p2->Get(8) == 4)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};


	DynamicArray<int> mas3(2);
	if (mas3[0] == -842150451 && mas3[1] == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};
	//-842150451

	delete[7] pr;
	delete[3] priv;

	return 0;
}

int Test_Dynamic_Array() {
	int* pr{ new int[5] {11,12,13,14,15} };
	DynamicArray<int> mas1(pr, 5);

	if (mas1[1] == 12 && mas1[4] == 15)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (mas1.GetLength() == 5)
		std::cout << "Test GetSize: success" << "\n";
	else {
		std::cout << "Test GetSize: fail" << "\n";
	};

	if (mas1.Get(3) == 14)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	mas1.Resize(7);
	if (mas1.GetLength() == 7)
		std::cout << "Test Resize: success" << "\n";
	else {
		std::cout << "Test Resize: fail" << "\n";
	};

	int data = 44;
	mas1.Set(5, data);
	if (mas1[5] == 44)
		std::cout << "Test Set: success" << "\n";
	else {
		std::cout << "Test Set: fail" << "\n";
	};

	DynamicArray<int> mas2(2);
	if (mas2[0] == -842150451 && mas2[1] == -842150451)
		std::cout << "Test Creation constructor: success" << "\n";
	else {
		std::cout << "Test Creation constructor: fail" << "\n";
	};
	//-842150451

	delete[5] pr;

	return 0;
}

int Test_Linked_list() {
	int* a{ new int[6] {1,4,5,7,4,17} };
	int* b{ new int[5] {5,11,8,9,2} };

	LinkedList<int> list1{ a,6 };
	LinkedList<int> list2{ b,5 };

	if (list1.GetFirst() == 1)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 17)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1[2] == 5 && list1[5] == 17)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (list1.GetLength() == 6)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(3) == 7)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(5);
	if (list1[0] == 5)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(9);
	if (list2[5] == 9)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	LinkedList<int>* p = list2.GetSubList(1, 4);
	if (p->Get(0) == 11 && p->Get(1) == 8 && p->Get(2) == 9 && p->Get(3) == 2)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2[2] == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedList<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 5 && p2->Get(1) == 1 && p2->Get(2) == 4 && p2->Get(3) == 5
		&& p2->Get(4) == 7 && p2->Get(5) == 4 && p2->Get(6) == 17 && p2->Get(7) == 5
		&& p2->Get(8) == 11 && p2->Get(9) == 3 && p2->Get(10) == 8 && p2->Get(11) == 9
		&& p2->Get(12) == 2 && p2->Get(13) == 9)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	delete[7] a;
	delete[6] b;

	return 0;
}

int Test_List_Sequence() {
	int* a{ new int[6] {1,4,5,7,4,17} };
	LinkedListSequence<int> list1{ a,6 };

	int* b{ new int[5] {5,11,8,9,2} };
	LinkedListSequence<int> list2{ b,5 };

	if (list1.GetFirst() == 1)
		std::cout << "Test GetFirst: success" << "\n";
	else {
		std::cout << "Test GetFirst: fail" << "\n";
	};

	if (list1.GetLast() == 17)
		std::cout << "Test GetLast: success" << "\n";
	else {
		std::cout << "Test GetLast: fail" << "\n";
	};

	if (list1[2] == 5 && list1[5] == 17)
		std::cout << "Test Operator []: success" << "\n";
	else {
		std::cout << "Test Operator []: fail" << "\n";
	};

	if (list1.GetLength() == 6)
		std::cout << "Test GetLenght: success" << "\n";
	else {
		std::cout << "Test GetLenght: fail" << "\n";
	};

	if (list1.Get(3) == 7)
		std::cout << "Test Get: success" << "\n";
	else {
		std::cout << "Test Get: fail" << "\n";
	};

	list1.Append(5);
	if (list1.Get(0) == 5)
		std::cout << "Test Append: success" << "\n";
	else {
		std::cout << "Test Append: fail" << "\n";
	};

	list2.Prepend(9);
	if (list2.Get(5) == 9)
		std::cout << "Test Prepend: success" << "\n";
	else {
		std::cout << "Test Prepend: fail" << "\n";
	};

	Sequence<int>* p = list2.GetSubSequence(1, 4);
	if (p->Get(0) == 11 && p->Get(1) == 8 && p->Get(2) == 9 && p->Get(3) == 2)
		std::cout << "Test GetSubList: success" << "\n";
	else {
		std::cout << "Test GetSubList: fail" << "\n";
	};

	list2.InsertAt(3, 2);
	if (list2.Get(2) == 3)
		std::cout << "Test InsertAt: success" << "\n";
	else {
		std::cout << "Test InsertAt: fail" << "\n";
	};

	LinkedListSequence<int>* p2 = list1.Concat(&list2);
	if (p2->Get(0) == 5 && p2->Get(1) == 1 && p2->Get(2) == 4 && p2->Get(3) == 5
		&& p2->Get(4) == 7 && p2->Get(5) == 4 && p2->Get(6) == 17 && p2->Get(7) == 5
		&& p2->Get(8) == 11 && p2->Get(9) == 3 && p2->Get(10) == 8 && p2->Get(11) == 9
		&& p2->Get(12) == 2 && p2->Get(13) == 9)
		std::cout << "Test Concat: success" << "\n";
	else {
		std::cout << "Test Concat: fail" << "\n";
	};

	delete[7] a;
	delete[6] b;

	return 0;
}

int Test_Graph() {
	



	return 0;
}



