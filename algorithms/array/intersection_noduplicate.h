
#include <iostream>
#include "sort.h"
#include <vector>
#include <algorithm>
using namespace std;

void intersection_noduplicate(int a[], int n, int b[], int m)
{
    vector<int> temp;
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
            if (find(temp.begin(), temp.end(), a[i]) == temp.end())
            {
                temp.push_back(a[i]);
                cout << a[i++] << " ";
            }
            j++;
        }
    }
    cout << "\n";
}
