#include <iostream>
using namespace std;

void minmax_iterative(int arr[], int n)
{
    int max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    cout << "Maximum Number : " << max << "\n";
    cout << "Minimum Number : " << min << "\n";
}