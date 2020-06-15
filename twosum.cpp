class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(target-nums[i])) 
            {
                vector<int> res;
                res.push_back(m[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            m[nums[i]]=i;
        }
        return vector<int>();
    }
};