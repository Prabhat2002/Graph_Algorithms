
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100];
stack<int>s;
int vis[100];
int DFS ()
{ 
    if(s.empty())
    {
        return 0;
    }
    else
    {
        int node=s.top();
        cout<<node<<endl;
        s.pop();
        for(auto i=adj[node].begin();i!=adj[node].end();i++)
        {
            if(!vis[*i])
            {
                vis[*i]=1;
                s.push(*i);
            }
        }
        DFS();
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
    s.push(1);
    vis[1]=1;
    DFS();
    cout<<"Thank you....";
    
}
