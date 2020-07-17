class Solution {
public:
    void getRange(vector<int>& nums, int target, vector<int>& output, int isLeft){
        int length = nums.size();
        int left = 0;
        int right = length-1;
        while(left<=right){
            int mid = (left + right)/2;
            if(target<nums[mid]) right = mid-1;
            else if(target>nums[mid]) left = mid+1;
            
            else{
                if(isLeft){
                    if(mid == 0 || nums[mid-1]!= target){
                        output[0]=mid;
                        return;
                    }
                    else right = mid-1;
                }else {
                    if(mid == length-1 || nums[mid+1]!=target){
                        output[1] = mid;
                        return;
                    }
                    else left = mid+1;
                }
            }
        }
        
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output(2,-1);
        getRange(nums, target, output, 1);
        getRange(nums, target, output, 0);
        return output;
    }
};