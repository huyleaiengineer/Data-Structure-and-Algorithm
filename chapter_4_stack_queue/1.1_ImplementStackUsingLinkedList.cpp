#include <bits/stdc++.h>
using namespace std;
#define MAX 200

struct Stack{
    int key;
    Stack *next;
    Stack (): key(0), next(nullptr){}
};


bool isEmpty(Stack *S)
{
    return S->key==0 && S->next == nullptr;
}


void Push(Stack *&S, int key)
{
    Stack *p = new Stack();
    p->key = key;
    p->next = S;
    S = p;
}

int Pop(Stack *&S)
{
    int x;
    if (isEmpty(S))
    {
        cout << "underflow\n";
        return -1;
    }else{
        Stack *p = S;
        S = p->next;
        x = p->key;
        //delete p;
        return x;
    }
}

void showStack(Stack *s)
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
    Stack *S;
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
                S = new Stack();
                //StackInitialize(S);
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
