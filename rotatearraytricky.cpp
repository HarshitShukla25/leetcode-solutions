class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1) return ;  // [-1]
        reverse(nums.end()-k%nums.size(),nums.end()); // [1,2] me 3 likha ho isilie modulus
        reverse(nums.begin(),nums.end()-k%nums.size());
        
        reverse(nums.begin(),nums.end());
    }
};