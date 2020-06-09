class Solution {

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0, n = stones.size();
        for (auto s : stones) sum += s;
        int target = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= target; j++) {
                if (stones[i - 1] <= j)
                    dp[i][j] = max(dp[i - 1][j - stones[i - 1]] + stones[i - 1], dp[i - 1][j]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return sum - dp[n][target] - dp[n][target];
    }
};
