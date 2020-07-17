class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> vv;
        sort(nums.begin(),nums.end());
        backtrack(vv,nums,vector<int>(),0);
        int n=nums.size();
        
        return vv;
    }
    void backtrack(vector<vector<int>>& vv,vector<int> nums,vector<int> tmp,int start){
        vv.push_back(tmp);
        for(int i = start; i < nums.size(); i++){
        if(i > start && nums[i] == nums[i-1]) continue; // skip duplicates
        tmp.push_back(nums[i]);
        backtrack(vv, nums, tmp, i + 1);
        tmp.erase(tmp.end()-1);
    }
        

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> vv;
        sort(candidates.begin(),candidates.end());
        
        backtrack(vv,candidates,vector<int>(),target,0);
        return vv;
    }
    void backtrack(vector<vector<int>>& vv,vector<int> candidates,vector<int> tmp,int remain,int start)
    {
       if(remain<0) return ;
        else if(remain==0) vv.push_back(tmp);
        else
        {
            for(int i=start;i<candidates.size();i++)
            {
                tmp.push_back(candidates[i]);
                backtrack(vv,candidates,tmp,remain-candidates[i],i);
                tmp.erase(tmp.end()-1);
            }
        }
    }
 
};

Pick a starting point.
while(Problem is not solved)
    For each path from the starting point.
        check if selected path is safe, if yes select it
        and make recursive call to rest of the problem
        before which undo the current move.
    End For
If none of the move works out, return false, NO SOLUTON.

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vv;
        
        backtrack(vv,s,vector<string>(),0);
        return vv;
        
    }
    void backtrack(vector<vector<string>>& vv,string s,vector<string> tmp,int start)
    {
        if(start==s.size()) vv.push_back(tmp);
        else{
             for(int i=start;i<s.size();i++)
        {
            if(isPalindrome(s, start, i)){
            tmp.push_back(s.substr(start,i-start+1)); // imp
            backtrack(vv,s,tmp,i+1);
            tmp.erase(tmp.end()-1);}
        }
        }
       
    }
    bool isPalindrome(string s, int low, int high){
   while(low < high)
    if(s[low++] != s[high--]) return false;
   return true;
    }
};