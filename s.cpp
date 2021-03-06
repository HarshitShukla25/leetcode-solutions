#include <bits/stdc++.h>
using namespace std;
class Graph 
{ 
    int V;    // No. of vertices 
  
    // Pointer to an array containing adjacency 
    // lists 
    list<int> *adj;    
public: 
    Graph(int V);  // Constructor 
  
    // function to add an edge to graph 
    void addEdge(int v, int w);  
  
    // prints DFS traversal from a given source s 
    void DFS(int v); 
    void DFSUtil(int v,bool visited[]);
}; 
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); // Add w to v’s list. 
} 
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void Graph::DFS(int v) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited); 
} 
  
int connectedComponents(Graph g)
{
	bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false;
    int count =0;
    for(int q=0;q<V;q++)
    {
    	if(visited[q]==false)
    		{	DFSUtil(q,visited);
    		 	 count++;
    		} 
    }
    		return count; 
}
int main() 
{ 
    // Create a graph given in the above diagram 
    int n;
    cin >> n;
    Graph g(n*2); 
    int a,b;
    while(n--)
    {
    	
    	cin >> a >> b;
    	g.addEdge(a,-b);
    }
     int res = connectedComponents(g)-1;
     cout << res;
  
    return 0; 
} 
