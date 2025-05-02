#include <bits/stdc++.h>
using namespace std;
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    bool flag = true;
    while(flag)
    {
        cout << "LIST OF OPERATION\n";
        cout << "10. Stop Programing\n";
        cout << "\n-------------\nEnter your option: ";
        int opt;
        cin >> opt;
        switch(opt)
        {
            case 10:
                flag=false;
                break;
        }
    }
}
