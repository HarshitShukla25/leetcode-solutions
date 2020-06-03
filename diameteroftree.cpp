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
 #define f first
 #define s second
class Solution {
public:
	pair<int,int> diameter(TreeNode* root)
	{
	if(!root) return {0,0};
	pair<int,int> left = diameter(root->left);
	pair<int,int> right = diameter(root->right);
	return {max(left.f,right.f)+1,max(max(left.s,right.s),left.f+right.f+1)};
	}
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root) return 0;
        pair<int,int> result = diameter(root);
        return max(result.f, result.s)-1;
    }
};






////////////////////////////////////////////////////////////////////
class Solution {
public:
    int height(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int ls = height(root->left);
        int rs = height(root->right);
        return 1+max(ls,rs);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int hL = height(root->left);
        int hR = height(root->right);
        //Diameter passes through root
        int option1 = hL+hR;
        //Diameter lies in left subtree
        int option2 = diameterOfBinaryTree(root->left);
        //Diameter lies in right subtree
        int option3 = diameterOfBinaryTree(root->right);
		//return the best of these
        return max(option1,max(option2,option3));        
    }
};