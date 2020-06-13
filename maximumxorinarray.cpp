class Trie{
    Trie *children[2]={};
    bool leaf;
    Trie()
    {
        leaf=false;
       
    }
}

class Solution {
private:
    Trie* root= new Trie();
public:
    void buildtree(vector<int>& nums)
    {
        for(int num : nums)
        {
            Trie* node = root;
            for(int i=31;i>=0;i--)
            {
                int bitOp = (num>>i)&1;
                if(!node->children[bitOp])
                    node->children[bitOp]= new Trie();
                node = node->children[bitOp];
            }
            node->leaf = true;
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        buildtree(nums);
        int maxRes=0,res=0;
        for(int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            Trie* node = root;
            int index;
            int res=0;
            for(int k=31;k>=0;k--)
            {
                int bitOp=(num>>k)&1;
                if(bitOp) index=0;
                else index=1;
                if(node->children[index])
                {
                    res <<=1;
                    res |=1;
                    node=node->children[index];
                }
                else
                {
                    res <<=1;
                    res|=0;
                    node=node-> children[index?0:1];
                }

            }
            maxRes = max(maxRes, res);
        }
        return maxRes;
    }
};