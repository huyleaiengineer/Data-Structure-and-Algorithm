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

int Partition(int a[], int left, int right)
{
   int pivot = a[right], pivot_index = left-1;
   for (int i = left; i < right; ++i)
       if (a[i] <= pivot)
            swap(a[++pivot_index], a[i]);
   swap(a[right], a[pivot_index+1]);
   return pivot_index+1;
}

void quickSort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int mid = Partition(a, left, right);
    quickSort(a, left, mid-1);
    quickSort(a, mid+1, right);

}

int main()
{
    string s;
    ofstream f("Quick_sort_report.OUTPUT");
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
            quickSort(a, 1, n);
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
