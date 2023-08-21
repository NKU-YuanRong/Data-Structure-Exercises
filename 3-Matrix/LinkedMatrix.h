#ifndef LINKED_MATRIX
#define LINKED_MATRIX
#include"HeadNode.h"
#include<iostream>
using namespace std;

class LinkedMatrix {
    friend istream& operator>> (istream&, LinkedMatrix&);
public:
    LinkedMatrix(int r, int c);
    void Transpose(LinkedMatrix& b);
    void Input(int r, int c, int v);
    int Got(int r, int c);
    void Add(LinkedMatrix& b, LinkedMatrix& c);
    void Minus(LinkedMatrix& b, LinkedMatrix& c);
    void Multiply(LinkedMatrix& b, LinkedMatrix& c);
    void Print();
private:
    int rows, cols;
    HeadNode* head;
};

#endif