class Solution {
public:
   //basically cycle nikaalni h directed graph me
	//used graph coloring 0 for unprocessed 1 for processed and 2 for processing , jese hi koi processing node mil gyi iska mtlb cycle h 
	bool isCycle(vector<vector<int>>& adj,vector<int>& visited,int curr)
	{
		if(visited[curr] == 2) 
			return true;
		visited[curr] = 2;
		for(int i=0;i<adj[curr].size();i++)
		{
			if(visited[adj[curr][i]] != 1)
			{
				if(isCycle(adj,visited,adj[curr][i]));
			}
		}
		visited[curr] = 1;
		return false;
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for (int i = 0; i < numCourses;i++)
        {
        	adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses,0);
        for (int i = 0; i < numCourses;i++)
        {
        	if(visited[i] == 0)
        	{
        		if(isCycle(adj,visited,i))
        			return false;
        	}
        }
        return true;
    }
};