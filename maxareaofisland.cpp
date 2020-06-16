class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int m, int n,int& maxtemp) {
        
 		if (i < 0 || i >= m || j < 0 || j >= n) return;
 		if (grid[i][j] == 0 || visited[i][j]) return;
        maxtemp+=1;
       
 		visited[i][j] = true;
 		dfs(grid, visited, i+1, j, m, n,maxtemp);
 		dfs(grid, visited, i, j+1, m, n,maxtemp);
 		dfs(grid, visited, i-1, j, m, n,maxtemp);
 		dfs(grid, visited, i, j-1, m, n,maxtemp);
 	}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

 		int m = grid.size();
 		int n = grid[0].size();
 		vector<vector<bool>>visited(m, vector<bool>(n, false));

 		int res = 0;
 		for (int i = 0; i < m; i++) {
 			for (int j = 0; j < n; j++) {
 				if (grid[i][j] == 1 && !visited[i][j]) {
                    int maxtemp=0;
 					dfs(grid, visited, i, j, m, n,maxtemp);
 					res= max(maxtemp,res);
 				}
 			}
        }
        return res;
    }
};