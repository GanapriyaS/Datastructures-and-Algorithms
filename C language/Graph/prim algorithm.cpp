#include<iostream>
#define I 32167
using namespace std;
int main()
{
    int v,e,a,j,k,edge_count=0,mincost=0,cost;
    cout<<"ENTER THE NO OF VERTICES:";
    cin>>v;
    int g[v+1][v+1]={0};
    bool near[v+1]={false};
    cout<<"ENTER THE NO OF EDGES:";
    cin>>e;
    for (int i=0;i<=v;i++)
        for(int j=0;j<=v;j++)
            g[i][j]=I;
    cout<<"ENTER THE VERTICES OF THE EDGE CONNECTED:\n";
    for(int i=1;i<=e;i++)
    {
      cout<<"EDGE "<<i<<":";
      cin>>j>>k;
      cout<<"COST:";
      cin>>cost;
      g[j][k]=cost;
    }
    cout<<"ENTER THE STARTING EDGE:";
    cin>>a;
    near[a]=true;
    cout<<"\n---------------------------------------------------------------------------------------\n";
    while(edge_count< v-1)
    {
        int min=I,a=-1,b=-1;
        for(int i=0;i<=v;i++)
        {
            for(int j=0;j<=v;j++)
            {
                if(g[i][j]<min)
                {
                    if(i!=j && !(near[i]==false &&near[j]==false) && !(near[i]==true &&near[j]==true))
                    {
                        min=g[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        if(a!=-1 && b!=-1)
        {
            cout<<"Edge "<<edge_count<<":("<<a<<","<<b<<")   cost:"<<min<<endl;
            edge_count=edge_count+1;
            mincost=mincost+min;
            near[a]=near[b]=true;
        }
    }
    cout<<"\nMinimum cost:"<<mincost;
    return 0;
}
