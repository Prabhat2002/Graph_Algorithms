
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100];
queue<int>q;
int vis[100];
int BFS()
{
   if(q.empty())
   {
       return 0;
   }
   else
   {
       int node=q.front();
       cout<<node<<endl;
       q.pop();
       for(auto i=adj[node].begin();i!=adj[node].end();i++)
       {
           if(!vis[*i])
           {
               vis[*i]=1;
               q.push(*i);
           }
       }
       BFS();  
   }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int a=0;a<100;a++)
        vis[a]=0;
    for(int a=0;a<m;a++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    q.push(1);
    vis[1]=1;
    int x=BFS();
    cout<<"Thank you....";
    
}
