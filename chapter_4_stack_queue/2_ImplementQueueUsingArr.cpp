#include <bits/stdc++.h>
using namespace std;
#define MAX 200

struct Queue{
    int a[MAX], head, tail, N=MAX-1;
};

void QueueInitialize(Queue &Q)
{
    Q.head = Q.tail = 1;
}

bool isEmpty(Queue Q)
{
    return Q.head == Q.tail;
}

bool isFull(Queue Q)
{
    return (Q.tail == Q.N && Q.head == 1) || Q.head == Q.tail+1;
}

void Push(Queue &Q, int key)
{
    if (isFull(Q))
        cout << "Overflow\n";
    else{
       Q.a[Q.tail] = key;
       if (Q.tail == Q.N)
        Q.tail = 1;
       else
        ++Q.tail;
    }
}

int Pop(Queue &Q)
{
    if (isEmpty(Q))
    {
        cout << "underflow\n";
        return -1;
    }else{
        int x = Q.a[Q.head];
        if (Q.head == Q.N)
            Q.head = 1;
        else
            ++Q.head;
        return x;
    }
}

void showQueue(Queue Q)
{
    while (!isEmpty(Q))
    {
        cout << Pop(Q) << " ";
    }
    cout << endl;
}

void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    bool flag = true;
    int key;
    Queue Q;
    while(flag)
    {
        cout << "LIST OF OPERATION\n";
        cout << "1. Initialization\n";
        cout << "2. Push\n";
        cout << "3. Pop\n";
        cout << "10. Stop Programing\n";
        cout << "\n-------------\nEnter your option: ";
        int opt;
        cin >> opt;
        switch(opt)
        {
            case 1:{
                QueueInitialize(Q);
                break;
            }
            case 2:{
                cout << "Enter key = "; cin >> key;
                Push(Q, key);
                break;
            }
            case 3:
                Pop(Q);
                break;
            case 10:
                flag=false;
                break;
        }
        cout << "Curent Queue: "; showQueue(Q);
    }
}
