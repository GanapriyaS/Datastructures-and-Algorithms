#include "swap.h"

void sort012(int arr[], int n)
{
  int low = 0, high = n - 1, mid = 0;
  while (mid <= high)
  {
    if (arr[mid] == 0)
      swap(&arr[low++], &arr[mid++]);
    else if (arr[mid] == 1)
      mid++;
    else if (arr[mid] == 2)
      swap(&arr[mid], &arr[high--]);
  }
}