#include <iostream>
using namespace std;
#include <set>

void insertion_set(int a[], int n, int b[], int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(a[i]);

    cout << "Intersection of 2 arrays : ";
    for (int i = 0; i < m; i++)
        if (s.find(b[i]) != s.end())
            cout << b[i] << " ";

    cout << "\n";
}
