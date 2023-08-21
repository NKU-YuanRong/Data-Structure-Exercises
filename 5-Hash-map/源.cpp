#include<iostream>
#include"HashTable.h"
#include"hashChainsWithTail.h"
using namespace std;

void testHashingTable() {
	HashingTable a(11);
	a.Insert(10);
	a.Insert(21);
	a.Insert(0);
	a.Insert(6);
	a.Insert(8);
	a.Insert(101);
	a.Insert(33);
	a.Output();
	cout << a.Search(10) << endl;
	cout << a.Search(21) << endl;
	cout << a.Search(101) << endl;
	a.Delete(10);
	cout << a.Search(10) << endl << endl;
	a.Output();

	a.Delete(21);
	a.Delete(0);
	a.Delete(8);
	a.Delete(21);
	a.Output();

	a.Delete(33);
	a.Insert(42);
	a.Output();
}
void testHashChain() {
	hashChainsWithTail a(11);
	a.Insert(14).Insert(15).Insert(0).Insert(11).Insert(3).Insert(11);
	cout << a.Search(101) << endl;
	cout << a.Search(14) << endl;
	cout << a.Search(11) << endl;
	a.Print();
	a.Delete(11);
	cout << a.Search(11) << endl;
	a.Print();
}

int main() {
	//testHashingTable();
	testHashChain();
	return 0;
}