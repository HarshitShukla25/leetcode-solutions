class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        return dfs(graph,0);
    }
    vector<vector<int>> dfs(vector<vector<int>>& graph,int node)
    {
        vector<vector<int>> res;
        int n = graph.size();
        if(node==n-1)
        {
            vector<int> path;
            path.push_back(n-1);
            res.push_back(path);
            return res;
        }
        vector<int> edges = graph[node];
        for(int i=0;i<edges.size();i++)
        {
            vector<vector<int>> paths = dfs(graph,edges[i]);
            for(j=0;j<paths.size();j++)
            {
                paths[j].insert(paths[j].begin(),node);
                res.push_back(paths[j]);
            }
        }
        return res;
    }
    
};


////////////////////////////////////////////////////////////////bettersoln

class Solution {
public:
    
    vector<bool> visited;
    int n;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        visited = vector<bool>(n, false);
        vector<int> curPath;
        vector<vector<int>> sol;
        paths(graph, 0, curPath, sol);
        return sol;
    }
    
    void paths(vector<vector<int>>& graph, int src, 
               vector<int>& curPath, vector<vector<int>>& sol){
        visited[src] = true; curPath.push_back(src);
        if (src==n-1){
            sol.push_back(curPath); 
            visited[src] = false; curPath.pop_back();
            return;
        }
        for (int next:graph[src]){
            if (!visited[next]){
                paths(graph, next, curPath, sol);
            }
        }
        visited[src] = false; curPath.pop_back();
    }
};