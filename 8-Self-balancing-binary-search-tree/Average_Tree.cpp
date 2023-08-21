#include"Average_Tree.h"
#include<iostream>
using namespace std;

int Average_Tree::Height(Tree_Node* t)
{
	if (t == NULL) {
		return 0;
	}
	else {
		int Lh = Height(t->Left_Child);
		int Rh = Height(t->Right_Child);
		return Lh > Rh ? Lh + 1 : Rh + 1;
	}
}

void Average_Tree::Update_Balance(Tree_Node* t){
	t->Balance_Factor = Height(t->Left_Child) - Height(t->Right_Child);
}

Tree_Node* Average_Tree::Find_Parent(Tree_Node* t)
{
	if (t == Root) {
		return NULL;
	}
	Tree_Node* q = 0;
	Tree_Node* p = Root;
	while (p) {
		if (p->value < t->value) {
			q = p;
			p = p->Right_Child;
		}
		else if (p->value > t->value) {
			q = p;
			p = p->Left_Child;
		}
		else {
			break;
		}
	}
	return q;
	return nullptr;
}

Tree_Node* Average_Tree::LL_Adjust(Tree_Node* t){
	Tree_Node* Ls = t->Left_Child;
	t->Left_Child = Ls->Right_Child;
	Ls->Right_Child = t;
	
	Update_Balance(t);
	Update_Balance(Ls);

	return Ls;
	
}

Tree_Node* Average_Tree::LR_Adjust(Tree_Node* t)
{
	Tree_Node* Ls = t->Left_Child;
	Tree_Node* Rg = Ls->Right_Child;
	t->Left_Child = Rg->Right_Child;
	Ls->Right_Child = Rg->Left_Child;
	Rg->Left_Child = Ls;
	Rg->Right_Child = t;
	Update_Balance(t);
	Update_Balance(Ls);
	Update_Balance(Rg);
	return Rg;
}

Tree_Node* Average_Tree::RR_Adjust(Tree_Node* t)
{
	Tree_Node* Rs = t->Right_Child;
	t->Right_Child = Rs->Left_Child;
	Rs->Left_Child = t;

	Update_Balance(t);
	Update_Balance(Rs);

	return Rs;
}

Tree_Node* Average_Tree::RL_Adjust(Tree_Node* t)
{
	Tree_Node* Rs = t->Right_Child;
	Tree_Node* Lg = Rs->Left_Child;
	t->Right_Child = Lg->Left_Child;
	Rs->Left_Child = Lg->Right_Child;
	Lg->Right_Child = Rs;
	Lg->Left_Child = t;
	Update_Balance(t);
	Update_Balance(Rs);
	Update_Balance(Lg);
	return Lg;
}

Tree_Node* Average_Tree::Add(Tree_Node* &t, int v){
	if (t == NULL) {
		t = new Tree_Node(v);
		return t;
	}
	if (v < t->value) {
		t->Left_Child = Add(t->Left_Child, v);
		Update_Balance(t);
		if (t->Balance_Factor == 2) {
			if (v < t->Left_Child->value) {
				t = LL_Adjust(t);
			}
			else {
				t = LR_Adjust(t);
			}
		}
	}
	else if (v > t->value) {
		t->Right_Child = Add(t->Right_Child, v);
		Update_Balance(t);
		if (t->Balance_Factor == -2) {
			if (v > t->Right_Child->value) {
				t = RR_Adjust(t);
			}
			else {
				t = RL_Adjust(t);
			}
		}
	}
	else {
		cout << "重复插入！" << endl;
	}
	Update_Balance(t);
	return t;
}

Tree_Node* Average_Tree::Remove(Tree_Node*& t, int v)
{
	if (t == NULL) {
		return NULL;
	}
	if (v < t->value) {
		t->Left_Child = Remove(t->Left_Child, v);
		Update_Balance(t);
		if (t->Balance_Factor == -2) {
			if (t->Right_Child->Balance_Factor > 0) {
				t = RL_Adjust(t);
			}
			else {
				t = RR_Adjust(t);
			}
			Update_Balance(t);
		}
	}
	else if (v > t->value) {
		t->Right_Child = Remove(t->Right_Child, v);
		Update_Balance(t);
		if (t->Balance_Factor == 2) {
			if (t->Left_Child->Balance_Factor < 0) {
				t = LR_Adjust(t);
			}
			else {
				t = LL_Adjust(t);
			}
			Update_Balance(t);
		}
	}
	else {
		if (t->Left_Child != NULL && t->Right_Child != NULL) {
			Tree_Node* p = t->Left_Child;
			while (p->Right_Child != NULL) {
				p = p->Right_Child;
			}
			t->value = p->value;
			t->Left_Child = Remove(t->Left_Child, p->value);
		}
		else {
			Tree_Node* delpos = t;
			t = t->Left_Child == NULL ? t->Right_Child : t->Left_Child;
			delete delpos;
		}
	}
	return t;
}

void Average_Tree::Visit(Tree_Node* t){
	if (t) {
		cout << t->value << endl;
		return;
	}
}

void Average_Tree::Level_In_Order_Visit(Tree_Node* t, int Level){
	if (t) {
		Level_In_Order_Visit(t->Right_Child, Level + 1);
		for (int i = 0; i < Level; i++) {
			cout << "   ";
		}
		Visit(t);
		Level_In_Order_Visit(t->Left_Child, Level + 1);
	}
}

int Average_Tree::Lowest_Leaf(Tree_Node* t)
{
	if (t->Left_Child != NULL) {
		if (t->Right_Child != NULL) {
			return Lowest_Leaf(t->Balance_Factor > 0 ? t->Right_Child : t->Left_Child);
		}
		else {
			return Lowest_Leaf(t->Left_Child);
		}
	}
	else {
		if (t->Right_Child != NULL) {
			return Lowest_Leaf(t->Right_Child);
		}
		else {
			return t->value;
		}
	}
}

Average_Tree::Average_Tree() {
	Root = NULL;
}

bool Average_Tree::Search(int v)
{
	if (Root == NULL) {
		cout << "Tree is empty!" << endl;
		return false;
	}
	Tree_Node* p = Root;
	while (p) {
		if (p->value < v) {
			p = p->Right_Child;
		}
		else if (p->value > v) {
			p = p->Left_Child;
		}
		else {
			return true;
		}
	}
	return false;
}

Average_Tree& Average_Tree::Insert(int v)
{
	Root = Add(Root, v);
	/*
	if (Root == NULL) {
		Root = new Tree_Node(v);
		return *this;
	}
	Tree_Node* p = Root;
	Tree_Node* q = 0;
	while (p) {
		if (p->value < v) {
			q = p;
			p = p->Right_Child;
		}
		else if (p->value > v) {
			q = p;
			p = p->Left_Child;
		}
		else {
			cout << "重复输入" << p->value << endl;
			return *this;
		}
	}
	if (q->value < v) {
		q->Right_Child = new Tree_Node(v);
	}
	else {
		q->Left_Child = new Tree_Node(v);
	}*/
	return *this;
}

Average_Tree& Average_Tree::Delete(int v)
{
	Root = Remove(Root, v);
	return *this;
}

int Average_Tree::Get_Tree_Height()
{
	return Height(Root);
}

void Average_Tree::Print_Tree(){
	Level_In_Order_Visit(Root, 0);
}

int Average_Tree::Get_Lowest_Leaf()
{
	if (Root == NULL) {
		cout << "The tree is empty!" << endl;
		return -1;
	}
	return Lowest_Leaf(Root);
}
