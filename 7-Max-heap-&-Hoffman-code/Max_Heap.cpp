#include"Max_Heap.h"
#include<iostream>
using namespace std;
/*
Max_Heap::Max_Heap(int Max_Heap_Size){
	Max_Size = Max_Heap_Size;
	Current_Size = 0;
	Heap = new int[Max_Size + 1];
}
*/
Max_Heap::Max_Heap(int Max_Element, int Min_Element, int Max_Heap_Size){
	Max_Size = Max_Heap_Size;
	Current_Size = 0;
	Heap = new int[2 * Max_Heap_Size + 1];
	Heap[0] = Max_Element;
	for (int i = 1; i < 2 * Max_Heap_Size + 1; i++) {
		Heap[i] = Min_Element;
	}
}

int Max_Heap::Max()
{
	if (Current_Size == 0) {
		cout << "The Heap Is Empty!" << endl;
		return -1;
	}
	return Heap[1];
}

/*

Max_Heap& Max_Heap::Insert(const int& x)
{
	if (Current_Size == Max_Size) {
		cout << "The Heap Is Full!" << endl;
		return *this;
	}
	int i = ++Current_Size;
	while (i != 1 && x > Heap[i / 2]) {
		Heap[i] = Heap[i / 2];
		i /= 2;
	}
	Heap[i] = x;
	return *this;
	// TODO: 在此处插入 return 语句
}

Max_Heap& Max_Heap::DeleteMax(int& x)
{
	if (Current_Size == 0) {
		cout << "The Heap Is Empty!" << endl;
		return *this;
	}
	x = Heap[1];//x即为被删除的最大元素
	int y = Heap[Current_Size--];
	int i = 1, ci = 2;
	while (ci <= Current_Size) {
		if (ci < Current_Size && Heap[ci] < Heap[ci + 1]) {
			ci++;
		}
		if (y >= Heap[ci]) {
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

*/

void Max_Heap::Print(){
	for (int i = 1; i <= Current_Size; i++) {
		cout << Heap[i] << " ";
	}
	cout << endl;
}

Max_Heap& Max_Heap::Push(const int& x){
	if (Current_Size == Max_Size) {
		cout << "The Heap Is Full!" << endl;
		return *this;
	}
	int i = ++Current_Size;
	while (x > Heap[i / 2]) {
		Heap[i] = Heap[i / 2];
		i /= 2;
	}
	Heap[i] = x;
	return *this;
}

Max_Heap& Max_Heap::Pop(int& x)
{
	if (Current_Size == 0) {
		cout << "The Heap Is Empty!" << endl;
		return *this;
	}
	x = Heap[1];
	int y = Heap[Current_Size];
	Heap[Current_Size--] = Heap[Current_Size + 1];
	int i = 1, ci = 2;
	while (1) {
		if (Heap[ci] < Heap[ci + 1]) {
			ci++;
		}
		if (y >= Heap[ci]) {
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
