#ifndef LOWMATRIX
#define LOWMATRIX
#include"UptriangularMatrix.h"
using namespace std;

class LowTriangularMatrix {
private:
	int* p;
	int length;
	int order;
public:
	LowTriangularMatrix(int n);
	LowTriangularMatrix(const LowTriangularMatrix& a);
	~LowTriangularMatrix();
	void set(int i, int j, int& newValue);
	void printMatrix();
	UpTriangularMatrix reverse();
};

#endif