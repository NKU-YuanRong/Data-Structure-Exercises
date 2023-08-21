#include"HashTable.h"
#include<iostream>
using namespace std;

HashingTable::HashingTable(int divisor) {
	m = divisor;
	emptyBuckets = m;
	usedEmptyBuckets = 0;
	ht = new int[m];
	empty = new bool[m];
	neverUsed = new bool[m];

	for (int i = 0; i < m; i++) {
		neverUsed[i] = true;
		empty[i] = true;
	}
		
}

int HashingTable::hSearch(const int& k) const{
	int i = k % m;
	int j = i;
	do {
		if (neverUsed[j] || (!empty[j] && ht[j] == k))return j;
		j = (j + 1) % m;
	} while (j != i);
	return j;
}

bool HashingTable::Search(const int& k)const {
	int b = hSearch(k);
	//cout << b << " ";
	if (!empty[b] && ht[b] == k)return true;
	return false;
	//if (empty[b] || ht[b] != k)return false;
	//return true;
}

HashingTable& HashingTable::Insert(const int& k) {
	int b = hSearch(k);
	if (neverUsed[b]) {
		neverUsed[b] = false;
		empty[b] = false;
		ht[b] = k;
		emptyBuckets--;
		if (usedEmptyBuckets >= emptyBuckets * 0.6) {
			reConstruct();
		}
		return *this;
	}
	if (!empty[b] && ht[b] == k) {
		cout << "重复输入" << endl;
	}
	else {
		cout << "空间已满" << endl;
	}
	return *this;
}

bool HashingTable::Delete(const int &k) {
	int b = hSearch(k);
	if (!empty[b] && ht[b] == k) {
		empty[b] = true;
		emptyBuckets++;
		usedEmptyBuckets++;
		if (usedEmptyBuckets >= emptyBuckets * 0.6) {
			reConstruct();
		}
		return true;
	}
	return false;
}

void HashingTable::reConstruct() {
	int j = 0;
	int* temp = new int[m - emptyBuckets];
	for (int i = 0; i < m; i++) {
		if (!empty[i]) {
			temp[j++] = ht[i];
		}
		empty[i] = true;
		neverUsed[i] = true;
	}
	
	for (int i = 0; i < j; i++) {
		//Insert(temp[i]);
		int b = hSearch(temp[i]);
		neverUsed[b] = false;
		empty[b] = false;
		ht[b] = temp[i];
		emptyBuckets--;
	}

}

void HashingTable::Output() {
	for (int i = 0; i < m; i++) {
		if (empty[i]) cout << "null ";
		else cout << ht[i] << " ";
		cout << empty[i] << " " << neverUsed[i] << endl;
	}
	cout << endl;
}