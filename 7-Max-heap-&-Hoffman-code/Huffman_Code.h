#ifndef HUFFMANCODE
#define HUFFMANCODE
#include"Huffman_Heap.h"
#include<string>
class Huffman_Code {
private:
	int Input_Length;
	char* Input;
	int* All_Characters;
	int* Character_Frequency;
	int Character_Number;
	Tree_Node* Root;
	string* Code;
	char* ASCII_List;
	int Code_Num;
	void Code_Pre_Order_Visit(Tree_Node* t, string s);
	string Input_Huffman_Code;
	char* DeCoding_Result;
public:
	void Visit(Tree_Node* t);
	Huffman_Code(char* In, int len);
	~Huffman_Code();
	void Count_Number();
	void Make_Huffman_Tree();
	Tree_Node* Get_Huffman_Tree_Root() { return Root; }
	void In_Order_Visit(Tree_Node* t, int Level);
	void Get_Huffman_Code();
	void Coding();
	void DeCoding();
};
#endif