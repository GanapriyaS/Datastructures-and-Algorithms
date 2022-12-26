#include <iostream>
#include "sort.h"
using namespace std;

void union_sort(int a[], int n, int b[], int m)
{
    sort(a, n);
    sort(b, m);
    int i = 0, j = 0;
    cout << "Union of 2 arrays : ";
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            cout << a[i++] << " ";
        else if (a[i] > b[j])
            cout << b[j++] << " ";
        else
        {
            cout << a[i++] << " ";
            j++;
        }
    }
    while (i < n)
        cout << a[i++] << " ";

    while (j < m)
        cout << b[j++] << " ";

    cout << endl;
}
