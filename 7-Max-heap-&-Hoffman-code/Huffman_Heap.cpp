#include"Huffman_Heap.h"
#include<iostream>
using namespace std;

Min_Heap::Min_Heap(int Max){
	Current_Size = 0;
	Max_Size = Max;
	Heap = new Tree_Node[Max_Size + 1];
}

Min_Heap::Min_Heap(int* Source, int* Numbers, int Length, int Max){
	Current_Size = Length;
	Max_Size = Max;
	Heap = new Tree_Node[Max_Size + 1];
	for (int i = 0; i < Length; i++) {
		Heap[i + 1] = *(new Tree_Node(Source[i], Numbers[i]));
	}
}

Min_Heap& Min_Heap::Push(const Tree_Node& x)
{
	if (Current_Size == Max_Size) {
		cout << "The Heap is Full!" << endl;
		return *this;
	}
	int i = ++Current_Size;
	while (i != 1 && x.num < Heap[i / 2].num) {
		Heap[i] = Heap[i / 2];
		i /= 2;
	}
	Heap[i] = x;
	return *this;
	// TODO: 在此处插入 return 语句
}

Min_Heap& Min_Heap::Pop(Tree_Node& x)
{
	if (Current_Size == 0) {
		cout << "The Heap is Empty!" << endl;
		return *this;
	}
	x = Heap[1];
	Tree_Node y = Heap[Current_Size--];
	int i = 1, ci = 2;
	while (ci <= Current_Size) {
		if (ci<Current_Size && Heap[ci].num > Heap[ci + 1].num) {
			ci++;
		}
		if (Heap[ci].num >= y.num) {
			break;
		}
		Heap[i] = Heap[ci];
		i = ci;
		ci *= 2;
	}
	Heap[i] = y;
	return *this;
	// TODO: 在此处插入 return 语句
}

Tree_Node* Min_Heap::Get_Min_Pointer()
{
	return &Heap[1];
}

void Min_Heap::Print(){
	for (int i = 1; i <= Current_Size; i++) {
		cout << (char)Heap[i].value << " " << Heap[i].num << "  ";
	}
	cout << endl;
}
