#include <iostream>
#include <utility>
using namespace std;

pair<int, int> distance(int a[], int n, int d)
{
    int left = 0;
    for (int right = 0; right < n; right++)
    {
        while (a[right] - a[left] > d) left++;
        if (a[right]-a[left] == d)
            return {left, right};
    }
    return {-1, -1};
}

int main()
{
   int a[] = {1, 2, 3, 7, 8};
   int n = sizeof(a)/sizeof(a[0]);
   int d = 4;
   pair <int, int> res = distance(a, n, d);
   if (res.first!=-1)
    cout << "Cap vi tri thoa mang la (" << res.first << ", " << res.second << ")\n";
   else
    cout << "Khong tim thay cap vi tri thoa de\n";



    return 0;
}
