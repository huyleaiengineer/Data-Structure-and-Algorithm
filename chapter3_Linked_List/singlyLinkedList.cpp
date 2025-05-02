#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int key;
    ListNode *next;
    ListNode() : key(0), next(nullptr) {}
    ListNode(int x) : key(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : key(x), next(next) {}
};

void menu();

int main()
{
    menu();
    return 0;
}

bool isEmpty(ListNode *head)
{
    return head->key ==0 && head->next==nullptr;
}

void showList(ListNode *head)
{

    for (ListNode *x = head; x!=nullptr; x = x->next)
        cout << x->key << " -> ";
    cout << "NULL\n";
}

void insertAtBegin(ListNode *&head, int key)
{
    if (isEmpty(head)){
        head->key=key;
    }
    else

    {
        ListNode *tmp = new ListNode(key);
        tmp->next = head;
        head = tmp;
    }
}

void insertAtEnd(ListNode *&head, int key)
{
    if (isEmpty(head)){
        head->key=key;
    }
    else
    {
        ListNode *x = head;
        while (x->next != nullptr)
            x = x->next;
        ListNode *tmp = new ListNode(key);
        x->next = tmp;
    }
}
void insertAtPos(ListNode *&head, int pos, int key)
{
    if (isEmpty(head)){
        head->key=key;
    }
     else if (pos == 0)
        insertAtBegin(head, key);
    else
    {
        ListNode *x = head;
        int d = 1;
        while (x->next != nullptr){
            if (d == pos)
                break;
            x = x->next;
            ++d;
        }
        cout << "d = " << d << endl;
        cout << "x = " << x->key << endl;
        if (pos > d)
            insertAtEnd(head, key);
        else{
            ListNode *tmp = new ListNode(key);
            tmp->next = x->next;
            x->next = tmp;
        }
    }
}

void deletAtBegin(ListNode *&head)
{
    if (isEmpty(head))
        cout << "Empty list, can not remove\n";
    else{
        ListNode *x = head;
        head = head->next;
        delete x;
    }
}

void deletAtEnd(ListNode *&head)
{
    if (isEmpty(head))
        cout << "Empty list, can not remove\n";
    else{
        ListNode *x = head;
        while (x->next->next != nullptr)
            x = x->next;
        x->next = nullptr;
        delete x->next;
    }
}

ListNode *ListSearch(ListNode *head, int key)
{
    for (ListNode *x = head; x->next!=nullptr; x=x->next)
        if (x->key == key)
            return x;
    return new ListNode();
}


void deletNodeK(ListNode *&head, int pos)
{
    if (isEmpty(head))
        cout << "Empty list, can not remove\n";
    else if (pos == 0)
        deletAtBegin(head);
    else{
        int d = 0;
        ListNode *x = head;
        while(x->next != nullptr)
        {
            if (d == pos-1)
                break;
            x = x->next;
            ++d;
        }
        cout << "d = " << d << '\n';
        cout << "x->next->key = " << x->next->key << '\n';
        x->next = x->next->next;
        cout << "new x->key = " << x->key << '\n';

    }
}


void menu()
{
    bool flag = true;
    int key, pos;
    ListNode *head = new ListNode();
    insertAtBegin(head, 1);
    insertAtBegin(head, 2);
    insertAtBegin(head, 3);
    insertAtBegin(head, 4);
    insertAtBegin(head, 5);
    while(flag)
    {
        cout << "LIST OF OPERATION ON SINGLY LINKED LIST\n";
        cout << "1. Check Empty\n";
        cout << "2. Insert at the beginning\n";
        cout << "3. Insert at the end\n";
        cout << "4. Insert at any position\n";
        cout << "5. Delete at the beginning\n";
        cout << "6. Delete at the end\n";
        cout << "7. Delete at any position\n";
        cout << "8. Search at any position\n";
        cout << "9. Stop Programing\n";
        cout << "\n-------------\nEnter your option: ";
        int opt;
        cin >> opt;
        switch(opt)
        {
            case 1:
                if (isEmpty(head))
                    cout << "Empty List\n";
                else
                    cout << "Not Empty lits\n";
                break;
            case 2:
                cout << "Enter key = ";
                cin >> key;
                insertAtBegin(head, key);
                break;
            case 3:
                cout << "Enter key = ";
                cin >> key;
                insertAtEnd(head, key);
                break;
            case 4:
                cout << "Enter key = ";cin >> key;
                cout << "Enter position = "; cin >> pos;
                insertAtPos(head, pos, key);
                break;
            case 5:
                deletAtBegin(head);
                break;
            case 6:
                deletAtEnd(head);
                break;
            case 7:
                cout << "Enter position = "; cin >> pos;
                deletNodeK(head, pos);
                break;
            case 8:{
                cout << "Enter key = "; cin >> key;
                ListNode *node = ListSearch(head, key);
                if (isEmpty(node)){
                    cout << "Not exist node with key = " << key << '\n';
                }
                else{
                    cout << "Exist Key = " << node->key << '\n';
                }
                break;
            }
            case 9:
                flag=false;
                break;
        }
        cout << "Current List: ";
        showList(head);
        cout << "\n\n\n";
    }
}
