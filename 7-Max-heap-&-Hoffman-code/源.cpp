#include<iostream>
#include"Max_Heap.h"
#include"Huffman_Code.h"
using namespace std;

void Test_Max_Heap() {
	/*
	Max_Heap a(10);
	a.Insert(4);
	a.Insert(18);
	a.Insert(6);
	a.Insert(27);
	a.Insert(1);
	a.Insert(0);
	a.Insert(8);
	int temp = 0;
	int size = a.Size();
	for (int i = 0; i < size; i++) {
		a.DeleteMax(temp);
		cout << temp << " ";
	}
	cout << endl;
	*/
	Max_Heap a(100, -1, 15);
	a.Push(4);
	a.Push(18);
	a.Push(6);
	a.Push(50);
	a.Push(27);
	a.Push(1);
	a.Push(8);
	a.Push(0);
	int temp = 0;
	while (a.Size() > 0) {
		a.Pop(temp);
		cout << temp << " ";
	}
	cout << endl;
}

void Test_Huffman_Code() {
	char* InputContent = new char[101];
	cin.getline(InputContent, 100);
	int Length = strlen(InputContent);
	cout << endl << "The initial message is:" << endl;
	for (int i = 0; i < Length; i++) {
		cout << InputContent[i];
	}
	cout << endl << endl;

	Huffman_Code h(InputContent, Length);
	h.Count_Number();

	h.Make_Huffman_Tree();//树根存储在Root中
	
	cout << endl << "The Huffman Tree:" << endl;
	h.In_Order_Visit(h.Get_Huffman_Tree_Root(), 0);//可以遍历整棵树并输出

	h.Get_Huffman_Code();
	h.Coding();
	h.DeCoding();

}//Input: aaa, bbbbbbbb, asdkhjkkk, assddddd. bbbbb, ijnsud, socdf.

int main() {
	//Test_Max_Heap();
	Test_Huffman_Code();
}