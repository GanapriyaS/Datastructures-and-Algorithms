#include "sort.h"
#include <iostream>
using namespace std;

void kthminmax(int arr[],int n)
{
  int k;
  cout<<"Enter kth value to find kth largest and smallest element :";
  cin>>k;
  sort(arr,n);
  cout<<"Kth Largest element : "<<arr[n-k];
  cout<<"Kth Smallest element : "<<arr[k-1];
}