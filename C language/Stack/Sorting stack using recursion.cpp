#include<iostream>
#include<stack>
#include<vector>
using namespace std;
stack<int>s;
void sortedInsert(int x)
{
  if(s.empty() || x>s.top())
  {
    s.push(x);
    return;
  }
  int temp=s.top();
  s.pop();
  sortedInsert(x);
  s.push(temp);
}
void sortStack()
{
  if(!s.empty())
  {
    int x=s.top();
    s.pop();
    sortStack();
    sortedInsert(x);
  }
}
void display()
{
  if(!s.empty())
  {
  int x=s.top();
  s.pop();
  display();
  cout<<x<<" ";
}
}
int main() {
  char c;
  int count=0,value;
  vector<int>v;
  cout<<"ENTER THE ELEMENTS:\n";
  do
  {
    cout<<"ELEMENT "<<++count<<":";
    cin>>value;
    v.push_back(value);
    s.push(value);
    cout<<"WANT TO PUSH THE ELEMENT AGAIN?Y/N:";
    cin>>c;
  }
  while(c=='y'|| c=='Y');
  cout<<"\nSTACK ELEMENTS BEFORE SORTING:";
  for(int i:v)
    cout<<i<<" ";
  sortStack();
  cout<<"\nSTACK ELEMENTS AFTER SORTING:";
  display();
  return 0;
}
