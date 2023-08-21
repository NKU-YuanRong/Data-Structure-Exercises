#ifndef CHAIN_NODE
#define CHAIN_NODE
#include<iostream>
using namespace std;

class CNode {
public:
    int col;
    int value;
    CNode* next;

    CNode(int c, int v) {
        col = c;
        value = v;
        next = NULL;
    }
    int operator !=(const CNode& y)
    {
        return (value != y.value);
    }
};

#endif