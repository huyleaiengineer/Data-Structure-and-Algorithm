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

void insertionSort(int a[], int n)
{
    for (int i = 2; i <= n; ++i)
    {
        int key = a[i], key_index = i-1;
        while (key_index > 0 && a[key_index] > key)
        {
            a[key_index+1]=a[key_index];
            key_index--;
        }
        a[key_index+1] = key;
    }
}
int main()
{
    string s;
    ofstream f("Insertion_sort_report.OUTPUT");
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
            insertionSort(a, n);
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
