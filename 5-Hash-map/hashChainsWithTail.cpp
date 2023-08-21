#include"hashChainsWithTail.h"
#include<iostream>
using namespace std;
hashChainsWithTail::hashChainsWithTail(int divisor) {
	endNode.next = NULL;
	endNode.value = 999999999;
	m = divisor;
	empty = new bool[m];
	hc = new hashNode*[m];
	for (int i = 0; i < m; i++) {
		empty[i] = true;
		hc[i] = &endNode;
	}
}

hashChainsWithTail::~hashChainsWithTail() {
	delete[] empty;
	delete[] hc;
}

bool hashChainsWithTail::Search(int k) {
	int b = k % m;
	hashNode* p = hc[b];
	while (p->value < k) {
		p = p->next;
	}
	if (p->value == k) {
		return true;
	}
	return false;
}

hashChainsWithTail& hashChainsWithTail::Insert(int k) {
	int b = k % m;
	hashNode* p = hc[b];
	if (p->next == NULL) {
		hashNode* temp = new hashNode(k);
		hc[b] = temp;
		temp->next = &endNode;
		return *this;
	}
	hashNode* q = p;
	p = p->next;
	while (p->value <= k) {
		q = p;
		p = p->next;
	}
	if (q->value == k) {
		cout << "重复插入" << endl;
		return *this;
	}
	hashNode* temp = new hashNode(k);
	q->next = temp;
	temp->next = p;
	return *this;
}

void hashChainsWithTail::Delete(int k) {
	int b = k % m;
	hashNode* p = hc[b];
	if (p->value > k) {
		cout << "要删除的元素不存在" << endl;
		return;
	}
	if (p->value == k) {
		hc[b] = p->next;
		delete p;
		return;
	}
	
	hashNode* q = p;
	p = p->next;
	while (p->value < k) {
		q = p;
		p = p->next;
	}
	if (p->value == k) {
		q->next = p->next;
		delete p;
		return;
	}
	else {
		cout << "要删除的元素不存在" << endl;
		return;
	}
}

void hashChainsWithTail::Print() {
	hashNode* b;
	for (int i = 0; i < m; i++) {
		b = hc[i];
		cout << "Bucket " << i << " : ";
		while (b->next != NULL) {
			cout << b->value << " ";
			b = b->next;
		}
		cout << endl;
	}
}