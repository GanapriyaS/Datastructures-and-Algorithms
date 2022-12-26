#include <iostream>
using namespace std;
#include <set>

void union_set(int a[], int n, int b[], int m)
{
    set<int> s;
    int max = m > n ? m : n;
    for (int i = 0; i < max; i++)
    {
        if (n <= max)
            s.insert(a[i]);
        if (m <= max)
            s.insert(b[i]);
    }
    cout << "Union of 2 arrays : ";
    for (auto i = s.begin(); i != s.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
}
