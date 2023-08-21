#include"Undirected_Graph.h"

void Undirected_Graph::Coloring(int v1){
	int* Sign = new int[Graph_Order];
	int Color = Vertex_Color[v1];
	for (int i = 0; i < Graph_Order; i++) {
		Sign[i] = -1;
	}//标记
	queue<int> q;
	q.push(v1);
	while (!q.empty()){
		int Now_Step = q.front();
		q.pop();
		for (int j = 0; j < Graph_Order; j++) {
			if (Now_Step == j)continue;
			if (Connections[Now_Step][j] == 1 && Sign[j] == -1) {
				Vertex_Color[j] = Color;
				Sign[j] = 1;//已染色
				q.push(j);
			}
		}
	}
	delete[] Sign;
}

int* Undirected_Graph::Coloring()
{
	int* Vertices = new int[Graph_Order];
	int Color = 0;
	for (int i = 0; i < Graph_Order; i++) {
		Vertices[i] = -1;//-1代表未被染色
	}
	for (int i = 0; i < Graph_Order; i++) {
		if (Vertices[i] == -1) {
			queue<int> q;
			Color++;
			q.push(i);
			while (!q.empty()) {
				int Now_Step = q.front();
				Vertices[Now_Step] = Color;
				q.pop();
				for (int j = 0; j < Graph_Order; j++) {
					if (i == j)continue;
					if (Connections[Now_Step][j] == 1  && Vertices[j] == -1) {
						//Vertices[i] = Color;
						q.push(j);
					}
				}
			}
		}
	}
	return Vertices;
}

Undirected_Graph::Undirected_Graph(int ord) {
	Graph_Order = ord;
	Branch_Number = ord;
	Vertex_Color = new int[Graph_Order];
	Connections = new int* [Graph_Order];
	for (int i = 0; i < Graph_Order; i++) {
		Connections[i] = new int[Graph_Order];
		for (int j = 0; j < Graph_Order; j++) {
			Connections[i][j] = 0;
		}
		Connections[i][i] = 1;
		Vertex_Color[i] = i;
	}
}

Undirected_Graph::~Undirected_Graph()
{
	for (int i = 0; i < Graph_Order; i++) {
		delete[] Connections[i];
	}
	delete[]Connections;
}

void Undirected_Graph::insertEdge(int v1, int v2)
{
	Connections[v1][v2] = 1;
	Connections[v2][v1] = 1;
	Coloring(v1);
}

int** Undirected_Graph::undirectedTC() {
	int** Transitive_Closure = new int* [Graph_Order];
	for (int i = 0; i < Graph_Order; i++) {
		Transitive_Closure[i] = new int [Graph_Order];
		for (int j = 0; j < Graph_Order; j++) {
			Transitive_Closure[i][j] = 0;
		}
	}
	for (int i = 0; i < Graph_Order; i++) {
		int temp = Vertex_Color[i];
		for (int j = i; j < Graph_Order; j++) {
			if (Vertex_Color[j] == temp) {
				Transitive_Closure[i][j] = 1;
				Transitive_Closure[j][i] = 1;
			}
		}
	}
	return Transitive_Closure;
}