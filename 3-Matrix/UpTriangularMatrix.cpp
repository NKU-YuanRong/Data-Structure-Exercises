#include"UptriangularMatrix.h"
#include<iostream>
using namespace std;

UpTriangularMatrix::UpTriangularMatrix(int n) {
	order = n;
	length = n * (n + 1) / 2;
	p = new int[length];
	for (int i = 0; i < length; i++) {
		p[i] = 0;
	}
}
UpTriangularMatrix::UpTriangularMatrix(const UpTriangularMatrix& a) {
	length = a.length;
	order = a.order;
	p = new int[length];
	for (int i = 0; i < length; i++) {
		p[i] = a.p[i];
	}
}
UpTriangularMatrix::~UpTriangularMatrix() {
	delete[] p;
}
void UpTriangularMatrix::set(int i, int j, int& newValue) {
	if (i<1 || j<1 || i>order || j>order) {
		cout << "非法输入" << endl;
	}
	if (i <= j) {
		p[order * (i - 1) - (i - 1) * (i - 2) / 2 + j - i] = newValue;
	}
	else {
		if (newValue != 0) {
			cout << "非法输入" << endl;
		}
	}
}
void UpTriangularMatrix::printMatrix() {
	for (int i = 1; i <= order; i++) {
		int temp = order * (i - 1) - (i - 1) * (i - 2) / 2;
		for (int j = 1; j < i; j++) {
			cout << 0 << " ";
		}
		for (int j = i; j <= order; j++) {
			cout << p[temp + j - i] << " ";
		}
		cout << endl;
	}
}