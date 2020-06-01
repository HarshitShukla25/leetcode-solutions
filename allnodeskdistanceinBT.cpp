class Solution {
public:
unordered_map<TreeNode*, TreeNode*>parentNode;

void preorder(TreeNode *root, TreeNode *parent){
// stores parent of every node in hashmap

    if(root==NULL)
        return;
    parentNode[root]=parent;
    preorder(root->left, root);
    preorder(root->right, root);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    
    preorder(root, NULL);
    int level=0;
    
    queue<TreeNode *>q;
    set<TreeNode *>visited;
	
	//initialize queue and visited with target node
	
    q.push(target);
    visited.insert(target);
    
    while(level!=K){
	
	// outter while loop runs till desired level
	
        int count = q.size();  // count basically represents number of nodes at a particular level.
        while(count-- > 0){
		
		// inner while loop basically level order traversal
		
            TreeNode * temp=q.front();
            q.pop();
            
			//stores left if it is not NULL and not visited
            if(temp->left!=NULL && !visited.count(temp->left)){
                q.push(temp->left);
                visited.insert(temp->left);
            } 
			
			//stores right if it is not NULL and not visited
            if(temp->right!=NULL && !visited.count(temp->right)){
                q.push(temp->right);
                visited.insert(temp->right);
            }
			
			//stores parent of node if it is not NULL ans not visited
            if(parentNode[temp]!=NULL && !visited.count(parentNode[temp])){
                q.push(parentNode[temp]);
                visited.insert(parentNode[temp]);
            }
        }
        level++;   
    }
    
    vector<int>ans;
    
	// stores all nodes which are at level==K
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;    
}
};