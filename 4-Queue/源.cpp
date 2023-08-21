#include<iostream>
using namespace std;

class TwoWayNode {
public:
	int value;
	TwoWayNode* next;
	TwoWayNode* prev;
	TwoWayNode();//无参构造函数，默认参数value = -1
	TwoWayNode(int val);//有参构造函数，参数value = val
	TwoWayNode(int val, TwoWayNode* pr, TwoWayNode* ne);//有参构造函数plus
};
TwoWayNode::TwoWayNode() {
	value = -1;
	next = NULL;
	prev = NULL;
}
TwoWayNode::TwoWayNode(int val) {
	value = val;
	next = NULL;
	prev = NULL;
}
TwoWayNode::TwoWayNode(int val, TwoWayNode* pr, TwoWayNode* ne) {
	value = val;
	prev = pr;
	next = ne;
}

class ChainTable {
private:
	TwoWayNode* head;
	int num;
public:
	ChainTable();
	ChainTable(const ChainTable& a);
	~ChainTable();
	//void Reset();//重置，释放链表内存空间，将链表恢复为初创建状态(head = NULL)
	void Put(int val);//向链表尾插入新元素
	int Pop();//弹出，弹出链表尾部元素
	void Delete(int n);
	void Reset();
	//void Insert(int val, int pos);//向链表中插入元素
	//void Delete(int pos);//删除链表中的元素
	void Print();//向屏幕输出链表中的元素

	friend int Josephus_Linked(int n, int m);
	void Put(TwoWayNode* a);
};
ChainTable::ChainTable() {
	head = NULL;
	num = 0;
}
ChainTable::ChainTable(const ChainTable& a) {
	if (head != NULL) {
		TwoWayNode* p = head->next;
		while (p != head) {
			p = p->next;
			delete p->prev;
			p->prev = head;
		}
		delete p;
		head = NULL;
	}
	num = a.num;
	if (a.head == NULL) {
		head = NULL;
		return;
	}
	TwoWayNode* fi = new TwoWayNode(a.head->value);
	fi->prev = fi;
	fi->next = fi;
	head = fi;
	TwoWayNode* q = a.head->next;
	while (q != a.head) {
		//Put(q->value);
		TwoWayNode* head_prev = head->prev;
		TwoWayNode* fo = new TwoWayNode(q->value, head_prev, head);
		head_prev->next = fo;
		head->prev = fo;
		q = q->next;
	}
	
}
ChainTable::~ChainTable() {
	if (head == NULL) {
		return;
	}
	TwoWayNode* p = head->next;
	while (p != head) {
		p = p->next;
		delete p->prev;
		p->prev = head;
	}
	delete p;
}
void ChainTable::Reset() {
	if (head == NULL) {
		return;
	}
	TwoWayNode* p = head->next;
	while (p != head) {
		p = p->next;
		delete p->prev;
		p->prev = head;
	}
	delete p;
	head = NULL;
	num = 0;
}
void ChainTable::Put(int val) {
	if (head == NULL) {
		TwoWayNode* a = new TwoWayNode(val);
		head = a;
		a->next = a;
		a->prev = a;
		num++;
		//head = a.next = a.prev = &a;
		return;
	}
	TwoWayNode* q = head->prev;
	TwoWayNode* b = new TwoWayNode(val, q, head);
	head->prev = b;
	q->next = b;
	num++;
}
void ChainTable::Put(TwoWayNode* a) {
	if (head == NULL) {
		head = a;
		a->next = a;
		a->prev = a;
		return;
	}
	TwoWayNode* q = head->prev;
	q->next = a;
	head->prev = a;
	a->prev = q;
	a->next = head;
	num++;
}
int ChainTable::Pop() {
	if (head == NULL) {
		cout << "The ChainTable is Vacant" << endl;
		return -1;
	}
	TwoWayNode* p = head->prev;
	if (p == head) {
		int temp = p->value;
		delete p;
		head = NULL;
		num = 0;
		return temp;
	}
	int temp = p->value;
	head->prev = p->prev;
	p->prev->next = head;
	delete p;
	num--;
	return temp;
}
void ChainTable::Delete(int n) {
	if (head == NULL) {
		cout << "ChainTable is empty!" << endl;
		return;
	}
	TwoWayNode* p = head;
	if (num == 1) {
		delete p;
		head = NULL;
		return;
	}
	for (int i = 1; i < n; i++) {
		p = p->next;
	}
	if (p == head) {
		TwoWayNode* q = p->prev;
		TwoWayNode* r = p->next;
		head = r;
		q->next = r;
		r->prev = q;
		delete p;
		return;
	}
	TwoWayNode* q = p->prev;
	TwoWayNode* r = p->next;
	q->next = r;
	r->prev = q;
	delete p;
	num--;
	return;
}//删除第n%len个元素
void ChainTable::Print() {
	if (head == NULL) {
		cout << endl;
		return;
	}
	TwoWayNode* p = head;
	while (p->next != head) {
		cout << p->value << " ";
		p = p->next;
	}
	cout << p->value << endl;
}

int Josephus_Linked(int n, int m) {
	ChainTable a;
	for (int i = 1; i <= n; i++) {
		a.Put(i);
	}
	
	TwoWayNode* p = a.head;
	while (a.num != 1) {
		for (int i = 0; i < m; i++) {
			p = p->next;
		}
		TwoWayNode* q = p->prev->prev;
		TwoWayNode* r = p->prev;
		cout << r->value << " ";
		if (p == q) {
			break;
		}
		q->next = p;
		p->prev = q;
		if (a.head == r) {
			a.head = p;
		}
		delete r;
	}
	return p->value;
}

int Josephus_Liner(int n, int m) {
	int* arr = new int[n + 1];
	for (int i = 1; i < n; i++) {
		arr[i] = i + 1;
	}
	arr[n] = 1;
	int p = n;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			p = arr[p];
		}
		cout << arr[p] << " ";
		arr[p] = arr[arr[p]];
	}
	return arr[p];
}

void testJose() {
	int n, m;
	cin >> n >> m;
	if (n > 2 && n < 101 && m>0 && m < 101) {
		cout << Josephus_Linked(n, m) << endl;//链表实现
		cout << Josephus_Liner(n, m) << endl;//数组实现
		cout << endl;
	}
	else {
		cout << "WRONG!" << endl;
	}
}

//-------------------------------------------------------------

int main() {
	testJose();
	return 0;
}