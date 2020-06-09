class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int sum=0,n= nums.size();
        for(auto s : nums) sum+= s;
        if(sum%2==1) return false;
        int target = sum/2;
        bool dp[n+1][target+1];
        
        for(int i=0;i<n+1;i++)
            dp[i][0]=true;
        for(int j=0;j<target+1;j++)
            dp[0][j]=false;
        for(int i = 1; i<=n;i++)
        {
            for(int j= 1;j<=target;j++)
            {
                
                if(nums[i-1]>j) dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
};