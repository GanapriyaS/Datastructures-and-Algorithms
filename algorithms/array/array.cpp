#include <iostream>
using namespace std;
#include "display.h"
#include "intersection_noduplicate.h"

int main()
{
  int n, m;
  cout << "Enter total no of elements :";
  cin >> n;
  int arr[n];
  // int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Enter elements\n";
  for (int i = 0; i < n; i++)
  {
    cout << "Element " << i << " :";
    cin >> arr[i];
  }

  cout << "Enter total no of elements :";
  cin >> m;
  int arr1[m];
  // int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Enter elements\n";
  for (int i = 0; i < m; i++)
  {
    cout << "Element " << i << " :";
    cin >> arr1[i];
  }
  display(arr, n);
  display(arr1, m);
  intersection_noduplicate(arr, n, arr1, m);
  return 0;
}
