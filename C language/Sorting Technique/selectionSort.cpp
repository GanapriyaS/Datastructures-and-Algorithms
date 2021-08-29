#include<iostream>
using namespace std;
int min(int a[],int n,int i)
{
  int min=i,j;
  for(j=i+1;j<n;j++)
    if(a[j]<a[min])
      min=j;
  return min;
}
void swap(int *a,int *b)
{
  int t=*a;
  *a=*b;
  *b=t;
}
void selectionSort(int a[],int n)
{
  for(int i=0;i<n-1;i++)
  {
    int j=min(a,n,i);
    swap(&a[i],&a[j]);
  }
}
void display(int a[],int n)
{
  for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main() {
  int n;
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
  cout<<"BEFORE SORTING:";
  display(a,n);
  selectionSort(a,n);
  cout<<"\nAFTER SORTING:";
  display(a,n);
  cout<<"\n---------------------------------------------------"<<endl;
  return 0;
}
