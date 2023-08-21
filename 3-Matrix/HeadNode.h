#ifndef HEAD_NODE
#define HEAD_NODE
#include<iostream>
#include"CNode.h"
using namespace std;

class HeadNode {
public:
    int row;
    CNode* thisRow;
    HeadNode* nextRow;

    HeadNode(int r) {
        row = r;
        thisRow = NULL;
        nextRow = NULL;
    }
    int operator !=(const HeadNode& y)
    {
        return (row != y.row);
    }
};

#endif