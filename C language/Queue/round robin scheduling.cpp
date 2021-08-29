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
  cout<<"------------------------------------------------------------------------------"<<endl;
  cout<<"AT - Arrival Time \nBT - Burst Time \nWT - Waiting Time \nTAT - TurnAround Time \nCT - Completing Time \nRT - Response Time \nST - Starting Time \n";
  cout<<"-------------------------------------------------------------------------------"<<endl;
  int n,tot_tat=0,tot_wt=0,tot_rt=0,time_quantum,time,remain;
  cout<<"Enter the number of process:";
  cin>>n;
  remain=n;
  map<int,int>at;
  vector<int>bt(n);
  vector<int>tat(n);
  vector<int>wt(n);
  vector<int>ct(n);
  vector<int>st(n);
  vector<int>rem_bt(n);
  vector<int>rt(n);
  queue<int>q;
  cout<<"\nEnter the value of time quantum:";
  cin>>time_quantum;
  for(int i=0;i<n;i++)
  {
      cout<<"\nEnter the Burst time and arrival time for process:"<<i+1; cout<<endl;
      cout<<"Burst time:";
      cin>>bt[i];
      rem_bt[i]=bt[i];
      cout<<"Arrival time:";
      cin>>at[i];
  }
  vector<pair<int, int> > A;
  for (auto& it : at)
    A.push_back(it);
  sort(A.begin(), A.end(), cmp);
  vector<pair<int, int>>::iterator p=A.begin();
  time=p->second;
  q.push(p->first);
  int x;
  while(remain!=0)
 {
   if(q.empty())
   {
      p++;
      q.push(p->first);
      continue;
   }
   x=q.front();
   q.pop();
   if(rem_bt[x]==bt[x] )
   {
     st[x]=max(time,at[x]);
     time=st[x];
   }
   if(rem_bt[x]<=time_quantum && rem_bt[x]>0)
   {
     time+=rem_bt[x];
     remain--;
     rem_bt[x]=0;
     ct[x]=time;
     rt[x]=st[x]-at[x];
     tat[x]=time - at[x];
     wt[x]=tat[x]-bt[x];
     tot_wt+=wt[x];
     tot_tat+=tat[x];
     tot_rt+=rt[x];
     vector<pair<int, int>>::iterator k=p+1;
     for(;k!=A.end();k++)
     {
       if(k->second<=time)
       {
         q.push(k->first);
         p++;
       }
     }
   }
   else if(rem_bt[x]-time_quantum>0)
   {
     rem_bt[x]=rem_bt[x]-time_quantum;
     time+=time_quantum;
     vector<pair<int, int>>::iterator k=p+1;
     for(;k!=A.end();k++)
     {
       if(k->second<=time)
       {
         q.push(k->first);
         p++;
       }
     }
     q.push(x);
   }
 }
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"PROCESS \tBT \tAT \tST \tCT \tWT \tTAT \tRT"<<endl;
    for(int i=0;i<n;i++)
    {
    cout<<"P["<<i+1<<"]\t\t"<<bt[i]<<"\t"<<at[i]<<"\t"<<st[i]<<"\t"<<ct[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<"\t"<<rt[i];
    cout<<endl;
    }
    cout<<endl;
    cout<<"Average Waiting time:"<<(float)tot_wt/n<<"\n"; cout<<"Average Turnaround time:"<<(float)tot_tat/n<<"\n"; cout<<"Average Response time:"<<(float)tot_rt/n<<"\n";
    return 0;
    }
