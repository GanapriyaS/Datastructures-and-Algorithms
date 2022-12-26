#include <iostream>
using namespace std;

void count(int arr[], int n)
{
    int key, count = 0;
    cout << "Enter key element to count :";
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            count++;
        }
    }
    cout << "Element " << key << "Element count in an array : ";
    if (count)
        cout << count << endl;
    else
        cout << "Not Found\n";
}