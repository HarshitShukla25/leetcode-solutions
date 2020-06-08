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
    int valueofgrandchildren(TreeNode* root)
    {   int sum=0;
        if(root->left!=NULL)
        {
            if(root->left->left!=NULL) sum+=root->left->left->val;
            if(root->left->right!=NULL) sum+=root->left->right->val;
            
        }
        if(root->right!=NULL)
        {
            if(root->right->left!=NULL) sum+= root->right->left->val;
            if(root->right->right!=NULL) sum+= root->right->right->val;
        }
     return sum;
    }
    void dfs(TreeNode* root,int &res)
    {
        if(root==NULL) return ;
        if((root->val)%2==0)
        {
            res+=valueofgrandchildren(root);
        }
        dfs(root->left,res);
        dfs(root->right,res);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int res=0;
         dfs(root,res);
        return res;
        
    }
};