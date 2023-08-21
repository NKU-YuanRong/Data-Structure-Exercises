#ifndef HASHTABLE
#define HASHTABLE
#include<iostream>
using namespace std;

class HashingTable {
public:
	HashingTable(int divisor);
	~HashingTable() { delete[]ht; delete[] empty; delete[] neverUsed; }
	bool Search(const int& k)const;
	HashingTable& Insert(const int &a);
	bool Delete(const int& k);
	void Output();
	void recon() {
		reConstruct();
	}
private:
	int hSearch(const int& k)const;
	void reConstruct();
	int emptyBuckets;
	int usedEmptyBuckets;
	int m;
	bool* neverUsed;
	int* ht;
	bool* empty;
};

#endif // !HASHTABLE

