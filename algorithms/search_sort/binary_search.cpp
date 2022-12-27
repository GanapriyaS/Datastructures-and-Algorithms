// https://leetcode.com/problems/binary-search/

#include<iostream>
using namespace std;
int binarySearch(int arr[],int target,int n)
{
    int left = 0;
    int right = n - 1;
// >= is to search even array has single element
    while (right >= left){
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
void display(int a[],int n)
{
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main() {
  int n,target;
  cout<<"---------------------------------------------------"<<endl;
  cout << "ENTER THE NO OF ELEMENTS:";
  cin>>n;
  int a[n]={0};
  cout<<"ENTER THE ELEMENTS:"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<"ELEMENT "<<i+1<<":";
    cin>>a[i];
  }
  cout<<"---------------------------------------------------"<<endl;
  cout<<"ENTER ELEMENT TO BE SEARCH:";
  cin>>target;
  display(a,n);
  int index = binarySearch(a,target,n);
  if(index==-1){
    cout<<"\nELEMENT "<<target<<" NOT FOUND";
  }
  else{
    cout<<"\nELEMENT "<<target<<" FOUND AT INDEX "<<index;
  }
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}