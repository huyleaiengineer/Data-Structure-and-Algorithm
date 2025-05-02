#include <bits/stdc++.h>
using namespace std;

void checkEmpty(vector<int> v)
{
    if (v.empty())
        cout << "Vector empty\n";
    else
        cout << "Vector is not empty\n";
}

void vectorTraversal(vector<int> v)
{
    for (int i : v)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    vector<int> v1; /// Empty vector
    /// Check empty vector
    checkEmpty(v1);
    cout << "Size of vector v1 = " << v1.size() << '\n';
    cout << "Vector v1: ";
    vectorTraversal(v1);

    vector<int> v3(5, 7);
    checkEmpty(v3);
    cout << "Size of vector v3 = " << v3.size() << '\n';
    cout << "Vector v3: ";
    vectorTraversal(v3);

    vector <int> v2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    checkEmpty(v2);
    cout << "Size of vector v2 = " << v2.size() << '\n';
    cout << "Vector v2 ";
    vectorTraversal(v2);

    /// Inserting

    v2.push_back(100); /// add in the end --> O(1)
    cout << "Size of vector v2 = " << v2.size() << '\n';
    cout << "Size of vector v2 = " << v2.size() << '\n';
    cout << "Vector v2 ";
    vectorTraversal(v2);

    v2.insert(v2.begin()+3, 1000);
    cout << "Size of vector v2 = " << v2.size() << '\n';
    cout << "Vector v2 ";
    vectorTraversal(v2);

    /// Accessing
    cout << v2.at(1) << '\n'; /// 2
    cout << v3[3] << '\n'; /// 7

    /// Updating
    v3[2] = 9999;
    cout << v3[2] << '\n'; /// 7

    /// Deleting
    v3.insert(v3.begin()+2, 100);
    cout << "Vector v3: ";
    vectorTraversal(v3);
    v3.pop_back();
    cout << "Vector v3: ";
    vectorTraversal(v3);
    v3.erase(find(v3.begin(), v3.end(), 100));
    cout << "Vector v3: ";
    vectorTraversal(v3);
    cout << "Reverse vector v3:\n";
    reverse(v3.begin(), v3.end());
    cout << "Vector v3: ";
    vectorTraversal(v3);
    vector<int> v4(v3.size());
    reverse_copy(v3.begin(), v3.end(), v4.begin());
    cout << "Reverse Vector v4: ";
    vectorTraversal(v4);

    cout << "Vector v2 ";
    vectorTraversal(v2);
    sort(v2.begin(), v2.end());
    cout << "After sorting acsending\n";
    cout << "Vector v2 ";
    vectorTraversal(v2);
    /// Method 1 - descending
    cout << "After sorting descending\n";
    sort(v2.rbegin(), v2.rend());
    cout << "Vector v2 ";
    vectorTraversal(v2);
    /// Method 2 - descending
    cout << "Vector v3: ";
    vectorTraversal(v3);
    sort(v3.begin(), v3.end(), [](int a, int b){return a > b;});
    cout << "Vector v3: ";
    vectorTraversal(v3);

    /// Swap 2 vector

    cout << "Vector v3: ";
    vectorTraversal(v3);
    cout << "Vector v2 ";
    vectorTraversal(v2);
    v2.swap(v3);
    cout << "Vector v3: ";
    vectorTraversal(v3);
    cout << "Vector v2 ";
    vectorTraversal(v2);

    /// remove duplicate in vector
    vector<int> v5 = {1, 2, 1, 4, 5, 6, 2, 4, 7, 1};
    cout << "vector v5 = " << endl;
    vectorTraversal(v5);
    sort(v5.begin(), v5.end()); /// O(nlogn)
    cout << "vector v5 = " << endl;
    vectorTraversal(v5);
    /// Move all duplicate into a vector
    auto it = unique(v5.begin(), v5.end());
    cout << "Vector it: " << *it << '\n';
    v5.erase(it, v5.end());
    cout << "vector v5 = " << endl;
    vectorTraversal(v5);

    return 0;
}
