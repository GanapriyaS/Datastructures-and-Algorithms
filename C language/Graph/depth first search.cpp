#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int v,e,j,k,start;
    stack<int>s;
    cout<<"ENTER THE NO OF VERTICES:";
    cin>>v;
    int g[v+1][v+1]={0};
    bool visited[v+1]={false};
    cout<<"ENTER THE NO OF EDGES:";
    cin>>e;
    cout<<"ENTER THE VERTICES OF THE EDGE CONNECTED:\n";
    for(int i=1;i<=e;i++)
    {
      cout<<"EDGE "<<i<<":";
      cin>>j>>k;
      g[j][k]=1;
    }
    cout<<"ENTER THE INTIAL VERTEX TO BE TRAVERSED FROM:";
    cin>>start;
    cout<<"\nBFS ORDER OF VISITED VERTICES:";
    s.push(start);
    while(!s.empty())
    {
      start=s.top();
        s.pop();
        if(!visited[start])
        cout << start << " ";
        visited[start]=true;
        for(int i=1;i<=v;i++)
            if(g[start][i] && !visited[i])
                s.push(i);
      }
    return 0;
}
