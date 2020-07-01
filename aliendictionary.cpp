/*There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

For example,
Given the following words in dictionary,

[
"wrt",
"wrf",
"er",
"ett",
"rftt"
]
The correct order is: "wertf".
The idea is to create a graph of characters and then find topological sorting of the created graph.

Create a graph g with number of vertices equal to the size of alphabet in the given alien language. For example, if the alphabet size is 5, then there can be 5 characters in words. Initially there are no edges in graph.

Do following for every pair of adjacent words in given sorted array.
…..a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters.
…..b) Create an edge in g from mismatching character of word1 to that of word2.

Print topological sorting of the above created graph.*/
public class Solution {
/**
* @param words: a list of words
* @return: a string which is correct order
*/

public static class Graph {
    private List<Graph> adj;
    private char vertax;
    
    public Graph(char a){
        this.vertax = a;
        this.adj = new ArrayList<Graph>();            
    }
    
    public void addEdge(Graph b){
        System.out.printf("edge added from %s to %s\n", this.vertax, b.vertax);
        this.adj.add(b);
    }
}

public String topoSort(Map<Character, Graph> nodeMap){
    
    Map<Character, Integer> inDegree = new HashMap<Character,Integer>();
    
    for(Character key : nodeMap.keySet()){
        inDegree.put(key, 0);
    }
    
    for(Map.Entry<Character, Graph> entry : nodeMap.entrySet()){
        Character c = (Character) entry.getKey();
        Graph g = (Graph) entry.getValue();
        for(Graph adj : g.adj){
            Character key = adj.vertax;
            inDegree.put(key, inDegree.get(key) + 1); 
        }
    }
    
    PriorityQueue<Character> q = new PriorityQueue<Character>();
    
    for(Map.Entry<Character, Integer> entry : inDegree.entrySet()){
        Character c = (Character) entry.getKey();
        Integer degree = (Integer) entry.getValue();
        if(degree == 0){
            q.add(c);
        }
    }
    
    StringBuilder sb = new StringBuilder();

    while(!q.isEmpty()){
        Character c = q.poll();
        sb.append(c);
        Graph peek = nodeMap.get(c);
        for(Graph g : peek.adj){
            int degree = inDegree.get(g.vertax);
            inDegree.put(g.vertax, degree - 1);
            if(degree - 1 == 0){
                q.add(g.vertax);
            }
        }
    }
    
    if (sb.length() != inDegree.size()) {
        return "";
    }
    
    return sb.toString();
}

public String alienOrder(String[] words) {
    // Write your code 
    

    Map<Character, Graph> nodeMap = new HashMap<Character, Graph>();

    for(int j =0 ; j< words.length ; j++){
        
        char arr [] = words[j].toCharArray();
        for(char c : arr){
            if(nodeMap.get(c) == null){
                Graph g = new Graph(c);
                nodeMap.put(c,g);     
            }
            
        }
    }
    
    for(int j =0 ; j< words.length -1 ; j++){
        
        char [] a = words[j].toCharArray();
        char [] b = words[j+1].toCharArray();
        
        int i = 0;
        
        while(a[i] == b[i] && i < Math.min(a.length, b.length)){
            i++;
        }
        
        
        Graph aGraph = null, bGraph = null;
        aGraph = nodeMap.get(a[i]);
        bGraph = nodeMap.get(b[i]);
        aGraph.addEdge(bGraph);
    }
    
    
    return topoSort(nodeMap);
}

//cpp
class Solution {
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
     static bool compare(int a,int b){
         return (a>b)?true:false;
     }
     
     bool dfs(int index,map<int,vector<int>>&graph,vector<int>&color){
         if(color[index]==2){
            return false;
         }
        if(color[index]==1){
            return true;
        }
        color[index]=1;
        if(graph.find(index)==graph.end()){
            color[index]=2;
            return false;
        }
        vector<int>adj=graph[index];
        for(int i=0;i<adj.size();i++){
            if(dfs(adj[i],graph,color)==true)
                return true;
        }
        color[index]=2;
        return false;
     }
     void dfs2(map<int,vector<int>>&graph,int index,vector<bool>&visited,stack<int>&mystack){
         if(visited[index]==true)
            return;
        visited[index]=true;
        vector<int>k=graph[index];
        for(int i=0;i<graph[index].size();i++){
            if(visited[k[i]]==true)
                continue;
            dfs2(graph,k[i],visited,mystack);
        }
        mystack.push(index);
     }
     
    string alienOrder(vector<string> &words) {
        int size=words.size();
        
        if(size==1){
            return words[0];
        }
        map<int,vector<int>>graph;
        
        for(int i=1;i<size;i++){
            string b=words[i];
            string a=words[i-1];
            int j=0,k=0;
            while(j<a.length() && k<b.length()){
                if(a[j]!=b[k]){
                    graph[a[j]-'a'].push_back(b[k]-'a');
                   // cout<<a[j]<<" -> "<<b[k]<<endl;
                    break;
                }
                if(graph.find(a[j]-'a')==graph.end()){
                    graph[a[j]-'a']={};
                }
                j++;
                k++;
            }
            while(j<a.length()){
                if(graph.find(a[j]-'a')==graph.end()){
                    graph[a[j]-'a']={};
                }
                j++;
            }
            while(k<b.length()){
                if(graph.find(b[k]-'a')==graph.end())
                    graph[b[k]-'a']={};
                k++;
            }
            
        }
        vector<int>color(26,0);
        // true is directed cycle
        
        for(int i=0;i<26;i++){
            if(color[i]==0){
                if(dfs(i,graph,color)==true){
                    return "";
                }
            }
        }
        for(int i=0;i<26;i++){
            if(graph.find(i)==graph.end())
                continue;
            sort(graph[i].begin(),graph[i].end(),compare);
            for(int j=0;j<graph[i].size();j++){
                //cout<<(char)('a'+i)<<" "<<(char)('a'+graph[i][j])<<endl;
            }
        }
       // return "";
        
        stack<int>mystack;
        vector<bool>visited(26,false);
        for(int i=26;i>=0;i--){
            if(graph.find(i)==graph.end() || visited[i]==true)
                continue;
            dfs2(graph,i,visited,mystack);
            
        }
        string sol="";
        while(mystack.size()>0){
            sol+=string(1,'a'+mystack.top());
            mystack.pop();
        }
        return sol;
    }
};
