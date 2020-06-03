class Solution {
public:
    // isme basically you have printed out the topological sorted order.
	bool isCycle(vector<vector<int>>& adj,vector<int>& visited,int curr,vector<int>& res)
	{
		
		if(visited[curr] == 2) 
			return true;
		visited[curr] = 2;
		for(int i=0;i<adj[curr].size();i++)
		{
			if(visited[adj[curr][i]] != 1)
			{
				if(isCycle(adj,visited,adj[curr][i],res))
                    return true;
			}
		};
		res.push_back(curr);
		visited[curr] = 1;
		return false;
	}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    	vector<int> res;
        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < prerequisites.size();i++)
        {
        	adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses,0);
        for (int i = 0; i < numCourses;i++)
        {
        	if(visited[i] == 0)
        	{
        		if(isCycle(adj,visited,i,res))
        			return {};
        	}
        }
        return res;
    }
};