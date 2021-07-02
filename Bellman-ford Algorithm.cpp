#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int n,m; 
  cin>>n>>m;
  vector<vector<int>>adj;
  for(int a=0;a<m;a++)
  {
      int u,v,wt;
      cin>>u>>v>>wt;
      adj.push_back({u,v,wt});
  }
  int source;
  cin>>source;
  int dist[n];
  int inf=100000;
 for(int a=0;a<n;a++)
 {
   dist[a]=inf;
 }
 dist[source]=0;
  for(int a=0;a<n-1;a++)
  {
      for(auto i:adj)
      {
         int u=i[0];
         int v=i[1];
         int w=i[2];
        //  cout<<u<<" "<<v<<" "<<w<<endl;
         if(dist[u]+w<dist[v])
         {
             dist[v]=dist[u]+w;
            //  cout<<dist[v];
         }
      }
  }
  
  int f1=0;
   for(auto i:adj)
      {
         int u=i[0];
         int v=i[1];
         int w=i[2];
         if(dist[u]+w<dist[v])
         {
             f1=1;
             cout<<"Negative Cycle";
             break;
         }
      }
    if(!f1)
    {
        for(int a=0;a<n;a++)
        {
            cout<<source<<"->"<<dist[a]<<endl;
        }
    }
}