#ifndef AVERAGETREE
#define AVERAGETREE
using namespace std;
class Tree_Node {
public:
	int value;
	int Balance_Factor;
	Tree_Node* Left_Child;
	Tree_Node* Right_Child;
	Tree_Node(int v) {
		value = v;
		Balance_Factor = 0;
		Left_Child = 0;
		Right_Child = 0;
	}
	Tree_Node(int v, int b) {
		value = v;
		Balance_Factor = b;
		Left_Child = 0;
		Right_Child = 0;
	}
	Tree_Node(int v, int b, Tree_Node* Left, Tree_Node* Right) {
		value = v;
		Balance_Factor = b;
		Left_Child = Left;
		Right_Child = Right;
	}
};

class Average_Tree {
private:
	Tree_Node* Root;
	int Height(Tree_Node* t);
	void Update_Balance(Tree_Node* t);
	Tree_Node* Find_Parent(Tree_Node* t);
	Tree_Node* LL_Adjust(Tree_Node* t);
	Tree_Node* LR_Adjust(Tree_Node* t);
	Tree_Node* RR_Adjust(Tree_Node* t);
	Tree_Node* RL_Adjust(Tree_Node* t);
	Tree_Node* Add(Tree_Node* &t, int v);
	Tree_Node* Remove(Tree_Node*& t, int v);
	void Visit(Tree_Node* t);
	void Level_In_Order_Visit(Tree_Node* t, int Level);
	int Lowest_Leaf(Tree_Node* t);
public:
	Average_Tree();
	bool Search(int v);//ËÑË÷
	Average_Tree& Insert(int v);//²åÈë
	Average_Tree& Delete(int v);//É¾³ý
	int Get_Tree_Height();
	void Print_Tree();
	int Get_Lowest_Leaf();
};
#endif // !AVERAGETREE