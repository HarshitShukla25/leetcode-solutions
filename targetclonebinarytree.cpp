class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==target || original==NULL) return cloned;
        TreeNode *t=getTargetCopy(original->left,cloned->left,target);
        if(t==NULL) t=getTargetCopy(original->right,cloned->right,target);
        return t;
    }
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==target || original==NULL) return cloned;
        TreeNode *t=getTargetCopy(original->left,cloned->left,target);
        if(t==NULL) t=getTargetCopy(original->right,cloned->right,target);
        return t;
    }
};

///Also look at this JAVA soln for the traversal path
class Solution {
    private List<String> targetPath;
    private TreeNode targetNode = null;
    public final TreeNode getTargetCopy(final TreeNode original, 
                                        final TreeNode cloned, 
                                        final TreeNode target) {
        buildTargetPath(original, target, new ArrayList<>());
        findTargetNode(cloned, 0);
        return targetNode;
    }
    
    private void buildTargetPath(TreeNode root, TreeNode target, List<String> curPath) {
        if (root == null) return;
        if (root.equals(target)) {
            targetPath = new ArrayList<>(curPath);
            return;
        }
        curPath.add("left");
        buildTargetPath(root.left, target, curPath);
        curPath.remove(curPath.size()-1);
        
        curPath.add("right");
        buildTargetPath(root.right, target, curPath);
        curPath.remove(curPath.size()-1);
    }
    
    private void findTargetNode(TreeNode root, int pos) {
        if (pos == targetPath.size()) {
            targetNode = root;
            return;
        }
        if ("left".equals(targetPath.get(pos))) {
            findTargetNode(root.left, pos+1);
        } else {
            findTargetNode(root.right, pos+1);
        }
    }
}