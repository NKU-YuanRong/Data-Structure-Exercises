#include<iostream>
using namespace std;


class ChainNode {
public:
	ChainNode* next;
	int value;
	//������˽�г�Ա�����ݺ�ָ��
	ChainNode() {
		value = -1;
		next = NULL;
	}
	ChainNode(int a) {
		value = a;
		next = NULL;
	}
};

class extendedChain {
private:
	ChainNode* head;//˽��Ԫ�أ�ͷָ��ָ���һ��Ԫ��
public:
	extendedChain();//���캯��
	extendedChain(const extendedChain& a);//�������캯��
	~extendedChain();//��������
	void Put(int a);//������β����Ԫ��
	//void pop();//ɾ���������һ��Ԫ��
	//void Insert(int pos, int val);//������ȷ��λ�ò���Ԫ��
	//void Delete(int pos);//ɾ������ĳλ�õ�Ԫ��
	void Print();//����Ļ�������
	friend extendedChain meld(extendedChain a, extendedChain b);//�ǳ�Ա����meld�������������ϳ�һ������
};
extendedChain::extendedChain() {
	head = NULL;
}
void extendedChain::Put(int a) {
	//ChainNode* p = new ChainNode(a);
	if (head == NULL) {
		head = new ChainNode(a);
		return;
	}
	ChainNode* q = head;
	while (q->next != NULL) {
		q = q->next;
	}
	//q->next = p;
	q->next = new ChainNode(a);
}
void extendedChain::Print() {
	ChainNode* p = head;
	while (p != NULL) {
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}
extendedChain::extendedChain(const extendedChain& a) {
	//�˴�ȱ��һ���ͷ�ԭ�пռ�Ĳ��裬����д��
	ChainNode* p = a.head;
	while (p!= NULL) {
		Put(p->value);
		p = p->next;
	}
}
extendedChain::~extendedChain() {
	ChainNode* p = head;
	ChainNode* q = p->next;
	while (q != NULL) {
		delete p;
		p = q;
		q = q->next;
	}
	delete p;
}
extendedChain meld(extendedChain a, extendedChain b) {
	extendedChain c;
	ChainNode* p = a.head;
	ChainNode* q = b.head;
	while (p != NULL && q != NULL) {
		c.Put(p->value);
		c.Put(q->value);
		p = p->next;
		q = q->next;
	}
	if (p == NULL) {
		while (q != NULL) {
			c.Put(q->value);
			q = q->next;
		}
	}
	else {
		while (p != NULL) {
			c.Put(p->value);
			p = p->next;
		}
	}
	return c;
}
void test01() {
	extendedChain a;
	for (int i = 5; i > 0; i--) {
		a.Put(i);
	}
	cout << "a = ";
	a.Print();
	extendedChain b = a;
	for (int i = 5; i < 11; i++) {
		b.Put(i);
	}
	cout << "b = ";
	b.Print();
	extendedChain c = meld(a, b);
	cout << "c = meld(a, b) = ";
	c.Print();
	extendedChain d;
	for (int i = 1; i < 6; i++) {
		d.Put(i);
	}
	cout << "d = ";
	d.Print();
	extendedChain e = meld(c, d);
	cout << "e = meld(c, d) = ";
	e.Print();
}

//---------------------------------------

int main() {
	test01();
	return 0;
}
