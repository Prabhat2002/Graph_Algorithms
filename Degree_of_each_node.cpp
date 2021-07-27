
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int vis[n+1];
    for(int a=0;a<=n;a++)
    {
        vis[a]=0;
    }
    vector<int>v[n+1] ;
    for(int a=0;a<m;a++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<int>q;
    q.push(1);
    // vis[1]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=1;
        cout<<x<<"->"<<v[x].size()<<endl;
        for(auto a=v[x].begin();a!=v[x].end();a++)
        {
            if(!vis[*a])
            {
                q.push(*a);
                break;
            }
        }
    }
    return 0;
}
