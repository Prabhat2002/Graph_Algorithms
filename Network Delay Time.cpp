class Solution 
{
 public:
    int networkDelayTime(vector<vector<int>>& nums, int n, int S) 
    {
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >pq; 
       vector<int>dist(n+1,INT_MAX);
       dist[S]=0;
       pq.push({0,S});
       vector<vector<int>>adj[n+1];
       for(int i=0;i<nums.size();i++)
           adj[nums[i][0]].push_back({nums[i][1],nums[i][2]});
       while(!pq.empty())
       {
          int distance=pq.top().first;
          int prev=pq.top().second;
          pq.pop();
          for(auto i:adj[prev])
          {
              int next=i[0];
              int nextDist=i[1];
              if(dist[next]>(dist[prev]+nextDist))
              {
                 dist[next]=dist[prev]+nextDist;
                 pq.push({dist[next],next});
              }
          }
       }
       int sum=0; 
       for(int i=1;i<=n;i++)
       {
           if(dist[i]==INT_MAX)
               return -1;
           sum=max(sum,dist[i]);
       }
       return sum;
    }
};
