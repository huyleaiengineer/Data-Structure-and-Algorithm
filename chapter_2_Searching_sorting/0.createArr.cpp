#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    srand(time(nullptr));
    for (int i = 6; i <= 6; ++i)
    {
        ofstream f("array"+to_string(i)+".txt");
        cout << "n  = "; cin >> n;
        f << n << '\n';
        for (int j = 1; j <= n; ++j)
            f << rand()%(2*n)-n << ' ';
        f.close();
    }
}
