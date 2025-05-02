#include <bits/stdc++.h>
using namespace std;

/// T(n)= O(n^2)
pair<int, int> difference1(int a[], int n, int x)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (abs(a[i]-a[j])==x)
                return {i, j};
    return {-1, -1};
}

/// T(n)= O(nlogn)
int binarySearch(int a[], int left, int right, int key)
{
    if (left < right)
    {
        int mid = (left+right)/2;
        if (a[mid] == key)
            return mid;
        else if (key < a[mid])
            return binarySearch(a, left, mid-1, key);
        else
            return binarySearch(a, mid+1, right, key);
    }
    return -1;
}

pair<int, int> difference2(int a[], int n, int x)
{
    sort(a, a+n);
    for (int j = 0; j < n-1; ++j)
    {
        int i = binarySearch(a, j+1, n, x+a[j]);
        if (i!=-1)
        return {j, i};
    }
    return {-1, -1};

}

/// T(n)= O(nlogn)
pair<int, int> difference3(int a[], int n, int x)
{
    sort(a, a+n);
    int i = 0;
    for (int j = 0; j < n; ++j)
    {
        while (a[j]-a[i] > x) ++i;
        if (a[j]-a[i] == x)
            return {i, j};
    }
    return {-1, -1};

}


void showresult(int a[], int n, int x, pair<int, int> res)
{
    cout << "Khoang cach la = " << x << endl;
    if (res.first!=-1)
    cout << "Cap vi tri thoa mang la (" << res.first << ", " << res.second << " = (" << a[res.first] << ", " << a[res.second] <<").\n";
   else
    cout << "Khong tim thay cap vi tri thoa de\n";
}

int main()
{
    int arr1[] = {5, 20, 3, 2, 50, 80};
    int x1 = 78;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int arr2[] = {90, 70, 20, 80, 50};
    int x2 = 45;
    int n2 = sizeof(arr2)/sizeof(arr2[0]);

    cout << "Using exhuasted search\n";

    pair <int, int> res = difference1(arr1, n1, x1);
    showresult(arr1, n1, x1, res);
    res = difference1(arr2, n2, x2);
    showresult(arr2, n2, x2, res);


    cout << "\n----------\n";
    cout << "Using sorting + binary search\n";

    res = difference2(arr1, n1, x1);
    showresult(arr1, n1, x1, res);
    res = difference2(arr2, n2, x2);
    showresult(arr2, n2, x2, res);

     cout << "\n----------\n";
    cout << "Using sorting + 2 pointers\n";

    res = difference3(arr1, n1, x1);
    showresult(arr1, n1, x1, res);
    res = difference3(arr2, n2, x2);
    showresult(arr2, n2, x2, res);



    return 0;
}
