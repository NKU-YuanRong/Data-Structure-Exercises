#include"Derected_Graph.h"
#include"Undirected_Graph.h"
#include<iostream>
#include<queue>
using namespace std;
void Test_Directed_Graph() {
	Directed_Graph g(10);
	/*
	g.Insert_Edge(1, 3);
	g.Insert_Edge(3, 5);
	g.Insert_Edge(3, 4);
	g.Insert_Edge(5, 7);
	g.Insert_Edge(4, 6);
	g.Insert_Edge(6, 7);
	g.Find_Path(1, 7);
	*/
	
	g.Insert_Edge(1,3);
	g.Insert_Edge(2,4);
	g.Insert_Edge(3,5);
	g.Insert_Edge(5, 4);
	g.Find_Path(1, 4);
}
void Test_Undirected_Graph() {
	Undirected_Graph g(11);
	g.insertEdge(1, 2);
	g.insertEdge(2, 3);
	g.insertEdge(3, 5);
	g.insertEdge(6, 7);
	g.insertEdge(7, 8);
	g.insertEdge(8, 10);
	int** tc = g.undirectedTC();
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			cout << tc[i][j] << " ";
		}
		cout << endl;
	}

}
int main() {
	//Test_Directed_Graph();
	Test_Undirected_Graph();
	return 0;
}