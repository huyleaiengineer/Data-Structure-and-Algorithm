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

void merge1(int a[], int left, int mid, int right)
{
    int n1 = mid-left+1, n2 = right-mid;
    int L[n1+1], R[n2+1];

    for (int i = 1; i <= n1; i++)
        L[i] = a[left+i];
    for (int i = 1; i <= n2; i++)
        R[i] = a[mid+1+i];
    int i = 1, j = 1, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            a[k] = L[i++];
        else
            a[k] = R[j++];
        ++k;
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int left, int right)
{
    if (left >= right)
        return;
    int mid = left + (right-left)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid+1, right);
    merge1(a, left, mid, right);
}
int main()
{
    string s;
    ofstream f("Merge_sort_report.OUTPUT");
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
            mergeSort(a, n);
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
