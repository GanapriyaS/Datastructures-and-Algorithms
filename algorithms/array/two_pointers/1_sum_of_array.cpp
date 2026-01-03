#include<iostream>
using namespace std;

int sum(int arr[],int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
  {
    sum+=arr[i];
  }
  return sum;
}


int sum_two_pointers(int arr[],int n)
{
  int sum=0;
  int i=0,j=n-1;
  while(i<=j)
  {
    if (i==j)
    {
      sum+=arr[i];
      break;
    }
    sum+=arr[i]+arr[j];
    i++;
    j--;
  }

  return sum;
}

int main()
{
  int choice,n;

  cout<<"----------------------------------------------------------------------------"<<endl;
  cout<<"ENTER THE NO OF THE ELEMENTS:";
  cin>>n;

  int arr[n];
  
  for (int i = 0; i < n; i++)
  {
    cout<<"ENTER THE ELEMENT:";
    cin>>arr[i];
  }

  cout<<"SUM :"<<sum(arr,n)<<endl;
  cout<<"SUM USING TWO POINTERS :"<<sum_two_pointers(arr,n)<<endl;
  
    return 0;
  }
