#include"Huffman_Code.h"
#include<iostream>
#include<iomanip>
using namespace std;

void Huffman_Code::Code_Pre_Order_Visit(Tree_Node* t, string s){
	if (t->value == -1) {
		Code_Pre_Order_Visit(t->Left_Child, s + "0");
		Code_Pre_Order_Visit(t->Right_Child, s + "1");
	}
	else {
		Code[Code_Num] = s;
		ASCII_List[Code_Num++] = (char)t->value;
	}
}

void Huffman_Code::Visit(Tree_Node* t){
	if (t) {
		if (t->value > 0) {
			cout << (char)(t->value) << " " << t->num << endl;
			return;
		}
		cout << (t->value) << " " << (t->num) << endl;
	}
}

Huffman_Code::Huffman_Code(char* In, int len){
	Input_Length = len,
	Input = new char[Input_Length];
	for (int i = 0; i < Input_Length; i++) {
		Input[i] = In[i];
	}
	All_Characters = 0;
	Root = 0;
	Character_Frequency = 0;
	Code = 0;
}

Huffman_Code::~Huffman_Code(){
	delete[] Input;
	delete[] All_Characters;
	delete[] Character_Frequency;
	delete[] Code;
	delete[] ASCII_List;
	delete[] DeCoding_Result;
}

void Huffman_Code::Count_Number(){
	All_Characters = new int[Input_Length];
	Character_Frequency = new int[Input_Length];
	for (int i = 0; i < Input_Length; i++) {
		Character_Frequency[i] = 0;
	}
	Character_Number = 0;
	int judge = 1;
	int temp;
	for (int i = 0; i < Input_Length; i++) {
		temp = (int)Input[i];
		judge = 1;
		for (int j = 0; j < Character_Number; j++) {
			if (All_Characters[j] == temp) {
				Character_Frequency[j]++;
				judge--;
				break;
			}
		}
		if (judge) {
			Character_Frequency[Character_Number]++;
			All_Characters[Character_Number++] = temp;
		}
	}
	cout << "All Characters and Frequency:" << endl;
	int* Cha = new int[Character_Number];
	int* Fre = new int[Character_Number];
	cout << "Character_Number: " << Character_Number << endl;
	cout << "Character:";
	for (int i = 0; i < Character_Number; i++) {
		for (int j = Character_Number - 1; j > i; j--) {
			if (Character_Frequency[j] < Character_Frequency[j - 1]) {
				int temp = Character_Frequency[j];
				Character_Frequency[j] = Character_Frequency[j - 1];
				Character_Frequency[j - 1] = temp;
				
				temp = All_Characters[j];
				All_Characters[j] = All_Characters[j - 1];
				All_Characters[j - 1] = temp;
			}
		}
		Cha[i] = All_Characters[i];
		cout << setw(4) << (char)Cha[i];
	}
	cout << endl << "Frequency:";
	for (int i = 0; i < Character_Number; i++) {
		Fre[i] = Character_Frequency[i];
		cout << setw(4) << Fre[i];
	}
	cout << endl << endl;
	delete[] All_Characters;
	delete[] Character_Frequency;
	All_Characters = Cha;
	Character_Frequency = Fre;
}

void Huffman_Code::Make_Huffman_Tree(){
	Min_Heap* h = new Min_Heap(All_Characters, Character_Frequency, Character_Number, Character_Number);
	while (h->Size() > 1) {
		Tree_Node* x, * y;
		x = new Tree_Node();
		y = new Tree_Node();
		h->Pop(*x);
		h->Pop(*y);
		Tree_Node* z = new Tree_Node(-1, x->num + y->num, x, y);
		h->Push(*z);
	}
	
	Root = h->Get_Min_Pointer();
}

void Huffman_Code::In_Order_Visit(Tree_Node* t, int Level){
	if (t) {
		In_Order_Visit(t->Left_Child, Level + 1);
		for (int i = 0; i < Level; i++) {
			cout << "     ";
		}
		Visit(t);
		In_Order_Visit(t->Right_Child, Level + 1);
	}
}

void Huffman_Code::Get_Huffman_Code(){
	Code = new string[Character_Number];
	ASCII_List = new char[Character_Number];
	Code_Num = 0;
	Code_Pre_Order_Visit(Root, "");
	cout << "Code_Num: " << Code_Num << endl;
	cout << "Huffman_Code:" << endl;
	if (Code_Num > 1) {
		for (int i = 0; i < Code_Num - 1; i++) {
			for (int j = 1; j < Code_Num - i; j++) {
				if (Code[j - 1].length() > Code[j].length()) {
					string temp = Code[j];
					Code[j] = Code[j - 1];
					Code[j - 1] = temp;
					char tempc = ASCII_List[j];
					ASCII_List[j] = ASCII_List[j - 1];
					ASCII_List[j - 1] = tempc;
				}
			}
		}
	}
	for (int i = 0; i < Code_Num; i++) {
		cout << ASCII_List[i] << ": " << Code[i] << endl;
	}
	cout << endl;
}

void Huffman_Code::Coding(){
	Input_Huffman_Code = "";
	for (int i = 0; i < Input_Length; i++) {
		for (int j = 0; j < Code_Num; j++) {
			if (Input[i] == ASCII_List[j]) {
				Input_Huffman_Code += Code[j];
				break;
			}
		}
	}
	cout << endl << "Huffman Code:" << endl
		<< Input_Huffman_Code << endl;
}

void Huffman_Code::DeCoding(){
	DeCoding_Result = new char[Input_Huffman_Code.length() / 2];
	int num = 0;
	Tree_Node* p = Root;
	for (int i = 0; i < Input_Huffman_Code.length(); i++) {
		
		if (Input_Huffman_Code[i] == '0') {
			p = p->Left_Child;
		}
		else {
			p = p->Right_Child;
		}
		if (p->value > 0) {
			DeCoding_Result[num++] = (char)p->value;
			p = Root;
		}
	}

	cout << endl << "DeCoding Result: " << endl;
	for (int i = 0; i < num; i++) {
		cout << DeCoding_Result[i];
	}
	cout << endl;
}

