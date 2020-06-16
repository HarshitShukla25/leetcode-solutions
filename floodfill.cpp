class Solution {
public:
    bool flag[50][50];
     int globalimg[50][50];
    bool isReachable(int r,int c,int cmax,int rmax)
    {
        return (r<rmax)&&(c<cmax)&&(r>=0)&&(c>=0)&&(flag[r][c]==false);
    }
    void dfs(int r,int c,int col,int newColor,int cmax,int rmax)
    {   flag[r][c]=true;
        if(isReachable(r+1,c,cmax,rmax))
        {
            if(globalimg[r+1][c]==col)
            dfs(r+1,c, col, newColor, cmax, rmax);
        }
        if(isReachable(r,c+1,cmax,rmax))
        {
            if(globalimg[r][c+1]==col)
            dfs(r,c+1, col,newColor, cmax,rmax);
        }
        if(isReachable(r-1,c,cmax,rmax))
        {
            if(globalimg[r-1][c]==col)
            dfs(r-1,c,col,newColor,cmax,rmax);
        }
        if(isReachable(r,c-1,cmax,rmax))
        {
            if(globalimg[r][c-1]==col)
            dfs(r,c-1, col,newColor,cmax,rmax);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
       
        int col = image[sr][sc];
        int cmax = image[0].size();
        int rmax = image.size();
        
          for(int i=0;i<rmax;i++)
        {
            for(int j=0;j<cmax;j++)
            {
              globalimg[i][j] =image[i][j];
            }
         }
        dfs(sr,sc,col,newColor,cmax,rmax);
        for(int i=0;i<rmax;i++)
        {
            for(int j=0;j<cmax;j++)
            {
                if(flag[i][j]==true)
                    image[i][j]=newColor;
            }
        }
        return image;
    }
};