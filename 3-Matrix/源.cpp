#include"LowTriangularMatrix.h"
#include"UptriangularMatrix.h"
#include"SpareMatrix.h"
#include"LinkedMatrix.h"
#include<iostream>
#include<istream>
#include<ostream>
using namespace std;

void LowMatrix2UpMatrix() {
	LowTriangularMatrix a(6);
	int temp = 3;
	a.set(5, 3, temp);
	a.set(6, 2, temp);
	a.printMatrix();
	UpTriangularMatrix b = a.reverse();
	cout << endl;
	b.printMatrix();
}

void TestSpareMatrix() {
	SpareMatrix<int> a(20);
	SpareMatrix<int> b(20);
	SpareMatrix<int> c(20);
	a.Set();
	a.Print();
	//a.Transpose(b);
	b.Set();
	b.Print();
	a.Mult(b, c);
	c.Print();
}
/*
* INPUT:
6 7 7
1 3 3
1 6 2
2 3 4
3 3 5
4 4 6
5 6 7
6 2 5
*/

void TestLinkedMatrix01() {
	LinkedMatrix a(6, 7);
	LinkedMatrix b(6, 7);
	a.Input(1, 3, 6);
	a.Input(5, 3, 7);
	a.Input(5, 4, 9);
	a.Input(5, 2, 5);
	a.Input(6, 1, 1);
	a.Print();
	cout << endl;
	a.Got(1, 3);
	a.Got(5, 4);
	a.Got(6, 1);
	a.Got(2, 4);
	cout << endl;
	a.Transpose(b);
	b.Print();
}
void TestLinkedMatrix02() {
	LinkedMatrix a(6, 7);
	//a.Input(5, 3, 8);
	a.Input(1, 3, 6);
	a.Input(5, 3, 7);
	a.Input(5, 4, 9);
	a.Input(5, 2, 5);
	a.Input(6, 1, 1);
	a.Print();
	cout << endl;

	LinkedMatrix b(6, 7);
	a.Transpose(b);
	b.Print();
	cout << endl;
	LinkedMatrix c(5, 5);
	a.Multiply(b, c);
	c.Print();
	/*
	b.Input(1, 3, 7);
	b.Input(5, 3, 6);
	b.Input(5, 4, 8);
	b.Print();
	cout << endl;
	LinkedMatrix c(6, 7);
	a.Minus(b, c);
	c.Print();*/
	/*
	c.Got(5, 3);
	c.Got(5, 4);
	c.Got(1, 3);
	c.Got(5, 6);*/
}
void TestLinkedMatrix00() {
	LinkedMatrix a(3, 2);
	LinkedMatrix b(2, 3);
	LinkedMatrix c(5, 7);
	a.Input(0, 0, 3);
	a.Input(0, 1, 7);
	a.Input(2, 1, 6);
	a.Print();
	cout << endl;
	b.Input(0, 0, 7);
	b.Input(0, 2, 4);
	b.Input(1, 0, -3);
	b.Input(1, 1, 1);
	b.Print();
	cout << endl;
	a.Multiply(b, c);
	c.Print();
}

int main() {
	//LowMatrix2UpMatrix();
	//TestSpareMatrix();
	TestLinkedMatrix00();
	//TestLinkedMatrix01();
	//TestLinkedMatrix02();
	return 0;
}