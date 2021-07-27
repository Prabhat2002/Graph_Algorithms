#include <bits/stdc++.h>
using namespace std;

#define N 100
vector<pair<int,int>>adj[N];
void DA(int x,int n)
{
   int source=x;
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
   for(int i=0;i<n;i++)
   {
            cout<<source<<"->"<<i<<" => "<<dist[i]<<endl;
   }
}
int main()
{
  int n,m;
  cin>>n>>m;
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
  cout<<endl<<"MST-"<<x+1<<endl;
  for(int a=1;a<n;a++)
  {
      cout<<par[a]<<"->"<<a<<endl;
  }
  DA(x,n);
  }
  return 0;
}
