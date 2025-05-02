#include <iostream>
using namespace std;

void ArrTraversal(int a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << ' ';
    cout << '\n';
}

int main()
{
    int declarationArr[100];
    int a[] = {-3, 2, 4, 5, 2, 3, 8, 6}; /// Initialization
    int n = sizeof(a)/sizeof(a[0]); /// Numbers of elements in array
    /// Access a[2]
    cout << a[2] << '\n'; /// 4 --> O(1)
    /// Update a[3] = 8;
    cout << "Before updating: " <<  a[3] << '\n'; /// O(1)
    a[3] = 10;
    cout << "After updating: " <<  a[3] << '\n'; /// O(1)
    cout << "Array Travesal:\n";
    ArrTraversal(a, n); /// O(n)

    return 0;
}
