class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i < nums.size();i++)
        {	if(i>reachable) return false;
        	if(reachable < nums[i]+i)
        		reachable=nums[i]+i;
        }
     
        return true;
    }
};