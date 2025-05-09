#include <bits/stdc++.h>
using namespace std;
#define MAX 200

struct Stack{
    int a[MAX], top, N=MAX-1;
};

void StackInitialize(Stack &S)
{
    S.top = 0;
}

bool isEmpty(Stack S)
{
    return S.top == 0;
}

bool isFull(Stack S)
{
    return S.top == S.N;
}

void Push(Stack &S, int key)
{
    if (isFull(S))
        cout << "Overflow\n";
    else{
        S.a[++S.top] = key;
    }
}

int Pop(Stack &S)
{
    if (isEmpty(S))
    {
        cout << "underflow\n";
        return -1;
    }else{
        return S.a[S.top--];
    }
}

void showStack(Stack s)
{
    while (!isEmpty(s))
    {
        cout << Pop(s) << " ";
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
    Stack S;
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
                StackInitialize(S);
                break;
            }
            case 2:{
                cout << "Enter key = "; cin >> key;
                Push(S, key);
                break;
            }
            case 3:
                Pop(S);
                break;
            case 10:
                flag=false;
                break;
        }
        cout << "Curent Stack: "; showStack(S);
    }
}
