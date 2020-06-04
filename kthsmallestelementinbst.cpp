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
	void inorder(TreeNode *curr,vector<int> &inarray)
	{
		inorder(curr->left,inarray);
		inarray.push_back(curr->val);
		inorder(curr->right,inarray);
	}
public:
    int kthSmallest(TreeNode* root, int k) {
    	vector<int> inarray;
        inorder(root,inarray);
        return inarray[k-1];
    }
};