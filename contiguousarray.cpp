class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        if(nums.size()==0) return 0;
       unordered_map<int,int> s;
        s[0]=-1;
        int maxlen=0;
        for(int i=0;i<nums.size();i++)
        {
           
            if(nums[i]==0) sum--;
            else sum++;
            
            if(s.count(sum)) {
                maxlen=max(maxlen, i-s[sum]);
                continue;
            }
            s[sum]=i;
        }
        return maxlen;
    }
};