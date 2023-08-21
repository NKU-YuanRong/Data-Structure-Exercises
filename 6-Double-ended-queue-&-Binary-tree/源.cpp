#include"Double_Ended_Queue.h"
#include"Reverse_Expression.h"
#include"Expression_Tree.h"
#include<iostream>
using namespace std;
void Test_DoubleQueue() {
	Double_Ended_Queue d = Double_Ended_Queue::Create(15);
	string rcd = "";
	int temp = 0;
	while (true) {
		cin >> rcd;
		if (rcd == "AddLeft") {
			cin >> temp;
			d.AddLeft(temp);
			continue;
		}
		if (rcd == "AddRight") {
			cin >> temp;;
			d.AddRight(temp);
			continue;
		}
		if (rcd == "DeleteRight") {
			d.DeleteRight();
			continue;
		}
		if (rcd == "DeleteLeft") {
			d.DeleteLeft();
			continue;
		}
		if (rcd == "IsEmpty") {
			d.IsEmpty();
			continue;
		}
		if (rcd == "IsFull") {
			d.IsFull();
			continue;
		}
		if (rcd == "Left") {
			d.Left();
			continue;
		}
		if (rcd == "Right") {
			d.Right();
			continue;
		}
		if (rcd == "End") {
			break;
		}
		cout << "WRONG" << endl;
	}
}
void Test_ExpressionTree() {
	char* Input = new char[20];
	cin.getline(Input, 20);
	int AnsLen = 0;
	char* Output = Reverse_Expression(Input, strlen(Input), AnsLen);
	
	Expression_Tree Exp_Tree(Expression_Tree::Make_Expression_Tree(Output, AnsLen));

	cout << endl << "The Expression_Tree is: " << endl;
	Exp_Tree.Expression_Order_Visit(Exp_Tree.GetRoot(), 0);

	
	cout << endl << "Ergodic the three level by level: ";
	Exp_Tree.Level_Order_Visit(Exp_Tree.GetRoot());
	cout << endl;

	cout << endl << "Ergodic the three level by level after swap childs :";
	Exp_Tree.Left_Right_Swap(Exp_Tree.GetRoot());
	Exp_Tree.Level_Order_Visit(Exp_Tree.GetRoot());
	cout << endl;

	cout << endl << "The number of Leaf_Node: ";
	Exp_Tree.Leaf_Node_Number(Exp_Tree.GetRoot());
	
	cout << endl << "The width of the tree: ";
	Exp_Tree.Width();
	
}//Input:a+b+c*(d+e)

int main() {
	//Test_DoubleQueue();
	Test_ExpressionTree();
}