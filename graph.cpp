#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

void addEdgeWeighted(vector<pair<int,int>> adj[], int u,int v, int wt)
{
	adj[u].pb(mp(v,wt));
	adj[v],pb(mp(u,wt));  // Undirected and weighted
}
void DFSutil(int u,vector<int> adj[],vector<bool> &visited)
{
	visited[u]=true;
	cout << u << " ";
	for(int i=0;i<adj[u].size();i++)
	{
		if(visited[adj[u][i]]!=true)
			DFSutil(adj[u][i],adj,visited);
	}
}
void DFS(vector<int> adj[],int V)
{
	vector<bool> visited(V,false);
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
			DFSutil(u,adj,visited);
	}
}

//////////////////////////////////////////////

struct Graph{
	int V;
	unordered_set<int>* adjList; //why a pointer to this here but not in integer
}

Graph* createGraph(int V)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->adjList = new unordered_set<int>[V];
	return graph;
}

void addEdge(Graph* graph,int src,int des)
{
	graph->adjList[src].insert(des);
	graph->adjList[des].insert(src);
}
void printGraph(Graph* graph) 
{ 
    for (int i = 0; i < graph->V; ++i) { 
        unordered_set<int> lst = graph->adjList[i]; 
        cout << endl << "Adjacency list of vertex "
             << i << endl; 
  
        for (auto itr = lst.begin(); itr != lst.end(); ++itr) 
            cout << *itr << " "; 
        cout << endl; 
    } 
} 
void searchEdge(Graph* graph, int src, int dest) 
{ 
    auto itr = graph->adjList[src].find(dest); 
    if (itr == graph->adjList[src].end()) 
        cout << endl << "Edge from " << src 
             << " to " << dest << " not found."
             << endl; 
    else
        cout << endl << "Edge from " << src 
             << " to " << dest << " found."
             << endl; 
} 

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
	list<int> queue;
	visited[s] = true;
	queue.pb(s);
	list<int>::iterator i;
	while(!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		for(i=adj[s].begin();i!=adj[s].end();i++)
		{
			if(!visited[*i])
			{
				visited[*i]=true;
					queue.push_back(*i);
			}
		}
	}
}



/////////////////////////////

using namespace std; 
  
// This class represents a directed graph using 
// adjacency list representation 
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
  
    // prints BFS traversal from a given source s 
    void BFS(int s);   
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
  
void Graph::BFS(int s) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Create a queue for BFS 
    list<int> queue; 
  
    // Mark the current node as visited and enqueue it 
    visited[s] = true; 
    queue.push_back(s); 
  
    // 'i' will be used to get all adjacent 
    // vertices of a vertex 
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        // Get all adjacent vertices of the dequeued 
        // vertex s. If a adjacent has not been visited,  
        // then mark it visited and enqueue it 
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
} 
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << v << " "; 
  
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
// Driver program to test methods of graph class 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 

////////////////////////////////////////////////

