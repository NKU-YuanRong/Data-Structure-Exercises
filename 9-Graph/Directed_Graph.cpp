#include"Derected_Graph.h"
#include <queue>
#include <iostream>
#include <stack>
using namespace std;

void Directed_Graph::Initialize(){
	if (Edge_Matrix == NULL) {
		return;
	}
	for (int i = 0; i < Vertices_Number; i++) {
		for (int j = 0; j < Vertices_Number; j++) {
			Edge_Matrix[i][j] = 0;
		}
	}
}

Directed_Graph::Directed_Graph(int Order) {
	Vertices_Number = Order;
	Edge_Matrix = new int* [Vertices_Number];
	for (int i = 0; i < Vertices_Number; i++) {
		Edge_Matrix[i] = new int[Vertices_Number];
	}
	Initialize();
}

Directed_Graph::~Directed_Graph()
{
	for (int i = 0; i < Vertices_Number; i++)
		delete[]Edge_Matrix[i];
	delete[]Edge_Matrix;
}

void Directed_Graph::Insert_Edge(int v1, int v2)
{
	if (Edge_Matrix[v1][v2] == 1) {
		cout << "重复插入！" << endl;
		return;
	}
	Edge_Matrix[v1][v2] = 1;
}

void Directed_Graph::Find_Path(int theSource, int theDestination)
{
	int* Vertices = new int[Vertices_Number];
	for (int i = 0; i < Vertices_Number; i++) { Vertices[i] = -1; }
	Vertices[theSource] = 0;
	queue<int> q;
	q.push(theSource);
	bool Find_Answer = false;
	//int num = 0;
	while (!Find_Answer && !q.empty()) {
		int Now_Step = q.front();
		q.pop();
		for (int i = 0; i < Vertices_Number; i++) {
			if ((Vertices[i] == -1) && (Edge_Matrix[Now_Step][i] == 1)) {
				
				Vertices[i] = Now_Step;
				if (i == theDestination) {
					Find_Answer = true;
					break;
				}
				q.push(i);
			}
		}
	}
	if (Find_Answer) {
		stack<int> s;
		int Sign = theDestination;
		while (Sign != theSource) {
			s.push(Sign);
			Sign = Vertices[Sign];
		}
		int Step = s.size();
		cout << "从节点" << theSource << "到节点" << theDestination << "的最短路径长度为" << Step << endl;
		cout << "具体路径为：" << Sign;
		for (int i = 0; i < Step; i++) {
			Sign = s.top();
			s.pop();
			cout << ", " << Sign;
		}
		cout << endl;
	}
	else {
		delete[] Vertices;
		cout << "不存在从节点" << theSource << "到节点" << theDestination << "的路径！" << endl;
	}
	
}
