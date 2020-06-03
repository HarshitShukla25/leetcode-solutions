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
    int findHeight(TreeNode *curr,int &parent,int value,int height)
    {	
    	if(!curr) return 0;
    	if(curr->val == value) return height;
    	parent = curr->val;
    	int left = findHeight(curr->left,parent,value,height+1);
    	if(left) return left;
    	parent = curr->val;
    	int right = findHeight(curr->right,parent,value,height+1);
    	if(right) return right;


    }
    bool isCousins(TreeNode* root, int x, int y) {
    	if(root->val == x || root->val == y) return false;
    	int xparent = -1;
    	int xheight = findHeight(root,xparent,x,0);
    	int yparent = -1;
    	int yheight = findHeight(root,yparent,y,0);
    	if(xheight==yheight && xparent!=yparent )
    		return true;
    	return false;
    }
};

/*
class Solution {
public:
    bool traverse(TreeNode* root, int x, int y, int& x_l, int& y_l, int level) {
        if (!root)
            return false;
        if (root->left && root->right && ((root->left->val == x && root->right->val == y) ||
                                         (root->left->val == y && root->right->val == x)))
            return false;
        if (root->val == x) {
            x_l = level;
            if (y_l != -1 && x_l == y_l)
                return true;
        }
        if (root->val == y) {
            y_l = level;
            if (x_l != -1 && x_l == y_l)
                return true;
        }
        
        return traverse(root->left, x, y, x_l, y_l, level + 1) ||
            traverse(root->right, x, y, x_l, y_l, level + 1);
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        int x_l = -1, y_l = -1, level = 0;
        
        return traverse(root, x, y, x_l, y_l, level);
    }
};*/