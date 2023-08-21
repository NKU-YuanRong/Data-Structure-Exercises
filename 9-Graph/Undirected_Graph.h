#ifndef UNDIRECTEDGRAPH
#define UNDIRECTEDGRAPH
#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;

class Undirected_Graph {
private:
	int Graph_Order;
	int** Connections;
	int* Vertex_Color;
	int Branch_Number;
	void Coloring(int v1);
	int* Coloring();
public:
	Undirected_Graph(int num_of_vertex);
	~Undirected_Graph();
	void insertEdge(int v1, int v2);
	int** undirectedTC();
	int** duibi();
};

#endif // !UNDIRECTEDGRAPH
