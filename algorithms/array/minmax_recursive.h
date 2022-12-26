#include <iostream>
using namespace std;

int getMin(int arr[], int n)
{
    return (n == 1) ? arr[0] : min(arr[0], getMin(arr + 1, n - 1));
}

int getMax(int arr[], int n)
{
    return (n == 1) ? arr[0] : max(arr[0], getMax(arr + 1, n - 1));
}

void minmax_recursive(int arr[], int n)
{
    cout << "Maximum Number : " << getMin(arr, n) << "\n";
    cout << "Minimum Number : " << getMax(arr, n) << "\n";
}