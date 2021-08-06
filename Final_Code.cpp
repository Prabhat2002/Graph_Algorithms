#include<bits/stdc++.h>
using namespace std;
#define N 1000
vector<pair<int,int>>adj[N+1] ;
vector<int>adj1[N+1];
float dege[N+1];
float accept_rate[N+1];
float flow_rate[N+1];
// Degree 
int degree()
{
    int vis[N+1];
    for(int a=0;a<=N;a++)
    {
        vis[a]=0;
    }
    queue<int>q;
    q.push(0);
    int s,deg=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=1;
        if(deg<adj1[x].size())
        {
            s=x;
        }
        for(auto a=adj1[x].begin();a!=adj1[x].end();a++)
        {
            if(!vis[*a])
            {
                q.push(*a);
                break;
            }
        }
    }
    return s;
}

// Dikshtra Algorithm
void DA(int x,int d,int n,float qd)
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
   float t=dist[d]+qd;
   cout<<"The distance from source "<<source<<endl;
   cout<<source<<"->"<<d<<" => "<<t<<endl;
}
/*
5 6
1 2 3
1 4 5
2 4 7
1 3 8
0 3 2
0 1 7
*/
// MST 
float MST(int x,int n)
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
   key[x]=0;
   par[x]=-1;
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
         if(mst[v]==false && wt < key[v] && flow_rate[u]/2<accept_rate[i.first])
         {
             par[v]=u;
             pq.push({key[v],v});
             key[v]=wt;
         }
     }
  }
  float q=0;
//   cout<<endl<<"MST-"<<x+1<<endl;
  for(int a=0;a<n;a++)
  {
      if(a==x)
         continue;
      else if(par[a]>n)
      {
          continue;
      }
      else
      {
        cout<<par[a]<<"->"<<a<<endl;
        q=q+dege[a];
      }
  }
  return q;
}

int main()
{
  int n,m;
  cout<<"Enter number of Nodes : ";
  cin>>n;
  cout<<"Enter number of Edges : ";
  cin>>m;
  cout<<"\nUSE NODE FROM 0 to "<<n-1<<endl<<endl;
  for(int a=0;a<m;a++)
  {
      cout<<"Create Edge"<<endl;
      int u,v,wt;
      cout<<"Enter First Node : ";
      cin>>u;
      cout<<"Enter Second Node : ";
      cin>>v;
      cout<<"Edge created : "<<u<<"->"<<v<<endl;
      cout<<"Enter Assumed Time taken by node-"<<u<<" to node-"<<v<<" : ";
      cin>>wt;
      adj[u].push_back(make_pair(v,wt));
      adj[v].push_back(make_pair(u,wt));
      adj1[u].push_back(v);
      adj1[v].push_back(u);
  }
  
  for(int a=0;a<n;a++)
  {
      cout<<"Enter delay of node-"<<a<<" : ";
      cin>>dege[a];
      cout<<"Enter accept_rate of node-"<<a<<" : ";
      cin>>accept_rate[a];
      cout<<"Enter flow_rate of node-"<<a<<" : ";
      cin>>flow_rate[a];
  }
  char c;
  cout<<"Do you want to enter source and destination (y/n) :- ";
  cin>>c;
  float q;
  if(c=='y')
  {
      int s,d;
      cout<<"Enter Source :- ";
      cin>>s;
      cout<<"Enter destination :- ";
      cin>>d;
      q=MST(s,n);
      DA(s,d,n,q);
  }
  else
  {
     int d;
     cout<<"Enter destination :- (Source will be selected itsself on the bais of Degree)";
     cin>>d;
     int x=degree();
     q=MST(x,n);
     DA(x,d,n,q);
  }
  return 0;
}

//  while(!pq.empty())
//   {
//     int u=pq.top().second;
//       pq.pop();
//       if(mst[u])
//         continue;
//       mst[u]=true;
//      for(auto i:adj[u])
//      {
//          int v=i.first;
//          int wt=i.second;
//          if(mst[v]==false && wt < key[v])
//          {
//              par[v]=u;
//              pq.push({key[v],v});
//              key[v]=wt;
//          }
//      }
//  }