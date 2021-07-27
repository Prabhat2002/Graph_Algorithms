#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,m;//n=number of vertex m=number of edges
  cin>>n>>m;
  vector<pair<int,int>>adj[n];
  for(int a=0;a<m;a++)
  {
      int x,y,wt;
      cin>>x>>y>>wt;
      adj[x].push_back(make_pair(y,wt));
      adj[y].push_back(make_pair(x,wt));
  }
  
  for(int x=0;x<n;x++)
  {
  int par[n];
  int key[n];
  bool mst[n];
  for(int a=0;a<n;a++)
  {
     key[a]=INT_MAX;
     mst[a]=false;
  }
 
  priority_queue< pair<int,int>, vector< pair<int,int>> ,greater<pair<int,int>> >pq;
  key[0]=0;
  par[0]=-1;
  pq.push({key[x],x});
  for(int a=0;a<n-1;a++)
  {
     int u=pq.top().second;
     pq.pop();
     mst[u]=true;
     
     for(auto i:adj[u])
     {
         int v=i.first;
         int wt=i.second;
         if(mst[v]==false && wt < key[v])
         {
             par[v]=u;
             pq.push({key[v],v});
             key[v]=wt;
         }
     }
  }
  cout<<endl<<endl<<"MST-"<<x+1<<endl<<endl;
  for(int a=1;a<n;a++)
  {
      cout<<par[a]<<"->"<<a<<endl;
  }
  
  cout<<endl<<endl;
  }
  return 0;
}
