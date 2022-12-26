#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define edge pair<int, int>
class Graph {
   private:
  int edge_count=0,mincost=0;
  vector<pair<int, edge> > G;
  vector<pair<int, edge> > T;
  int *parent;
  int V;
   public:
  Graph(int V);
  void AddWeightedEdge(int u, int v, int w);
  int find_set(int i);
  void union_set(int u, int v);
  void kruskal();
  void print();
};
Graph::Graph(int V) {
  parent = new int[V];
  for (int i = 0; i < V; i++)
    parent[i] = i;

  G.clear();
  T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
  G.push_back(make_pair(w, edge(u, v)));
}
int Graph::find_set(int i) {
  if (i == parent[i])
    return i;
  else
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v) {
  parent[u] = parent[v];
}
void Graph::kruskal() {
  int i, uRep, vRep;
  sort(G.begin(), G.end());
  for (i = 0; i < G.size(); i++) {
    uRep = find_set(G[i].second.first);
    vRep = find_set(G[i].second.second);
    if (uRep != vRep) {
      T.push_back(G[i]);
      union_set(uRep, vRep);
    }
  }
}
void Graph::print() {
  for (int i = 0; i < T.size(); i++) {
      edge_count=edge_count+1;
      mincost=mincost+T[i].first;
      cout<<"Edge "<<edge_count<<":("<<T[i].second.first<<","<<T[i].second.second<<")   cost:"<<T[i].first<<endl;
  }
  cout<<"\nMinimum cost:"<<mincost;
}
int main() {
  int v,e,a,b,cost;
  cout<<"ENTER THE NO OF VERTICES:";
  cin>>v;
  cout<<"ENTER THE NO OF EDGES:";
  cin>>e;
  Graph g(v+1);
  cout<<"ENTER THE VERTICES OF THE EDGE CONNECTED:\n";
  for(int i=1;i<=e;i++)
  {
    cout<<"EDGE "<<i<<":";
    cin>>a>>b;
    cout<<"COST:";
    cin>>cost;
    g.AddWeightedEdge(a, b, cost);
  }
  g.kruskal();
  g.print();
  return 0;
}
