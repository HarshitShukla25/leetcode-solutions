class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    	int n= groupSizes.size();
      	
        map<int,vector<int>> m;
        

        vector<vector<int>> res;
        for (int i=0; i<groupSizes.size();i++)
        {
        	if(m[groupSizes[i]].size()<groupSizes[i])
        	m[groupSizes[i]].push_back(i);
        	else
        	{
        		
        		res.push_back(m[groupSizes[i]]);
        		m[groupSizes[i]].clear();
        		m[groupSizes[i]].push_back(i);
        	}
        }
        for(auto it:m)
        {
        	res.push_back(it.second);
        }
        return res;
    }
};