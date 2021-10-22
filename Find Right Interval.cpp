class Solution {
public:
    vector<int>findRightInterval(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        vector<vector<int>>si(n); 
        for(int i=0;i<n;i++)
            si[i]={intervals[i][0], i};
        sort(si.begin(), si.end());
        vector<int>ans(n);
        for(int i = 0; i < n; i++)
        {
            vector<int> dummy = {intervals[i][1], -1};
            auto it = lower_bound(si.begin(), si.end(), dummy,
                [](const vector<int>& v1, const vector<int>& v2){
                    return v1[0] < v2[0];
                    });
            if(it==si.end())
                ans[i]=-1;
            else
                ans[i]=(*it)[1];
            
        }
        return ans;  
    }
};

// 1,2  2,3  3,4
// 3,4  2,3  1,2
