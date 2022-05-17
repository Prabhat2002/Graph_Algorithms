class Solution 
{
 public:
    bool valid(int i,int j,int col,vector<vector<int>>& image)
    {
        if(i>=0 && i<image.size() && j>=0 && j<image[0].size() &&  image[i][j]==col)
            return true;
        return false;
    }
    void call(vector<vector<int>>& image,int sr, int sc, int nc,int col)
    {
        image[sr][sc]=nc;
        if(valid(sr+1,sc,col,image))
            call(image,sr+1,sc,nc,col);
        if(valid(sr,sc-1,col,image))
            call(image,sr,sc-1,nc,col);
        if(valid(sr,sc+1,col,image))
            call(image,sr,sc+1,nc,col);
        if(valid(sr-1,sc,col,image))
            call(image,sr-1,sc,nc,col);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nc) 
    {
         int col=image[sr][sc];
         if(col==nc)
             return image;
         call(image,sr,sc,nc,col);
        return image;
    }
};
