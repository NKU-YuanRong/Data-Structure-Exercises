#include"Double_Ended_Queue.h"
#include<iostream>
using namespace std;

Double_Ended_Queue Double_Ended_Queue::Create(int MaxLen)
{
	if (MaxLen < 1) {
		cout << "不规范输入，设置默认长度为11" << endl;
		Double_Ended_Queue* q = new Double_Ended_Queue(11);
		return *q;
	}
	//Double_Ended_Queue* q = new Double_Ended_Queue(MaxLen);
	//return *q;
	return *(new Double_Ended_Queue(11));
}

bool Double_Ended_Queue::IsEmpty()
{
	//return length == 0;

	if (length == 0) {
		cout << "Yes" << endl;
		return true;
	}
	cout << "No" << endl;
	return false;
}


bool Double_Ended_Queue::IsFull()
{
	//return length == MAX_Length;
	if (length == MAX_Length) {
		cout << "Yes" << endl;
		return true;
	}
	cout << "No" << endl;
	return false;
}

int Double_Ended_Queue::Left()
{
	if (length == 0) {
		cout << "EMPTY" << endl;
		return -1;
	}
	cout << p[start] << endl;
	return p[start];
}

int Double_Ended_Queue::Right()
{
	if (length == 0) {
		cout << "EMPTY" << endl;
		return -1;
	}
	cout << p[(start + length - 1)%MAX_Length] << endl;
	return p[(start + length - 1) % MAX_Length];
}

bool Double_Ended_Queue::AddLeft(int n)
{
	if (length == MAX_Length) {
		cout << "FULL" << endl;
		return false;
	}

	start = (start + MAX_Length - 1) % MAX_Length;
	p[start] = n;
	/*
	if (start == 0) {
		start = MAX_Length - 1;
		p[start] = n;
	}
	else {
		start--;
		p[start] = n;
	}
	*/
	length++;
	Print();
	return true;
}

bool Double_Ended_Queue::AddRight(int n)
{
	if (length == MAX_Length) {
		cout << "FULL" << endl;
		return false;
	}
	p[(start + length) % MAX_Length] = n;
	length++;
	Print();
	return true;
}

bool Double_Ended_Queue::DeleteLeft()
{
	if (length == 0) {
		cout << "EMPTY" << endl;
		return false;
	}
	start = (start + 1) % MAX_Length;
	length--;
	Print();
	return true;
}

bool Double_Ended_Queue::DeleteRight()
{
	if (length == 0) {
		cout << "EMPTY" << endl;
		return false;
	}
	length--;
	Print();
	return true;
}

void Double_Ended_Queue::Print(){
	if (length == 0) {
		cout << endl;
		return;
	}
	for (int i = 0; i < length; i++) {
		cout << p[(start + i) % MAX_Length] << " ";
	}
	cout << endl;
}

void Double_Ended_Queue::PrintAll(){
	cout << endl;
	cout << "Start: " << start << endl;
	cout << "Length: " << length << endl;
	for (int i = 0; i < MAX_Length; i++) {
		cout << p[i] << endl;
	}
	cout << endl;
}
