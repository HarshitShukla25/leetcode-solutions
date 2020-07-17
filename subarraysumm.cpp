
Subset Sum (Not subarray)

1. Backtracking

isSS(set,n,sum) = isSS(set,n-1,sum) || isSS(set,n-1,sum-set[n-1])


2. DP
ek side no. of elements doosre side sum

int dp[n+1][sum+1];
for(int i=0;i<n;i++)
dp[i][0]=true // zero sum hai to always true hoga
dp[0][i]= false;

but dp[0][0] =true;

dp[i][j] = dp[i-1][j] || dp[i-1][j-set[i-1]];

//GFG solution
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] 
                               || subset[i - 1][j - set[i - 1]]; 
        } 
    } 