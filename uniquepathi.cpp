class Solution(object):
    def uniquePaths(self, m, n):
        dp = [ [0 for j in range(m)] for i in range(n)] 
                
        for i in range(n):
            for j in range(m):
                if( i==0 or j==0 ):                        # base case, for first row and first column, dp will have addition of values, as there is no other way.
                    dp[i][j] = 1
                else:                                       # Logic, find minimum cost to reach that cell from above and left.
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])
        return dp[-1][-1]


class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 1 || n <= 1){
            return 1;
        }
        
        vector<int> dp(n, 1);
        
        for (int i = 1; i < m; ++i){
            for (int j = 1; j < n; ++j){
                dp[j] += dp[j-1];
            }
        }
        
        return dp.back();
    }
};