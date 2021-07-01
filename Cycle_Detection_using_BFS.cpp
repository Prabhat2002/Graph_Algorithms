#include <bits/stdc++.h> 
using namespace std; 
int N=100; 
int main() 
{ 
    int vis[100]; 
    for(int a=0;a<N;a++) 
    { 
        vis[a]=0; 
    } 
    int n,m; 
       cin>>n>>m; 
    vector<int>arr[n+1]; 
    for(int a=0;a<m;a++) 
    { 
        int x,y; 
        cin>>x>>y; 
        arr[x].push_back(y); 
        arr[y].push_back(x); 
    } 
    queue<pair<int,int>> q; 
    q.push({1,-1}); 
    vis[1]=1; 
    int temp=100; 
    while(!q.empty()) 
    { 
        int node=q.front().first; 
        int prev=q.front().second; 
        q.pop();
        for(auto i=arr[node].begin();i!=arr[node].end();i++) 
        { 
            if(!vis[*i]) 
            { 
                vis[*i]=1; 
                q.push({*i,node}); 
            } 
            else if(prev!=*i) 
            { 
                temp=0; break;
            } 
            else{} 
        } 
    } 
    if(temp==100) 
    { 
        cout<<"No cycle\n"; 
    } 
    else 
    { 
        cout<<"cycle\n";
    } 
}