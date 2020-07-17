S(n,k) - no. of partitions of n elements in k subsets

S(n,k) = k*S(n-1,k)(this means ki if we have found the ways to put n-1 elements in k subset to ab ek bacha hua number k tareeke se jaa skta h kyoki kisi bhi ek subset me chala jaega) + S(n-1,k-1) (mtlb k-1 sets the aur n-1 no. the To ye nth number ne new SEt bna lia)
hence 
S(n,k) = k*S(n-1,k)+ S(n-1,k-1)


// if k==1 or n (arrangement do no matter in a set) so we have to return 1

O(exponential)


//DP

int dp[n+1][k+1];
for(int i=0;i<n;i++)
{
	dp[i][0] = 0; // idhar mtlb no set to definitely 0
	dp[0][i]= 0 ; // idhar no elements to definitely 0
}

for(int i=1;i<=n;i++)
{
	for(int j=1;j<=i;j++)  //not k
	{
		if(j==1 || j==i)  same as k==1 or n
		{
			dp[i][j]=1;
		}
		else
		dp[i][j] = j*dp[i-1][j] + dp[i-1][j-1];
	}
}