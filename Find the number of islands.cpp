Method : 1 

class Solution 
{
  public:
     bool valid(int i,int j,vector<vector<char>>&grid)
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() &&  grid[i][j]=='1')
            return true;
        return false;
    }
    void call(vector<vector<char>>&grid,int i, int j)
    {
        grid[i][j]='0';
        if(valid(i+1,j,grid))
            call(grid,i+1,j);
        if(valid(i-1,j+1,grid))
            call(grid,i-1,j+1);
        if(valid(i-1,j-1,grid))
            call(grid,i-1,j-1);
        if(valid(i+1,j-1,grid))
            call(grid,i+1,j-1);
        if(valid(i+1,j+1,grid))
            call(grid,i+1,j+1);    
        if(valid(i-1,j,grid))
            call(grid,i-1,j);
        if(valid(i,j+1,grid))
            call(grid,i,j+1);
        if(valid(i,j-1,grid))
            call(grid,i,j-1);
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                   ans++;
                   call(grid,i,j);
                }
            }
        }
        return ans;
    }
};


Method : 2 

class Solution 
{
  public:
     bool valid(int i,int j,vector<vector<char>>&grid)
    {
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() &&  grid[i][j]=='1')
            return true;
        return false;
    }
    void call(vector<vector<char>>&grid,int i, int j)
    {
        grid[i][j]='0';
        int dx[8] = {0,0,1,-1,-1,1,-1,1};
        int dy[8] = {1,-1,0,0,1,1,-1,-1};
        for(int k=0;k<8;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];
            if(valid(x,y,grid))
              call(grid,x,y);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int ans=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                   ans++;
                   call(grid,i,j);
                }
            }
        }
        return ans;
    }
};
