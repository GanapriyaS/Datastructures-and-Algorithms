#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int v,e,j,k,s;
    queue<int>q;
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
    cin>>s;
    cout<<"\nBFS ORDER OF VISITED VERTICES:";
    q.push(s);
    while(!q.empty())
    {
      s=q.front();
        q.pop();
        if(!visited[s])
        cout << s << " ";
        visited[s]=true;
        for(int i=1;i<=v;i++)
            if(g[s][i] && !visited[i])
                q.push(i);
          }
    return 0;
}
