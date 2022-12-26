#include <iostream>
using namespace std;

int display(int arr[], int n)
{
    cout << "Elements present in an array :";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}