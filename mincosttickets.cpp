class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days[days.size()-1];
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
        	for(int j=0;j<days.size();j++)
        	{
        		if(days[j]==i)
     			dp[i] = min(dp[i-1]+costs[0],dp[max(0,i-7)]+costs[1],dp[max(0,i-30)]+costs[2]);
     			else
     			dp[i] = dp[i-1];
        	}
        }
        return dp[n];
    }
};