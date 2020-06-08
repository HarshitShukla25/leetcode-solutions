class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum=0;
        int n = grid.size();
        vector<int> maxtb(n,0);
        vector<int> maxlr(n,0);
        for(int i=0;i<grid.size();i++)
        {
        	for(int j=0;j<grid[i].size();j++)
        	{
        		maxlr[i]=max(maxlr[i],grid[i][j]);
        		maxtb[j]=max(maxtb[j],grid[i][j]);
        	}
        }
        for(int i=0;i<grid.size();i++)
        {
        	for(int j=0;j<grid[i].size();j++)
        	{
        		if(min(maxlr[i],maxtb[j])>grid[i][j])
        			sum+=min(maxlr[i],maxtb[j])-grid[i][j];
        	}
        }
        return sum;
    }
};