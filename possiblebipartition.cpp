class Solution {
public:
	bool isbipartite(vector<vector<int>>& adj,int N,int i,vector<int>& color)
	{
		queue<int> q;
		q.push(i);
		color[i]=1;  //the benefit of doing by bfs here is that u get access to the parent element i.e curr
		while(!q.empty())
		{
			int curr = q.front();
			q.pop();
			for(int ele: adj[curr])
			{
				if(color[ele]==color[curr])
					return false;
				if(color[ele]==-1)
				{
					color[ele] = 1-color[curr];
					q.push(ele);
				}
				
			}
		}
		return true;
	}

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    	vector<vector<int>> adj(N+1);
    	for (int i = 0; i < dislikes.size();i++)
    	{
    		adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
    	}
    	
    	vector<int> color(N+1,-1);
        for(int i = 1; i <= N;i++)
        {
        	if(color[i]==-1)
        	{
        		
        		if(!isbipartite(adj,N,i,color))
        			return false;
        	}
        }
        return true;
    }
};