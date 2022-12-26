#include <iostream>
using namespace std;

void reverse_recursive(int arr[],int start,int end){
    if (start >= end)
    return;
     
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
     
    reverse_recursive(arr, start + 1, end - 1);   
}