class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
    	parent = new int[edges.length+1];
 		List<Integer> parents [] = new List[edges.length+1];
 		for(int i = 0;i<parents.length;i++) parents[i] = new ArrayList<>();

 		for(int [] edge:edges) {
 			parents[edge[1]].add(edge[0]);
            if(parents[edge[1]].size() == 2) {
                for(int j = 1;j>=0;j--) {
                    int [] redundant = {parents[edge[1]].get(j), edge[1]};
                    if(isValidWithoutEdge(redundant, edges)) {
                        return redundant;
                    }
                } 
            }
 		}     

        return findAnyInvalidEdge(edges);
    }

    int parent [] ;

    int [] findAnyInvalidEdge(int [][] edges) {


 		for(int i = 0;i<parent.length;i++) parent[i] = i;

 		for(int [] edge:edges) {
 			int p1 = getParent(parent, edge[0]);
 			int p2 = getParent(parent, edge[1]);

 			if(p1 == p2 ||p2 != edge[1]) return edge;

 			parent[p2] = p1;
 		} 

 		return edges[edges.length-1];
    }

    boolean isValidWithoutEdge(int [] redundant, int [][] edges) {
    	//int parent [] = new int[edges.length+1];
    	for(int i = 0;i<parent.length;i++) parent[i] = i;

    	for(int edge[]:edges) {
    		if(edge[0] == redundant[0] && edge[1] == redundant[1]) continue;
    		int p1 = getParent(parent, edge[0]);
    		int p2 = getParent(parent, edge[1]);

    		parent[p2] = p1;
    	}

    	for(int i = 2;i<parent.length;i++) {
    		if(getParent(parent, i) != getParent(parent, i-1)) return false;
    	}
    	return true;
    }

    int getParent(int [] parent, int v) {
    	int p = parent[v];
    	while(p != parent[p]) {
    		p = parent[p];
    	}
    	return p;
    }
}


///////////

class Solution {
    public int[] findRedundantDirectedConnection(int[][] edges) {
        int N = edges.length;
        Map<Integer, Integer> parent = new HashMap();
        List<int[]> candidates = new ArrayList();
        for (int[] edge: edges) {
            if (parent.containsKey(edge[1])) {
                candidates.add(new int[]{parent.get(edge[1]), edge[1]});
                candidates.add(edge);
            } else {
                parent.put(edge[1], edge[0]);
            }
        }

        int root = orbit(1, parent).node;
        if (candidates.isEmpty()) {
            Set<Integer> cycle = orbit(root, parent).seen;
            int[] ans = new int[]{0, 0};
            for (int[] edge: edges) {
                if (cycle.contains(edge[0]) && cycle.contains(edge[1])) {
                    ans = edge;
                }
            }
            return ans;
        }

        Map<Integer, List<Integer>> children = new HashMap();
        for (int v: parent.keySet()) {
            int pv = parent.get(v);
            if (!children.containsKey(pv))
                children.put(pv, new ArrayList<Integer>());
            children.get(pv).add(v);
        }

        boolean[] seen = new boolean[N+1];
        seen[0] = true;
        Stack<Integer> stack = new Stack();
        stack.add(root);
        while (!stack.isEmpty()) {
            int node = stack.pop();
            if (!seen[node]) {
                seen[node] = true;
                if (children.containsKey(node)) {
                    for (int c: children.get(node))
                        stack.push(c);
                }
            }
        }
        for (boolean b: seen) if (!b)
            return candidates.get(0);
        return candidates.get(1);
    }

    public OrbitResult orbit(int node, Map<Integer, Integer> parent) {
        Set<Integer> seen = new HashSet();
        while (parent.containsKey(node) && !seen.contains(node)) {
            seen.add(node);
            node = parent.get(node);
        }
        return new OrbitResult(node, seen);
    }

}
class OrbitResult {
    int node;
    Set<Integer> seen;
    OrbitResult(int n, Set<Integer> s) {
        node = n;
        seen = s;
    }
}

/////////////////
We build up the graph ( a rooted tree with N nodes) by adding each edge into it. A just added edge might screw up the graph (or say it diffrently: makes it become not a rooted tree with N nodes) in 2 cases:

A new edge makes a node have 2 parents. (I). We store 2 possible edges that should be removed. twoParents[0], and twoParents[1]
A new edge makes a cycle in the graph. (II). We store the possible edge that should be removed. cycle
There are 4 possibilities happen:

(I) happens before (II) : we need to remove the edge twoParents[0], because when we remove twoParents[0]:

the graph has no node that has 2 parents
the graph has no cycle.
(II) happens before (I)) : the same as above. We should remove twoParents[0]

Only (I) happens: we should remove one of twoParents. Because we must remove the one that occurs last in the given 2D-array. So twoParents[1] should be removed.

Only (II) happens: ofcourse we must remove the edge that makes the graph become cycle: so we remove cycle.

    public int[] findRedundantDirectedConnection(int[][] edges) {
        Map<Integer, Integer> map = new HashMap<>();
        int[] cycle = null, twoParents[] = null;
        for (int[] edge : edges) {
            if (!map.containsKey(edge[0])) map.put(edge[0], edge[0]);
            if (!map.containsKey(edge[1]) || map.get(edge[1]) == edge[1]) map.put(edge[1], edge[0]);
            else { // 2 parents
                twoParents = new int[][] {new int[] {map.get(edge[1]),edge[1]}, edge};
                if (cycle != null) return twoParents[0];
            }
            if (cycle == null && findRoot(map, edge[0]) == null) { // cycle
                cycle = edge;
                if (twoParents != null) return twoParents[0];
            }
        }
        if (cycle != null) return cycle;
        if (twoParents != null) return twoParents[1];
        return new int[2];
    }

    private Integer findRoot(Map<Integer, Integer> map, int node0) { // return null - cycle, int - root
        if (map.get(node0) == node0) return node0;
        int node = node0;
        while (map.get(node) != node) {
            node = map.get(node);
            if (node == node0) return null;
        }
        return node;
    }

    ///  1. If an incoming edge causes two parent scenario , and there was already an edge that caused a cycle then we definitely
  have to remove the first parent as the question states that only one edge is bad , thus the previous parent will be the defective
  edge that caused the cycle , and if even after removal of the first parent it does not convert into a tree then
  the input is wrong , as it would require two edges to be removed;
 
  2. If an incoming edge causes a cycle  , and there already exists a node with dual parents then we can safely assume that
  the one of the parents is the culprit because we know removing the incoming edge will not solve the problem as
  there still be a node with two parents , then we remove the first parent as we have not added the second parent
  in the map , does only first parent can cause the cycle.