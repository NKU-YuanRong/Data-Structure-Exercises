#ifndef UPMATRIX
#define UPMATRIX
using namespace std;

class UpTriangularMatrix {
private:
	int* p;
	int length;
	int order;
public:
	UpTriangularMatrix(int n);
	UpTriangularMatrix(const UpTriangularMatrix& a);
	~UpTriangularMatrix();
	void set(int i, int j, int& newValue);
	void printMatrix();
};

#endif