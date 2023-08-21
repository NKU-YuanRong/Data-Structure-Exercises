#include "LowTriangularMatrix.h"
#include<iostream>
using namespace std;

LowTriangularMatrix::LowTriangularMatrix(int n) {
	order = n;
	length = n * (n + 1) / 2;
	p = new int[length];
	for (int i = 0; i < length; i++) {
		p[i] = 1;
	}
}
LowTriangularMatrix::LowTriangularMatrix(const LowTriangularMatrix& a) {
	length = a.length;
	order = a.order;
	p = new int[length];
	for (int i = 0; i < length; i++) {
		p[i] = a.p[i];
	}
}
LowTriangularMatrix::~LowTriangularMatrix() {
	delete[] p;
}
void LowTriangularMatrix::set(int i, int j, int& newValue) {
	if (i<1 || j<1 || i>order || j>order) {
		cout << "非法输入" << endl;
	}
	if (i >= j) {
		p[i * (i - 1) / 2 + j - 1] = newValue;
	}
	else {
		if (newValue != 0) {
			cout << "非法输入" << endl;
		}
	}
}
void LowTriangularMatrix::printMatrix() {
	for (int i = 1; i <= order; i++) {
		int temp = i * (i - 1) / 2;
		for (int j = 1; j <= i; j++) {
			cout << p[temp + j - 1] << " ";
		}
		for (int j = i + 1; j <= order; j++) {
			cout << 0 << " ";
		}
		cout << endl;
	}
}
UpTriangularMatrix LowTriangularMatrix::reverse() {
	UpTriangularMatrix b(order);
	for (int i = 1; i <= order; i++) {
		for (int j = 1; j <= i; j++) {
			b.set(j, i, p[i * (i - 1) / 2 + j - 1]);
		}
	}
	return b;
}