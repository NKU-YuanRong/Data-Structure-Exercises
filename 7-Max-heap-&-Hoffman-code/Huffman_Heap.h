#ifndef HUFFMANTREE
#define HUFFMANTREE
using namespace std;

class Tree_Node {
public:
	int value;
	int num;
	Tree_Node* Left_Child;
	Tree_Node* Right_Child;
	Tree_Node() {
		value = -1;
		num = 0;
		Left_Child = 0;
		Right_Child = 0;
	}
	Tree_Node(int v, int n) {
		value = v;
		num = n;
		Left_Child = 0;
		Right_Child = 0;
	}
	Tree_Node(int v, int n, Tree_Node* Left, Tree_Node* Right) {
		value = v;
		num = n;
		Left_Child = Left;
		Right_Child = Right;
	}
	Tree_Node(const Tree_Node& t) {
		value = t.value;
		num = t.num;
		Left_Child = t.Left_Child;
		Right_Child = t.Right_Child;
	}
};

class Min_Heap {
private:
	int Current_Size;
	int Max_Size;
	Tree_Node* Heap;
public:
	Min_Heap(int Max = 10);
	Min_Heap(int* Source, int* Numbers, int Length, int Max = 10);
	~Min_Heap() { delete[] Heap; }
	Min_Heap& Push(const Tree_Node& x);
	Min_Heap& Pop(Tree_Node& x);
	Tree_Node* Get_Min_Pointer();
	int Size() { return Current_Size; }
	void Print();
};

#endif // !HUFFMANTREE
