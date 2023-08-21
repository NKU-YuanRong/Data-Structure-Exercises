#include<iostream>
//#include <stdio.h>
#define MAX_N 10

using namespace std;

int rcd[MAX_N], num[MAX_N] = { 1,2,3,4,5,6,7,8,9,10 };
int n;

void Print() {
    for (int i = 0; i < n; i++) {
        cout << rcd[i];
    }
    cout << endl;
}

void full_combination(int index, int p)//index：当前输出数量  p：输出偏移
{
    int i;
    //Print();
    //cout << index << "  " << p << endl;
    for (i = 0; i < index; i++)
    {
        cout << rcd[i];
        if (i < index - 1)
        {
            cout << " ";
        }
    }//rcd的前index个即为要输出的对象

    cout << endl;
    cout << endl;

    for (i = p; i < n; i++)
    {
        cout << i << endl;
        rcd[index] = num[i];
        full_combination(index + 1, i + 1);
    }
}

int main() {
    cin >> n;
    full_combination(0, 0);
    return 0;
}
/*
int read_data()
{
    int i;
    if (scanf("%d", &n) == EOF)
    {
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    return 1;
}

int main()
{
    while (read_data())
    {
        full_combination(0, 0);
    }
    return 0;
}
*/