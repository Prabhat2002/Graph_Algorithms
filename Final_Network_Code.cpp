  
#include<bits/stdc++.h>
using namespace std;
#define N 1000
vector<pair<int,int>>adj[N+1] ;
vector<int>adj1[N+1];
float dege[N+1];
float accept_rate[N+1];
float flow_rate[N+1];
int visi[N+1];
int pros[N+1];
int prog[N+1];
int trans[N+1];
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

int DAW(int x,int d,int n)
{
   int source=x;
   priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
   vector<int>dist(n+1,INT_MAX);
   dist[source]=0;
   pq.push({0,source});
   float q=0;
   while(!pq.empty())
   {
       int distance=pq.top().first;
       int prev=pq.top().second;
       pq.pop();
       int p=100;
       for(auto i=adj[prev].begin();i!=adj[prev].end();i++)
       {
           int next=i->first;
           int nextDist=i->second;
           if(dist[next]>(dist[prev]+nextDist) && flow_rate[prev]/2<accept_rate[next])
           {
               dist[next]=dist[prev]+nextDist;
               pq.push({dist[next],next});
           }
          
       }
   }
   cout<<"The distance from source "<<source<<endl;
   cout<<source<<"->"<<d<<" => "<<dist[d]<<endl;
   return dist[d];
}

// Dikshtra Algorithm
int DA(int x,int d,int n)
{
   int source=x;
   priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;
   vector<int>dist(n+1,INT_MAX);
   dist[source]=0;
   pq.push({0,source});
   float q=0;
   while(!pq.empty())
   {
       int distance=pq.top().first;
       int prev=pq.top().second;
       pq.pop();
       int p=100;
       for(auto i=adj[prev].begin();i!=adj[prev].end();i++)
       {
           int next=i->first;
           int nextDist=i->second;
           if(dist[next]>(dist[prev]+nextDist) && flow_rate[prev]/2<accept_rate[next])
           {
               dist[next]=dist[prev]+dege[prev]+nextDist+trans[prev]+pros[prev]+prog[prev];
               pq.push({dist[next],next});
           }
          
       }
   }
   cout<<"The distance from source "<<source<<endl;
   cout<<source<<"->"<<d<<" => "<<dist[d]<<endl;
   return dist[d];
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
         if(mst[v]==false && wt < key[v])
         {
             par[v]=u;
             pq.push({key[v],v});
             key[v]=wt+trans[v]+pros[v]+prog[v]+dege[v];
         }
     }
   }
  for(int a=1;a<n;a++)
  {
      if(x==a)
        continue;
      else if(par[a]>=n)
        continue;
      else if(par[a]<=0)
        continue;
      else
         cout<<par[a]<<"->"<<a<<endl;
  }
}

void DFS(int u,int n, int d,int visit[])
{
    static int q=0;
    static int p=100;
    visit[u] =1;
    cout <<u<<" -> ";
     for(auto i:adj[u])
     {
         
         int v=i.first;
         int wt=i.second;
         if(p==0)
         {
             continue;
         }
         if(!visit[v] && d!=v && flow_rate[u]/2<accept_rate[i.first])
         {
             q=q+wt+dege[u]+trans[u]+pros[u]+prog[u];
             visit[v]=1;
             DFS(v,n,d,visit);
         }
         if(!visit[v] && d==v && flow_rate[u]/2<accept_rate[i.first])
         {
             visit[v]=1;
             q=q+wt+dege[u]+trans[u]+pros[u]+prog[u];
             cout<<v;
             cout<<endl<<"By DFS "<<endl;
             cout<<q;
             p=0;
             break;
         }
     }
}

