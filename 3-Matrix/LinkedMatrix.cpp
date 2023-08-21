#include"LinkedMatrix.h"
#include<iostream>
using namespace std;

LinkedMatrix::LinkedMatrix(int r, int c) {
    rows = r;
    cols = c;
    head = NULL;
}
int LinkedMatrix::Got(int r, int c) {
    HeadNode* ph = head;
    while (ph != NULL && ph->row < r) {
        ph = ph->nextRow;
    }
    if (ph == NULL || ph->row != r) {
        cout << "M(" << r << "," << c << ") = " << 0 << endl;
        return 0;
    }
    else {
        CNode* pc = ph->thisRow;
        while (pc != NULL && pc->col < c) {
            pc = pc->next;
        }
        if (pc == NULL || pc->col != c) {
            cout << "M(" << r << "," << c << ") = " << 0 << endl;
            return 0;
        }
        else {
            cout << "M(" << r << "," << c << ") = " << pc->value << endl;
            return pc->value;
        }
    }
}
void LinkedMatrix::Input(int r, int c, int v) {
    if (v == 0) {
        return;
    }
    HeadNode* ph = head;
    if (head == NULL) {
        head = new HeadNode(r);
        ph = head;
    }
    else {
        if (ph->row > r) {
            HeadNode* temp = new HeadNode(r);
            temp->nextRow = ph;
            head = temp;
            ph = temp;
        }
        else {
            while (ph->nextRow != NULL && ph->nextRow->row <= r) {
                ph = ph->nextRow;
            }
            if (ph->row != r) {
                HeadNode* temp = new HeadNode(r);
                temp->nextRow = ph->nextRow;
                ph->nextRow = temp;
                ph = temp;
            }
        }
    }

    CNode* pc = ph->thisRow;
    if (ph->thisRow == NULL) {
        ph->thisRow = new CNode(c, v);
        pc = ph->thisRow;
    }
    else {
        if (ph->thisRow->col > c) {
            CNode* newCNode = new CNode(c, v);
            newCNode->next = ph->thisRow;
            ph->thisRow = newCNode;
            pc = newCNode;
        }
        else {
            while (pc->next != NULL && pc->next->col <= c) {
                pc = pc->next;
            }
            if (pc->col != c) {
                CNode* temp = new CNode(c, v);
                temp->next = pc->next;
                pc->next = temp;
            }
            else {
                pc->value = v;
            }
        }
    }
}
void LinkedMatrix::Add(LinkedMatrix& b, LinkedMatrix& c) {
    //*this和b相加，结果保存在c中,即c = *this + b
    if (rows != b.rows || cols != b.cols) {
        cout << "不能相加！" << endl;
        return;
    }
    c.rows = rows;
    c.cols = cols;
    HeadNode* pha = head;
    HeadNode* phb = b.head;
    while (pha != NULL && phb != NULL) {
        if (pha->row < phb->row) {
            CNode* pca = pha->thisRow;
            while (pca != NULL) {
                c.Input(pha->row, pca->col, pca->value);
                pca = pca->next;
            }
            pha = pha->nextRow;
        }
        else if (pha->row > phb->row) {
            CNode* pcb = phb->thisRow;
            while (pcb != NULL) {
                c.Input(phb->row, pcb->col, pcb->value);
                pcb = pcb->next;
            }
            phb = phb->nextRow;
        }
        else {
            CNode* pca = pha->thisRow;
            CNode* pcb = phb->thisRow;
            while (pca != NULL && pcb != NULL) {
                if (pca->col < pcb->col) {
                    c.Input(pha->row, pca->col, pca->value);
                    pca = pca->next;
                }
                else if (pca->col > pcb->col) {
                    c.Input(phb->row, pcb->col, pcb->value);
                    pcb = pcb->next;
                }
                else {
                    int tvalue = pca->value + pcb->value;
                    if (tvalue != 0) {
                        c.Input(pha->row, pca->col, tvalue);
                    }
                    pca = pca->next;
                    pcb = pcb->next;
                }
            }
            while (pca != NULL) {
                c.Input(pha->row, pca->col, pca->value);
                pca = pca->next;
            }
            while (pcb != NULL) {
                c.Input(phb->row, pcb->col, pcb->value);
                pcb = pcb->next;
            }
            pha = pha->nextRow;
            phb = phb->nextRow;
        }
    }
    while (pha != NULL) {
        CNode* pca = pha->thisRow;
        while (pca != NULL) {
            c.Input(pha->row, pca->col, pca->value);
            pca = pca->next;
        }
        pha = pha->nextRow;
    }
    while (phb != NULL) {

        CNode* pcb = phb->thisRow;
        while (pcb != NULL) {
            c.Input(phb->row, pcb->col, pcb->value);
            pcb = pcb->next;
        }
        phb = phb->nextRow;
    }
}
void LinkedMatrix::Minus(LinkedMatrix& b, LinkedMatrix& c) {
    //*this和b相减，结果保存在c中,即c = *this - b
    if (rows != b.rows || cols != b.cols) {
        cout << "不能相减！" << endl;
        return;
    }
    c.rows = rows;
    c.cols = cols;
    HeadNode* pha = head;
    HeadNode* phb = b.head;
    while (pha != NULL && phb != NULL) {
        if (pha->row < phb->row) {
            CNode* pca = pha->thisRow;
            while (pca != NULL) {
                c.Input(pha->row, pca->col, pca->value);
                pca = pca->next;
            }
            pha = pha->nextRow;
        }
        else if (pha->row > phb->row) {
            CNode* pcb = phb->thisRow;
            while (pcb != NULL) {
                c.Input(phb->row, pcb->col, -pcb->value);
                pcb = pcb->next;
            }
            phb = phb->nextRow;
        }
        else {
            CNode* pca = pha->thisRow;
            CNode* pcb = phb->thisRow;
            while (pca != NULL && pcb != NULL) {
                if (pca->col < pcb->col) {
                    c.Input(pha->row, pca->col, pca->value);
                    pca = pca->next;
                }
                else if (pca->col > pcb->col) {
                    c.Input(phb->row, pcb->col, -pcb->value);
                    pcb = pcb->next;
                }
                else {
                    int tvalue = pca->value - pcb->value;
                    if (tvalue != 0) {
                        c.Input(pha->row, pca->col, tvalue);
                    }
                    pca = pca->next;
                    pcb = pcb->next;
                }
            }
            while (pca != NULL) {
                c.Input(pha->row, pca->col, pca->value);
                pca = pca->next;
            }
            while (pcb != NULL) {
                c.Input(phb->row, pcb->col, -pcb->value);
                pcb = pcb->next;
            }
            pha = pha->nextRow;
            phb = phb->nextRow;
        }
    }
    while (pha != NULL) {
        CNode* pca = pha->thisRow;
        while (pca != NULL) {
            c.Input(pha->row, pca->col, pca->value);
            pca = pca->next;
        }
        pha = pha->nextRow;
    }
    while (phb != NULL) {

        CNode* pcb = phb->thisRow;
        while (pcb != NULL) {
            c.Input(phb->row, pcb->col, -pcb->value);
            pcb = pcb->next;
        }
        phb = phb->nextRow;
    }
}
void LinkedMatrix::Transpose(LinkedMatrix& b) {
    b.cols = rows;
    b.rows = cols;
    HeadNode* ph = head;
    while (ph != NULL) {
        CNode* pc = ph->thisRow;
        while (pc != NULL) {
            b.Input(pc->col, ph->row, pc->value);
            pc = pc->next;
        }
        ph = ph->nextRow;
    }
}
void LinkedMatrix::Multiply(LinkedMatrix& bt, LinkedMatrix& c) {
    if (cols != bt.rows) {
        cout << "不能相乘！" << endl;
        return;
    }
    c.rows = rows;
    c.cols = bt.cols;
    LinkedMatrix b(1, 1);
    bt.Transpose(b);//b为bt转置后的矩阵，方便乘法运算
    HeadNode* pha = head;

    while (pha != NULL) {
        HeadNode* phb = b.head;
        while (phb != NULL) {
            int rec = 0;
            CNode* pca = pha->thisRow;
            CNode* pcb = phb->thisRow;
            while (pca != NULL && pcb != NULL) {
                if (pca->col < pcb->col) {
                    pca = pca->next;
                }
                else if (pca->col > pcb->col) {
                    pcb = pcb->next;
                }
                else {
                    rec += pca->value * pcb->value;
                    pca = pca->next;
                    pcb = pcb->next;
                }
            }
            if (rec != 0) {
                c.Input(pha->row, phb->row, rec);
            }
            phb = phb->nextRow;
        }
        pha = pha->nextRow;
    }
}
void LinkedMatrix::Print() {
    HeadNode* ph = head;
    while (ph != NULL) {
        CNode* pc = ph->thisRow;
        while (pc != NULL) {
            cout << "M(" << ph->row << "," << pc->col << ") = " << pc->value << endl;
            pc = pc->next;
        }
        //cout << "------------------------------" << endl;
        ph = ph->nextRow;
    }

}
istream& operator>> (istream& in, LinkedMatrix& a) {
    cout << "Enter number of rows, columns, and terms" << endl;
    int terms = 0;
    in >> a.rows >> a.cols >> terms;
    int LastRow = 0, LastCol = 0, i = 0;
    int ThisRow, ThisCol, Val;
    while (i < terms) {
        cout << "Enter row, column, and value of term " << i + 1 << endl;
        in >> ThisRow >> ThisCol >> Val;

        if (Val == 0) {
            cout << "Can't input 0 as value" << endl;
            continue;
        }//检查输入是否为0
        if (ThisRow <= 0 || ThisCol <= 0 || ThisRow > a.rows || ThisCol > a.cols) {
            cout << "Invalid row and volumn!" << endl;
            continue;
        }//检查行号列号是否有效
        if (ThisRow < LastRow) {
            cout << "Not row major order" << endl;
            continue;
        }
        else if (ThisRow == LastRow && ThisCol <= LastCol) {
            cout << "Not row major order" << endl;
            continue;
        }//检查是否行主次序输入

        a.Input(ThisRow, ThisCol, Val);
        LastRow = ThisRow;
        LastCol = ThisCol;
        i++;
    }
    return in;
}