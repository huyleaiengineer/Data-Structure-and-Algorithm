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

void selectionSort(int a[], int n)
{
    for (int i = 1; i < n; ++i){
        int min_index = i;
        for (int j = i; j <=n; ++j)
            if (a[j] < a[min_index])
                min_index = j;
        swap(a[i], a[min_index]);
    }
}

int main()
{
    string s;
    ofstream f("Selection_sort_report.OUTPUT");
    for (int i = 1; i <= 5; ++i)
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
            selectionSort(a, n);
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
