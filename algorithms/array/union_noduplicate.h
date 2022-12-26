#include <iostream>
#include "sort.h"
#include <cstring>
using namespace std;

void union_noduplicate(int a[], int n, int b[], int m)
{
    int max = a[0], max1 = b[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    for (int i = 0; i < m; i++)
        if (b[i] > max1)
            max1 = b[i];
    max = max > max1 ? max : max1;

    // Assuming max element present in array is not more than 10^7
    int temp[max + 1];
    memset(temp, 0, sizeof(temp));

    int max2 = m > n ? m : n;

    cout << "Union of 2 arrays : ";
    for (int i = 0; i < max2; i++)
    {
        if (n <= max2 && temp[a[i]] == 0)
        {
            temp[a[i]]++;
            cout << a[i] << " ";
        }
        if (m <= max2 && temp[b[i]] == 0)
        {
            temp[b[i]]++;
            cout << b[i] << " ";
        }
    }
    cout << "\n";
}
