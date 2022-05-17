class Solution 
{
  public:
    void dfs(int src,vector<int>adj[],vector<int>&vis)
    {
        vis[src]=1;
        for(int i:adj[src])
        {
            if(vis[i]==0)
                dfs(i,adj,vis);
        }
    }
    int makeConnected(int n, vector<vector<int>>&nums) 
    {
        int m=nums.size();
        vector<int>adj[n];
        if(m<n-1)
            return -1;
        for(int i=0;i<m;i++)
        {
            adj[nums[i][0]].push_back(nums[i][1]);
            adj[nums[i][1]].push_back(nums[i][0]);
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ans++;
                dfs(i,adj,vis);
            }
        }
        return ans-1;
    }
};
