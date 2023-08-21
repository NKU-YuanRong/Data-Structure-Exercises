#ifndef EXPRESSIONTREE
#define EXPRESSIONTREE
using namespace std;

class Tree_Node {
public:
	char value;
	Tree_Node* Left_Child;
	Tree_Node* Right_Child;
	Tree_Node(const char &v) {
		value = v;
		Left_Child = Right_Child = 0;
	}
	Tree_Node() {
		Left_Child = Right_Child = 0;
	}
	Tree_Node(const char& v, Tree_Node* left, Tree_Node* right) {
		value = v;
		Left_Child = left;
		Right_Child = right;
	}
};

class Expression_Tree {
private:
	Tree_Node* Root;
	void Visit(Tree_Node* t);
public:
	Expression_Tree() {
		Root = 0;
	}
	Expression_Tree(Tree_Node* r) {
		Root = r;
	}
	Tree_Node* GetRoot() { return Root; }
	void In_Order_Visit(Tree_Node* t);
	void Expression_Order_Visit(Tree_Node* t, int Level);
	void Post_Order_Visit(Tree_Node* t);
	Tree_Node* MakeTree(char v, Tree_Node* LeftTree, Tree_Node* RightTree);
	static Tree_Node* Make_Expression_Tree(char* Reverse_Expression, int Length);

	int Leaf_Node_Number(Tree_Node* t);
	void Left_Right_Swap(Tree_Node* t);
	void Level_Order_Visit(Tree_Node* t);
	int Width();
};

#endif // !EXPRESSIONTREE
