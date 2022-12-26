#include <iostream>
#include "sort.h"
using namespace std;

void intersection_sort(int a[], int n, int b[], int m)
{
    sort(a, n);
    sort(b, m);
    int i = 0, j = 0;
    cout << "Intersection of 2 arrays : ";
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            i++;
        else if (a[i] > b[j])
            j++;
        else
        {
            cout << a[i++] << " ";
            j++;
        }
    }
    cout << endl;
}
