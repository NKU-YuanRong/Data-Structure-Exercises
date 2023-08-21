#ifndef SPARE_MATRIX
#define SPARE_MATRIX
#include<iostream>
#include<istream>
#include<ostream>
#include "Term.h"
using namespace std;

template<class T>
class SpareMatrix
{
    friend ostream& operator<<(ostream&, const SpareMatrix<T>&);
    friend istream& operator>>(istream&, SpareMatrix<T>&);
public:
    void Set();
    void Print();
    SpareMatrix(int maxTerms = 10);
    ~SpareMatrix();
    void Transpose(SpareMatrix<T>& b) const;
    void Add(const SpareMatrix<T>& b, SpareMatrix<T>& c) const;
    void Mult(const SpareMatrix<T>& b, SpareMatrix<T>& c);
private:
    void Append(const Term<T>& t);
    int rows, cols;  // matrix dimensions
    int terms;  // current number of nonzero terms
    Term<T>* a;   // term array
    int MaxTerms; // size of array a;
};

#endif

template<class T>
SpareMatrix<T>::SpareMatrix(int maxTerms)
{// Sparse matrix constructor.
    MaxTerms = maxTerms;
    a = new Term<T>[MaxTerms];
    terms = rows = cols = 0;
}
template<class T>
SpareMatrix<T>::~SpareMatrix() {
    delete[] a;
}
template<class T>
void SpareMatrix<T>::Set() {
    cout << "Enter number of rows, columns, and terms" << endl;
    cin >> rows >> cols >> terms;
    for (int i = 0; i < terms; i++) {
        cout << "Enter row, column, and value of term " << (i + 1) << endl;
        cin >> a[i].row >> a[i].col >> a[i].value;
    }
}
template<class T>
void SpareMatrix<T>::Print() {
    cout << "rows = " << rows << " columns = " << cols << endl;
    cout << "Terms = " << terms << endl;
    for (int i = 0; i < terms; i++) {
        cout << "a(" << a[i].row << "," << a[i].col << ") = " << a[i].value << endl;
    }
}
template <class T>
ostream& operator<<(ostream& out, const SpareMatrix<T>& x)
{// Put *this in output stream.
    out << "rows = " << x.rows << " columns = " << x.cols << endl;
    out << "nonzero terms = " << x.terms << endl;

    for (int i = 0; i < x.terms; i++)
        out << "a(" << x.a[i].row << ',' << x.a[i].col
        << ") = " << x.a[i].value << endl;
    return out;
}
template<class T>
istream& operator>>(istream& in, SpareMatrix<T>& x)
{// Input a sparse matrix.
    cout << "Enter number of rows, columns, and terms" << endl;
    in >> x.rows >> x.cols >> x.terms;
    for (int i = 0; i < x.terms; i++) {
        cout << "Enter row, column, and value of term " << (i + 1) << endl;
        in >> x.a[i].row >> x.a[i].col >> x.a[i].value;
    }
    return in;
}
template<class T>
void SpareMatrix<T>::Transpose(SpareMatrix<T>& b) const
{// b保存转置结果.

    // set transpose characteristics
    b.cols = rows;
    b.rows = cols;
    b.terms = terms;
    // initialize to compute transpose
    int* ColSize, * RowNext;
    ColSize = new int[cols + 1];
    RowNext = new int[cols + 1];

    // find number of entries in each column of *this
    for (int i = 1; i <= cols; i++) // initialize
        ColSize[i] = 0;
    for (int i = 0; i < terms; i++) // 计算每列元素数目
        ColSize[a[i].col]++;
    // 计算转置矩阵每行（原矩阵每列）第一个元素在b中位置
    // 第i行起始位置：行1元素数+…+行i-1元素数
    RowNext[1] = 0;
    for (int i = 2; i <= cols; i++)
        RowNext[i] = RowNext[i - 1] + ColSize[i - 1];
    // perform the transpose copying from *this to b
    for (int i = 0; i < terms; i++) {
        int j = RowNext[a[i].col]++; // a[i]在b中位置
        b.a[j].row = a[i].col;
        b.a[j].col = a[i].row;
        b.a[j].value = a[i].value;
    }
}
template<class T>
void SpareMatrix<T>::Append(const Term<T>& t)
{
    a[terms] = t;
    terms++;
}
template<class T>
void SpareMatrix<T>::Add(const SpareMatrix<T>& b, SpareMatrix<T>& c) const
{
    if (rows != b.rows || cols != b.cols)
        return;

    // set characteristics of result c
    c.rows = rows;
    c.cols = cols;
    c.terms = 0; // initial value

    // 两个指针，用于遍历*this和b，实现对应元素相加
    int ct = 0, cb = 0;
    // move through *this and b adding like terms
    while (ct < terms && cb < b.terms) {
        // 计算两个元素的行主次序编号
        int indt = a[ct].row * cols + a[ct].col;
        int indb = b.a[cb].row * cols + b.a[cb].col;

        if (indt < indb) {	// b的元素次序靠后，显然，*this的当前
            c.Append(a[ct]);	//元素即为结果——b的对应位置为0
            ct++;
        } // next term of *this
        else {
            if (indt == indb) {// 两个元素序号相同，应将它们相加
                    // 注意：相加结果为0不应放入结果矩阵c！
                if (a[ct].value + b.a[cb].value) {
                    Term<T> t;
                    t.row = a[ct].row;
                    t.col = a[ct].col;
                    t.value = a[ct].value + b.a[cb].value;
                    c.Append(t);
                }
                ct++; cb++;
            }  // next terms of *this and b
            else {
                c.Append(b.a[cb]);  // *this元素次序靠后的情况
                cb++;
            } // next term of b
        }
    }
    // 某个矩阵处理完毕，另一个未完，将剩余元素添加入c即可
    for (; ct < terms; ct++)
        c.Append(a[ct]);
    for (; cb < b.terms; cb++)
        c.Append(b.a[cb]);
}
template<class T>
void SpareMatrix<T>::Mult(const SpareMatrix<T>& b, SpareMatrix<T>& c) {
    if (cols != b.rows) {
        return;
    }
    //检查矩阵是否可以相乘

    c.rows = rows;
    c.cols = b.cols;
    c.terms = 0;
    //若可乘，对c初始化

    if (terms * b.terms == 0) {
        return;
    }
    //检查参与矩阵是否为元素为0

    int* rsize = new int[b.rows];//记录b有多少行
    int* rstart = new int[b.rows + 1];//记录b每行开始的位置
    int* temp = new int[b.cols];//暂时存储一行的元素

    for (int i = 0; i < b.rows; i++) {
        rsize[i] = 0;
    }
    for (int i = 0; i < b.terms; i++) {
        rsize[b.a[i].row]++;
    }
    rstart[0] = 0;
    rstart[b.rows] = b.terms;
    for (int i = 1; i < b.rows; i++) {
        rstart[i] = rstart[i - 1] + rsize[i - 1];
    }
    //初始化

    int ptrA = 0, rowA, colA;//定义指向a的一维数组的指针，遍历每个元素；再定义分别指向A中每个元素行和列的指针
    //int rowA, colA;//
    while (ptrA < terms) {
        rowA = a[ptrA].row;
        for (int i = 0; i < b.cols; i++) {
            temp[i] = 0;
        }//对temp初始化

        while (ptrA < terms && a[ptrA].row == rowA) {
            colA = a[ptrA].col;
            for (int i = rstart[colA]; i < rstart[colA + 1]; i++) {
                temp[b.a[i].col] += a[ptrA].value * b.a[i].value;
            }
            ptrA++;
        }//A一行有几个元素就循环几次

        for (int i = 0; i < b.cols; i++) {
            if (temp[i] != 0) {
                Term<T> ins;
                ins.row = rowA;
                ins.col = i;
                ins.value = temp[i];
                c.Append(ins);
            }
        }
    }
}