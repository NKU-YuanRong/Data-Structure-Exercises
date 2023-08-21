#include"Expression_Tree.h"
#include<iostream>
using namespace std;

void Expression_Tree::Visit(Tree_Node* t){
	if (t) {
		cout << (t->value) << endl;
	}
}

void Expression_Tree::In_Order_Visit(Tree_Node* t){
	if (t) {
		In_Order_Visit(t->Left_Child);
		Visit(t);
		In_Order_Visit(t->Right_Child);
	}
}

void Expression_Tree::Expression_Order_Visit(Tree_Node* t, int Level){
	if (t) {
		Expression_Order_Visit(t->Left_Child, Level + 1);
		for (int i = 0; i < Level; i++) {
			cout << "   ";
		}
		Visit(t);
		Expression_Order_Visit(t->Right_Child, Level + 1);
	}
}

void Expression_Tree::Post_Order_Visit(Tree_Node* t){
	if (t) {
		Post_Order_Visit(t->Left_Child);
		Post_Order_Visit(t->Right_Child);
		Visit(t);
	}
}

Tree_Node* Expression_Tree::MakeTree(char v, Tree_Node* LeftTree, Tree_Node* RightTree)
{
	Tree_Node* Father = new Tree_Node(v, LeftTree, RightTree);
	return Father;
}

Tree_Node* Expression_Tree::Make_Expression_Tree(char* Reverse_Expression, int Length)
{
	Tree_Node** Stack = new Tree_Node * [Length];
	int top = -1;
	for (int i = 0; i < Length; i++) {
		if (Reverse_Expression[i] >= 'a' && Reverse_Expression[i] <= 'z') {
			top++;
			Stack[top] = new Tree_Node(Reverse_Expression[i]);
		}
		if (
			(Reverse_Expression[i] == '+'||Reverse_Expression[i] == '-')||
			(Reverse_Expression[i] == '*' || Reverse_Expression[i] == '/')
			) {
			Tree_Node* temp1 = Stack[top--];
			Tree_Node* temp2 = Stack[top--];
			Tree_Node* temp = new Tree_Node(Reverse_Expression[i], temp1, temp2);
			top++;
			Stack[top] = temp;
		}
	}
	Tree_Node* Tree_Root = Stack[top];
	delete[] Stack;
	return Tree_Root;
}

int Expression_Tree::Leaf_Node_Number(Tree_Node* t)
{
	int cnt = 0;
	Tree_Node** List = new Tree_Node * [30];
	int Read_Ptr = 0, Insert_Ptr = 0;
	List[Insert_Ptr++] = t;
	for (; Read_Ptr != Insert_Ptr; Read_Ptr++) {
		if (!(List[Read_Ptr]->Right_Child) && !(List[Read_Ptr]->Left_Child)) {
			cnt++;
			continue;
		}
		if (List[Read_Ptr]->Left_Child) {
			List[Insert_Ptr++] = List[Read_Ptr]->Left_Child;
		}
		if (List[Read_Ptr]->Right_Child) {
			List[Insert_Ptr++] = List[Read_Ptr]->Right_Child;
		}
	}
	std::cout << cnt << endl;
	return cnt;
}

void Expression_Tree::Left_Right_Swap(Tree_Node* t){
	if (t) {
		Tree_Node* temp = t->Left_Child;
		t->Left_Child = t->Right_Child;
		t->Right_Child = temp;
		Left_Right_Swap(t->Left_Child);
		Left_Right_Swap(t->Right_Child);
	}
}

void Expression_Tree::Level_Order_Visit(Tree_Node* t){
	Tree_Node** List = new Tree_Node*[30];
	int Read_Ptr = 0, Insert_Ptr = 0;
	List[Insert_Ptr++] = t;
	while (Read_Ptr != Insert_Ptr) {
		cout << (List[Read_Ptr]->value);
		if (List[Read_Ptr]->Left_Child) {
			List[Insert_Ptr++] = List[Read_Ptr]->Left_Child;
		}
		if (List[Read_Ptr]->Right_Child) {
			List[Insert_Ptr++] = List[Read_Ptr]->Right_Child;
		}
		Read_Ptr++;
	}
	delete[] List;
}

int Expression_Tree::Width()
{
	int ArrayNum = 30;
	Tree_Node** List = new Tree_Node * [ArrayNum];
	int* Level = new int[ArrayNum];
	int* Level_Counter = new int[ArrayNum];

	for (int i = 0; i < ArrayNum; i++) {
		Level_Counter[i] = 0;
	}
	int Read_Ptr = 0, Insert_Ptr = 0;
	Level[Insert_Ptr] = 0;
	Level_Counter[0] = 1;
	List[Insert_Ptr++] = Root;
	while (Read_Ptr != Insert_Ptr) {
		if (List[Read_Ptr]->Left_Child) {
			Level[Insert_Ptr] = Level[Read_Ptr] + 1;
			Level_Counter[Level[Insert_Ptr]]++;
			List[Insert_Ptr++] = List[Read_Ptr]->Left_Child;
		}
		if (List[Read_Ptr]->Right_Child) {
			Level[Insert_Ptr] = Level[Read_Ptr] + 1;
			Level_Counter[Level[Insert_Ptr]]++;
			List[Insert_Ptr++] = List[Read_Ptr]->Right_Child;
		}
		Read_Ptr++;
	}
	int max = 0;
	for (int i = 0; i <= Level[Read_Ptr - 1]; i++) {
		if (Level_Counter[i] > max) {
			max = Level_Counter[i];
		}
	}
	cout << max << endl;
	delete[] Level_Counter;
	delete[] List;
	delete[] Level;
	return 0;
}
