#include<iostream>
#include"Average_Tree.h"
using namespace std;

void test_Average_Tree() {
	Average_Tree Tree;
	Tree.Insert(3);
	Tree.Insert(4);
	Tree.Insert(1);
	Tree.Insert(17);
	Tree.Insert(0);
	Tree.Insert(5);
	Tree.Insert(4);
	Tree.Insert(15);
	
	Tree.Insert(-2);
	cout << "Height: " << Tree.Get_Tree_Height() << endl;
	cout << "Lowest Leaf: " << Tree.Get_Lowest_Leaf() << endl << endl;
	Tree.Print_Tree();
	//Tree.Delete(0);
	//Tree.Print_Tree();
	//cout << Tree.Search(5) << endl;
}

int main() {
	test_Average_Tree();
	return 0;
}