int BFS(int x,int n,int d)
{
    int par[n];
    int key[n];
    bool mst[n];
    for(int a=0;a<n;a++)
    {
     key[a]=INT_MAX;
     mst[a]=false;
    }
    int vis[n+1];
    for(int a=0;a<n+1;a++)
    {
        vis[a]=0;
    }
    float q=0;
    key[x]=0;
    par[x]=-1;
    vis[x]=1;
    queue<pair<int,int>>pq;
    pq.push({key[x],x});
    while(!pq.empty())
    {
      int u=pq.front().second;
      pq.pop();
      mst[u]=true;
      cout<<u<<" -> ";
      int p=100; 
     for(auto i:adj[u])
     {
         int v=i.first;
         int wt=i.second;
         if(!vis[v] && d!=v && flow_rate[u]/2<accept_rate[i.first])
         {
             vis[v]=1;
             par[v]=u;
             cout<<v<<" -> ";
             pq.push({key[v],v});
             key[v]=wt;
             q=q+wt+dege[v]+trans[v]+pros[v]+prog[v];
         }
         if(!vis[v] && d==v && flow_rate[u]/2<accept_rate[i.first])
         {
             vis[v]=1;
             par[v]=u;
             cout<<v;
             pq.push({key[v],v});
             key[v]=wt;
             q=q+wt+dege[v]+trans[v]+pros[v]+prog[v];
             p=0;
             break;
         }
     }
     if(p==0)
           break;
    }
    cout<<endl<<"By BFS "<<endl;
    cout<<x<<" -> "<<d<<" => "<<q<<endl;
}
int main()
{
//   int n,m;
//   cout<<"Enter number of Nodes : ";
//   cin>>n;
//   cout<<"Enter number of Edges : ";
//   cin>>m;
//   cout<<"\nUSE NODE FROM 0 to "<<n-1<<endl<<endl;
//   for(int a=0;a<m;a++)
//   {
//       cout<<"Create Edge"<<endl;
//       int u,v,wt;
//       cout<<"Enter First Node : ";
//       cin>>u;
//       cout<<"Enter Second Node : ";
//       cin>>v;
//       cout<<"Edge created : "<<u<<"->"<<v<<endl<<endl;
//       wt=100+rand()%200;
//       adj[u].push_back(make_pair(v,wt));
//       adj[v].push_back(make_pair(u,wt));
//       adj1[u].push_back(v);
//       adj1[v].push_back(u);
//   }
  int arr[340]={ 7,1 , 8,1 , 11,1 , 12,1 , 13,1 , 22,1 , 23,1 , 34,1 , 35,1 , 37,1 , 39,1 , 7,2 , 8,2 , 9,2 , 11,2 , 12,2 , 13,2 , 22,2 , 23,2 , 35,2 , 36,2 , 39,2 , 14,3 , 15,3 , 16,3 , 17,3 , 18,3 , 36,3 , 39,3 , 17,4 , 36,4 , 37,4 , 39,4 , 6,5 , 34,5 , 35,5 , 39,5 , 7,6 , 35,6 , 39,6 , 8,7 , 9,7 , 11,7 , 12,7 , 13,7 , 35,7 , 39,7 , 9,8 , 10,8 , 20,8 , 21,8 , 22,8 , 23,8 , 24,8 , 35,8 , 38,8 , 39,8 , 10,9 , 35,9 , 36,9 , 39,9 , 35,10 , 36,10 , 39,10 , 19,11 , 35,11 , 36,11 , 39,11 , 19,12 , 26,12 , 35,12 , 36,12 , 38,12 , 39,12 , 35,13 , 36,13 , 38,13 , 39,13 , 25,14 , 26,14 , 27,14 , 28,14 , 29,14 , 36,14 , 39,14 , 19,15 , 25,15 , 26,15 , 27,15 , 28,15 , 29,15 , 36,15 , 39,15 , 19,16 , 27,16 , 36,16 , 39,16 , 36,17 , 39,17 , 19,18 , 25,18 , 26,18 , 27,18 , 29,18 , 32,18 , 36,18 , 39,18 , 33,19 , 36,19 , 38,19 , 39,19 , 36,20 , 38,20 , 39,20 , 33,21 , 36,21 , 38,21 , 39,21 , 27,22 , 28,22 , 30,22 , 31,22 ,32,22 , 33,22 , 35,22 , 36,22 , 38,22 , 39,22 , 30,23 , 32,23 , 33,23 , 35,23 , 36,23 , 38,23 , 39,23 , 36,24 , 38,24 , 39,24 , 36,25 , 38,25 , 39,25 , 36,26 , 38,26 , 39,26 , 30,27 , 36,27 , 38,27 , 39,27 , 36,28 , 38,28 , 39,28 , 36,29 , 38,29 , 39,29 , 36,30 , 38,30 , 39,30 , 32,31 , 36,31 , 38,31 , 39,31 , 36,32 , 38,32 , 39,32 , 36,33 , 38,33 , 39,33 , 37,34 , 36,35 , 37,35};
  int n=39;
  int m=170;
  int p=0;
  for(int a=0;a<m;a++)
  {
    //   cout<<"Create Edge"<<endl;
      int u,v,wt;
    //   cout<<"Enter First Node : ";
      u=arr[p++];
    //   cout<<"Enter Second Node : ";
      v=arr[p++];
      cout<<"Edge created : "<<u<<"->"<<v<<endl<<endl;
      wt=300+rand()%50;
      adj[u].push_back(make_pair(v,wt));
      adj[v].push_back(make_pair(u,wt));
      adj1[u].push_back(v);
      adj1[v].push_back(u);
  }
  for(int a=0;a<n;a++)
  {
      dege[a]=5+rand()%5;
      pros[a]=5+rand()%5;
      prog[a]=5+rand()%5;
      trans[a]=5+rand()%5;
      accept_rate[a]=10+rand()%20;
      flow_rate[a]=10+rand()%20;
  }
  for(int a=1;a<=n;a++)
  {
      visi[a]=0;
  }
  float q;
  float r;
      int s,d;
      cout<<"Enter Source :- ";
      cin>>s;
      cout<<"Enter destination :- ";
      cin>>d;
      cout<<endl;
      MST(s,n);
      cout<<endl;
      DFS(s,n,d,visi);
      cout<<endl;
      cout<<endl;
      BFS(s,n,d);
      cout<<endl;
      cout<<endl;
      int wd=DA(s,d,n);
      cout<<endl;
      int wod=DAW(s,d,n);
      float eff=wod*100/wd;
      cout<<endl<<"Efficiency : "<<eff<<"%";
  return 0;
}