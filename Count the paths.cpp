class Solution 
{
  public:
   void dfs(vector<int>adj[],vector<int>&vis,int s,int d,int &ans)
   {
       if(s==d)
       {
           ans++;
           return;
       }
       vis[s]=true;
       for(auto it:adj[s])
       {
           if(vis[it]==false)
               dfs(adj,vis,it,d,ans);
       }
       vis[s]=false;
   }
   int possible_paths(vector<vector<int>>edges, int n, int s, int d)
   {
      vector<int>adj[n+1];
      for(int i=0;i<edges.size();i++)
         adj[edges[i][0]].push_back(edges[i][1]);
      vector<int>vis(n+1,false);
      int ans=0;
      dfs(adj,vis,s,d,ans);
      return ans;
   }
};
