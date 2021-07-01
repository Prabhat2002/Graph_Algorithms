
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int vis[n+1];
    for(int a=0;a<n+1;a++)
    {
        vis[a]=0;
    }
    vector <int>adj[n+1];
    for (int i=0;i<n;i++)
    {
        
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    vis[1]=1;
   //--BFS 
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<"\n";
        q.pop();
        for(auto i=adj[node].begin();i!=adj[node].end();i++)
        {
            if(!vis[*i])
            {
                vis[*i]=1;
                q.push(*i);
            }
        }
    }
    return 0;
}
