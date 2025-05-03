#include <bits/stdc++.h>
using namespace std;
#define MAX 200

struct ListNode{
    int key;
    ListNode *next;
};

struct Queue{
    ListNode *head, *tail;
    Queue(): head(nullptr), tail(nullptr){}
};


bool isEmpty(Queue Q)
{
    return Q.head == nullptr;
}


void Push(Queue &Q, int key)
{
    ListNode *p = new ListNode();
    p->key = key;
    p->next = nullptr;
    if (isEmpty(Q))
        Q.head = p;
    else
        Q.tail->next=p;
    Q.tail = p;
}

int Pop(Queue &Q)
{
    if (isEmpty(Q))
    {
        cout << "underflow\n";
        return -1;
    }else{
        ListNode *p = Q.head;
        if (Q.head==Q.tail)
            Q.head = Q.tail = nullptr;
        else
            Q.head = p->next;
        return p->key;
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
        cout << "1. Is empty Queue\n";
        cout << "2. Push\n";
        cout << "3. Pop\n";
        cout << "10. Stop Programing\n";
        cout << "\n-------------\nEnter your option: ";
        int opt;
        cin >> opt;
        switch(opt)
        {
            case 1:{
                if (isEmpty(Q))
                    cout << "Empty queue\n";
                else
                    cout << "Not empty\n";
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
