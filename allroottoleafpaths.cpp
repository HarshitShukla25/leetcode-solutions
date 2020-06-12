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
    vector<string> res;
    void dfs(TreeNode* root,string s)
    {
        if(root==NULL) return ;
        if(root->left == NULL && root->right == NULL){
            
            s += to_string(root->val);
            res.push_back(s);
            return ;
        } 
         s += to_string(root->val)+"->";
        dfs(root->left,s);
        dfs(root->right,s);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        dfs(root,s);
        return res;
    }
};