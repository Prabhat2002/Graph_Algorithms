#include<bits/stdc++.h> 
using namespace std;
const int N=1e5+6;
vector<int>parent(N);
vector<int>sz(N);
void make_set(int v)
{
    parent[v]=v;
    sz[v]=1;
}
int find_set(int v) 
{ 
    if(v==parent [v])
    {
        return v; 
    }
    return parent[v]=find_set(parent [v]); 
}

void unionn(int u, int v) 
{ 
    u=find_set(u);
    v=find_set(v); 
    
  if(u != v) 
  {
     if(sz[u]<sz[v])
     {
         swap(u,v);
     }
     parent[v]=u;
     sz[u]+=sz[v];
  }
}

int main() 
{
  for(int a=0;a<N;a++)
  {
      make_set(a);
  }
int n,m; 
cin >> n>>m;
vector<vector<int>> edges;

for (int i = 0; i<m;i++) 
{
    int u, v, wt;
    cin >> u >> v >> wt;
    edges.push_back({wt,u,v});
}

sort(edges.begin(), edges.end());

int cost = 0;
for (auto it : edges) 
{
  int w=it[0];
  int a=it[1];
  int b=it[2];
  int x=find_set(a);
  int y=find_set(b);
  if(x==y)
  {
      continue;
  }
  else
  {
      cout<<a<<"->"<<b<<endl;
      cost+=w;
      unionn(a,b);
  }
}
cout << cost << endl;
return 0;
}
