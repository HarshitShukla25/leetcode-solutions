//TLE soln by me,dp is better
class Solution {
public:
    int count;
    void dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()) return ;
        if(grid[i][j]==2 || grid[i][j]==1) // visited or obstructed
            return ;
        if(grid[i][j]==4) {count++;return ;}
        grid[i][j]=2;
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        grid[i][j]=0;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m= grid.size();
        int n= grid[0].size();
        if(grid[m-1][n-1]==1) return 0;
        grid[m-1][n-1]=4; //finish
        dfs(0,0,grid);
        return count;
    }
}; 

// dp better soln
class Solution {
public:
   
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        if(m==0 || grid[0][0]==1) return 0; 
        dp[0][0]=1;
        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1) break;
            else
                dp[i][0]=1;
        }
        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1) break;
            else
                dp[0][j]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {   if(grid[i][j]==1) dp[i][j]=0;
                
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};


// dp best soln
