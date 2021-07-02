#include <bits/stdc++.h>
using namespace std;
int main() 
{
  int n,m; 
  cin>>n>>m;
  vector<pair<int,int>>adj[n+1];

  for (int i=0;i<m;i++) 
   {
     int u, v, wt;
     cin >> u >> v >> wt;
     adj[v].push_back({u,wt});
     adj[u].push_back({v,wt});
   }
   int source;
   cin>>source;
   priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
   vector<int>dist(n+1,INT_MAX);
   dist[source]=0;
   pq.push({0,source});
   while(!pq.empty())
   {
       int distance=pq.top().first;
       int prev=pq.top().second;
       pq.pop();
       for(auto i=adj[prev].begin();i!=adj[prev].end();i++)
       {
           int next=i->first;
           int nextDist=i->second;
           if(dist[next]>(dist[prev]+nextDist))
           {
               dist[next]=dist[prev]+nextDist;
               pq.push({dist[next],next});
           }
       }
   }
   cout<<"The distance from source "<<source<<endl;
   for(int i=1;i<=n;i++)
   {
       cout<<source<<"->"<<dist[i]<<endl;
   }
}