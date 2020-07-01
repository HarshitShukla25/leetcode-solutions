// not understood clearly
class Solution {
public:
 
    int deleteAndEarn(vector<int>& nums) {
    vector<int> sum(10001,0);
        vector<int> bins(10001,0);
        if (nums.size() == 0) 
        return 0;
    

    if (nums.size() == 1) 
        return nums[0];
    


    int maxVal = 0;

    for (int n : nums)
    {  bins[n]++;
        if (n > maxVal) {
            maxVal = n;
        }
    }

    sum[0] = bins[0];
    sum[1] = bins[1];

    for (int i = 2; i <= maxVal; i++) {
        sum[i] = max(sum[i - 2] + bins[i] * i, sum[i - 1]);
    }

    return sum[maxVal];
    }
};