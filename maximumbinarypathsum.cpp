/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int helper(TreeNode* root,int &maxsum)
    {   if(root==NULL) return 0;
        
        int leftsum = max(helper(root->left,maxsum),0);
        int rightsum = max(helper(root->right,maxsum),0);
    
        maxsum = max(maxsum,leftsum+rightsum+root->val);
        return max(leftsum,rightsum)+root->val; //since ek sub-path hone ke lie tum ya to sirf ek node ho ya fir ek hi side se chali aa rhi chain.
       
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int maxsum=INT_MIN;
         helper(root,maxsum);
        return maxsum;
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int helper(TreeNode* root,int &maxsum)
    {   if(root==NULL) return 0;
        
        int leftsum = helper(root->left,maxsum);
        int rightsum = helper(root->right,maxsum);
        int option1 = leftsum+rightsum+(root->val);
        int option2 = root->val;
        int option3 = max(leftsum,rightsum) + root->val;
        maxsum = max(max(option1,option2),max(option3,maxsum));
        return max(option3,option2); //since ek sub-path hone ke lie tum ya to sirf ek node ho ya fir ek hi side se chali aa rhi chain.
       
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        int maxsum=INT_MIN;
         helper(root,maxsum);
        return maxsum;
    }
};