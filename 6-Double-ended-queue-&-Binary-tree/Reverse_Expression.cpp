#include "Reverse_Expression.h"
using namespace std;

char* Reverse_Expression(char* Source, int Length, int& Answer_Length)
{
	char* Stack = new char[Length];
	char* Answer = new char[Length];
	int top = -1, j = 0;
	for (int i = 0; i < Length; i++) {
		if ('a' <= Source[i] && Source[i] <= 'z') {
			Answer[j++] = Source[i];
		}
		else if (Source[i] == '(') {
			top++;
			Stack[top] = Source[i];
		}
		else if (Source[i] == ')') {
			while (true) {
				if (Stack[top] != '(') {
					Answer[j] = Stack[top];
					j++;
					top--;
				}
				else {
					top--;
					break;
				}
			}
		}
		else if (Source[i] == '*' || Source[i] == '/') {
			if (top == -1) {
				top++;
				Stack[top] = Source[i];
			}
			else {
				if (Stack[top] == '*' || Source[i] == '/') {
					Answer[j] = Stack[top];
					j++;
					Stack[top] = Source[i];
				}
				else if (Stack[top] == '(') {
					top++;
					Stack[top] = Source[i];
				}
				else if (Stack[top] == '+' || Source[i] == '-') {
					top++;
					Stack[top] = Source[i];
				}
			}
		}
		else if (Source[i] == '+' || Source[i] == '-') {
			if (top == -1) {
				top++;
				Stack[top] = Source[i];
			}
			else {
				if (
					(Stack[top] == '+' || Stack[i] == '-') 
					|| (Stack[top] == '*' || Stack[i] == '/')
					) {
					Answer[j] = Stack[top];
					j++;
					Stack[top] = Source[i];
				}
				else if (Stack[top] == '(') {
					top++;
					Stack[top] = Source[i];
				}
			}
		}
	}
	while (top != -1) {
		Answer[j] = Stack[top];
		j++;
		top--;
	}

	Answer_Length = j;
	delete[] Stack;
	return Answer;
}
