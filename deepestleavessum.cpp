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
public:
    int maxlevel;
    int maxdepth(TreeNode* root)
    {   if(!root) return 0;
        int l = maxdepth(root->left);
        int r = maxdepth(root->right);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
    void findsum(TreeNode* root,int &sum,int currlevel)
    {
        if(root==NULL) return ;
        
        if(root->left==NULL && root->right==NULL && currlevel+1 == maxlevel) //currlevel plus 1 islie kia since initially 0 se start kia
            sum+=root->val;
        
        findsum(root->left,sum,currlevel+1);
        findsum(root->right,sum,currlevel+1);
        
    }
    int deepestLeavesSum(TreeNode* root) {
         maxlevel = maxdepth(root);
        int sum=0;
        findsum(root,sum,0);
        return sum;
    }
};

//best soln-
class Solution {
    
    int sum;
    int maxDepth;
    
    public int deepestLeavesSum(TreeNode root) {
        
       return recuressiveSum(root,0);
    }
    
    public int recuressiveSum(TreeNode root,int count){
        
        if(root == null)
            return 0;
        count++;
        
        if(root.left == null && root.right == null){
            
            if(count>maxDepth){
                sum = 0;
                sum+=root.val;
                maxDepth = count;
            } else if(count == maxDepth)
                sum+=root.val;
        }
        recuressiveSum(root.left,count);
        recuressiveSum(root.right,count);
        return sum;
    }
    
    
}