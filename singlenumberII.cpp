class Solution {
public:
    int singleNumber(vector<int>& nums) {
         // faster than 68%
         // memory 100%
        // notes: every element appears for three time .
        // time complexity =  O(n);
        std::map<int,int> map;
        for(int i =0; i<nums.size();i++){
            map[nums[i]]++;
        }
        for(auto x:map){
            if(x.second == 1)
                return x.first;
        }
        return 0;
    }
};