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
    int sum,Left,Right;
    void dfs(TreeNode* root)
    {
        if(!root) return ;

        if((root->val)>=Left && (root->val)<=Right)
            sum+=root->val;
        dfs(root->left);
        dfs(root->right);
    }
    int rangeSumBST(TreeNode* root, int L, int R) {
        sum=0,Left=L,Right=R;
        dfs(root);
        return sum;
    }
};