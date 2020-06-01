class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size()==0) return vector<int>();
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> divCount(n,1);
        vector<int> prev(n,-1);
        int max_ind=0;
        for(int i=1;i<n;i++)
        {
          for(int j=0;j<i;j++)
          {
              if(nums[i]%nums[j]==0)
              {  if(divCount[i]<divCount[j]+1)
              {
                  divCount[i]=divCount[j]+1;
                  prev[i]=j;
              }}
             
          }
            if (divCount[max_ind] < divCount[i]) 
            max_ind = i; 
        }
        int k=max_ind;
        vector<int> res;
        while(k>=0)
        {
            res.push_back(nums[k]);
            k=prev[k];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};