class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	int n = nums.size();
        int presum[n+1];
        presum[0]=0;
        presum[1]=nums[0];
        for (int i = 1; i < n;i++)
        	presum[i+1]=presum[i-1]+nums[i];
        int c=0;
        for(int i = 1; i < =n;i++)
        {
        	for (int j = 0; j <i;j++)
        	{
        		if(presum[i]-presum[j]==k)
        			c++;
        	}
        }
        return c;
    }
};

int subarraySum(int* nums, int numsSize, int k){

int i,j,sum,c=0;
for(i=0;i<numsSize;i++)
{
    sum=nums[i];
    if(sum==k)
       c++;
    for(j=i+1;j<numsSize;j++)
    {
        sum=sum+nums[j];
        if(sum==k)
        c++;
    }
}
return c;
}
//best soln
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;int sum=0,cnt=0;
        mp[0]=1;     
        for(int i=0 ; i<nums.size() ; i++)
        {
            sum+=nums[i];
            if(mp.find(sum-k)!=mp.end()) cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};