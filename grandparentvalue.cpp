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


///////////////////////////////////////
class Solution { //using the parent queue to manage both son and grandparent
public:
   void traversal(queue<TreeNode*>& parent, TreeNode* curr){
       // TreeNode* curr=root;
       if(curr==NULL)
           return;
       
       if(curr->val%2==0){
           if(curr->left!=NULL)
               parent.push(curr->left);
           if(curr->right!=NULL)
               parent.push(curr->right);
       }
       traversal(parent,curr->left);
       traversal(parent,curr->right);
   }
           
   int sumEvenGrandparent(TreeNode* root) {
       
       queue<TreeNode*> parent;
       traversal(parent,root);
       int sum=0;
       while(parent.empty()==false){
           TreeNode* curr=parent.front();
           parent.pop();
           if(curr->left!=NULL)
               sum+=(curr->left)->val;
           if(curr->right!=NULL)
               sum+=(curr->right)->val;
       }
       return sum;
   }
       
};