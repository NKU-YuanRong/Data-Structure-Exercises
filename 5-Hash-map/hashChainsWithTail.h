#ifndef HASHCHAINSWITHTAIL
#define HASHCHAINSWITHTAIL
#include<iostream>
using namespace std;
class hashNode {
public:
	int value;
	hashNode* next;
	hashNode() {
		value = 0;
		next = NULL;
	}
	hashNode(int a) {
		value = a;
		next = NULL;
	}
};
class hashChainsWithTail {
public:
	hashChainsWithTail(int divisor);
	~hashChainsWithTail();
	hashChainsWithTail& Insert(int k);
	void Delete(int k);
	bool Search(int k);
	void Print();
private:
	int m;
	bool* empty;
	hashNode** hc;
	hashNode endNode;
};
#endif
