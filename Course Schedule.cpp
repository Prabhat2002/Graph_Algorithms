class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> nums) 
    {
        vector<int>ans;
        vector<int>adj[n];
        for(int i=0;i<m;i++)
            adj[nums[i][0]].push_back(nums[i][1]);
        map<int,int>mp;
        for(int i=0;i<n;i++)
        {
           vector<int>v=adj[i];
           for(auto j:v) 
               mp[j]++;
        }
        queue<int>pq;
        for(int i=0;i<n;i++)
        {
            if(mp[i]==0)
                pq.push(i);
            
        }
        
        if(pq.empty())
            return {};
        int i=0;
        while(!pq.empty())
        {
           int val=pq.front();
           pq.pop();
           ans.push_back(val);
           i++;
           for(auto x:adj[val])
           {
              mp[x]--;
              if(mp[x]==0)
                pq.push(x);
           }
        }        
        if(i!=n)
            return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
