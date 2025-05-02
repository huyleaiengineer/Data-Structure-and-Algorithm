#include <bits/stdc++.h>
using namespace std;

int a[100001], n;

/// T(n) = O(n)
int SequentialSearch(int a[], int n, int key)
{
    for (int i = 1; i <= n; ++i)
        if (a[i] == key)
            return i;
    return -1;
}

void readFile(string s)
{
    ifstream f(s);
    f >> n;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
}

int main()
{
    readFile("array2.txt");
    int keys[] = {0, -89, 678, 234, -2, -44};
    for (int i : keys)
    {
        int pos = SequentialSearch(a, n, i);
        if (pos!=-1)
            cout << "Phan tu co gia tri " << i << " nam o vi tri " << pos << endl;
        else
            cout << "Khong ton tai phan tu gia tri " << i << " trong mang\n";
    }
    return 0;
}
