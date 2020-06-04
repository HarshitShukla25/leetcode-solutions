class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
    	int n = nums.size();
    	if(nums.size()==0) return 0;
         vector<int> counts(n,0);
        int lis[n];
        lis[0]=1;
        counts[0]=1;


        for(int i=1;i<nums.size(); i++)
        {	lis[i]=1;
        	counts[i]=1;
        	for(int j=0;j<i;j++)
        	{
        		if(nums[i]>nums[j] )
        		{
        			if(lis[i] < lis[j] + 1)
        			{lis[i]= lis[j]+1;
        				counts[i] = counts[j]; //main ese hi chalta h dp k questions me ki jb kuch na ho rha ho to counts[i]=counts[j] krte rho
        			}
        			else if(lis[i]==lis[j]+1) 
        				counts[i]+=counts[j]; // aur jese is ques k hisaab se jab bhi same lis aaye bhale vo longest ho ya na ho to fir lis ki length k sath sath count bhi increase krte jao basically yaha count tumhara us particular element tk jitne b
        		}
        	}
        }
        int maxlen = *max_element(lis,lis+nums.size());
        int ans=0;
        for(int i=0; i<nums.size();i++)
        {
        	if(lis[i] == maxlen)
        	{
        		ans+=counts[i];
        	}
        }
        return ans;
    }
};