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