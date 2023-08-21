#ifndef DOUBLEQUEUE
#define DOUBLEQUEUE
using namespace std;

class Double_Ended_Queue {
private:
	int MAX_Length;
	int start;
	int length;
	int* p;
	Double_Ended_Queue(int len) {
		MAX_Length = len;
		start = 0;
		length = 0;
		p = new int[MAX_Length];
	}
public:
	static Double_Ended_Queue Create(int MaxLen);
	bool IsEmpty();
	bool IsFull();
	int Left();
	int Right();
	bool AddLeft(int n);
	bool AddRight(int n);
	bool DeleteLeft();
	bool DeleteRight();
	void Print();
	void PrintAll();
};

#endif // !1
