#include <bits/stdc++.h>
using namespace std;

int a[1'000'001], n;


void readFile(string s)
{
    ifstream f(s);
    f >> n;
    for (int i = 1; i <= n; ++i)
        f >> a[i];
    f.close();
}

bool isSorted(int a[], int n)
{
     for (int i = 1; i < n; ++i)
        if (a[i] > a[i+1])
            return false;
    return true;
}

void bubleSort(int a[], int n)
{
    int head = 1;
    int tail = n;
    while (head <= tail)
    {
        for (int i = head; i <= tail; i++)
        {
            if (a[i] > a[tail])
                swap(a[i], a[tail]);
            else if (a[i] < a[head])
                swap(a[i], a[head]);
        }
        head++;
        tail--;
    }
}
int main()
{
    string s;
    ofstream f("Bubble_sort_report.OUTPUT");
    for (int i = 1; i <= 6; ++i)
    {
        s = "array"+to_string(i)+".txt";
        readFile(s);
        cout << s << ": n = " << n << "\n";
        if (isSorted(a,n))
        {
            cout << "Array is sorted!\n";
        }else{
            cout << "Array is unsorted\n";
        }
        clock_t st = clock();
            bubleSort(a, n);
        clock_t en = clock();
        if (isSorted(a,n))
        {
            cout << "Array is sorted!\n";
        }else{
            cout << "Array is unsorted\n";
        }
        cout << "Time = " << (en-st) << " ms\n";
        f << i << ". n = " << n << '\n';
        f<< "Time = " << (en-st) << " ms\n";
    }
    f.close();
    return 0;
}
