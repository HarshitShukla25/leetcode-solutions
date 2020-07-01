class Solution {
public:
    TreeNode* ans = NULL;
    int depth = 0;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 1);
        return ans;
    }
    
    int dfs(TreeNode* root, int d) {
        if(!root) return d;
        int l = dfs(root->left, d + 1);
        int r = dfs(root->right, d + 1);
        if(l >= depth && r >= depth) {
            depth = max(l, r);
            ans = root;
        }
        return max(l, r);
    };