#include <iostream>
#include<vector>
#include<map>
#include<queue>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>& a, pair<int,int>& b)
{
return a.second < b.second;
}
int main()
{
  cout<<"-------------------------------------------------------------------------------"<<endl;
  cout<<"AT - Arrival Time \nBT - Burst Time \nWT - Waiting Time \nTAT - TurnAround Time \nCT - Completing Time \nST - Starting Time \n";
  cout<<"-----------------------------------------------------------------------------------------------"<<endl;
  int n,tot_tat=0,tot_wt=0;
  cout<<"Enter the number of process:";
  cin>>n;
  map<int,int>at;
  vector<int>bt(n);
  vector<int>tat(n);
  vector<int>wt(n);
  vector<int>ct(n);
  vector<int>st(n);
  for(int i=0;i<n;i++)
  {
    cout<<"\nEnter the Burst time and arrival time for process:"<<i+1; cout<<endl;
    cout<<"Burst time:";
    cin>>bt[i];
    cout<<"Arrival time:";
    cin>>at[i];
  }
  vector<pair<int, int> > A;
  for (auto& it : at)
    A.push_back(it);
  sort(A.begin(), A.end(), cmp);
  cout<<"-----------------------------------------------------------------------"<<endl; queue<int>q;
  for (auto& p : A)
    q.push(p.first);
  int a=0;
  int x;
  while(!q.empty())
  {
      x=q.front();
      q.pop();
      st[x]=max(at[x],a);
      ct[x]=st[x]+bt[x];
      tat[x]=ct[x]- at[x];
      wt[x]=tat[x]-bt[x];
      tot_wt+=wt[x];
      tot_tat+=tat[x];
      a=ct[x];
  }
  cout<<"PROCESS \tBT \tAT \tST \tCT \tWT \tTAT"<<endl;
  for(int i=0;i<n;i++)
  {
    cout<<"P["<<i+1<<"]\t\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<st[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i];
    cout<<endl;
  }
  cout<<endl;
  cout<<"Average Waiting time:"<<(float)tot_wt/n<<"\n"; cout<<"Average Turnaround time time:"<<(float)tot_tat/n;
  return 0;
}
