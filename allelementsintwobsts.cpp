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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> tree1 = sortedlist(root1);
        vector<int> tree2 = sortedlist(root2);
        vector<int> res;
        int i=0,j=0;
        while(i<tree1.size() && j<tree2.size())
        {
            if(tree1[i]<tree2[j])
            {
                res.push_back(tree1[i]);
                i++;
            }
            else
                res.push_back(tree2[j++]);
        }
        while(i<tree1.size()) res.push_back(tree1[i++]);
        while(j<tree2.size()) res.push_back(tree2[j++]);
        return res;
    }
    vector<int> sortedlist(TreeNode* root)
    {   
        if(root==NULL) return vector<int>();
        vector<int> leftsorted = sortedlist(root->left);
        leftsorted.push_back(root->val);
        vector<int> right = sortedlist(root->right);
        leftsorted.insert(leftsorted.end(),right.begin(),right.end());
        return leftsorted;
    }
};