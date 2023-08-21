#ifndef DIRECTEDGRAPH
#define DIRECTEDGRAPH

using namespace std;
class Directed_Graph {
private:
	int Vertices_Number;
	int** Edge_Matrix;
	void Initialize();
public:
	Directed_Graph(int Order);
	~Directed_Graph();
	void Insert_Edge(int v1, int v2);
	void Find_Path(int theSource, int theDestination);
};

#endif