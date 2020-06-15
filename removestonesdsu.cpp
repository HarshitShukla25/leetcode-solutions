//======================   DFS Solution   ========================

public int removeStones(int[][] stones) {
    boolean[] vis = new boolean[stones.length]; // Visited Array
    int ans = 0;
    for(int i =0;i<stones.length;i++){
        if(!vis[i]){
            ans++;
            dfs(stones, i, vis);  // Calling for dfs if not visited
        }
    }
    return stones.length- ans;
}
	public void dfs(int[][] arr,  int i, boolean vis[]){
		vis[i] = true; // Mark
		int[] x = arr[i]; 
		for(int j = 0;j<arr.length;j++){
			int[] y = arr[j];
			if(x[0]==y[0] || x[1] == y[1]){    // if any coordinate matches( either x axis or y axis)
				if(!vis[j])      // And if it is not visited
					dfs(arr, j, vis);      //Call for DFS
			}
		}
	}
	
	
	// ====================  Union Find Solution   ===================
	
	int[] par;
	public int findPar(int x){       // Func to Find Parent 
    return par[x]= par[x]==x?x:findPar(par[x]);
	}
	public int removeStones(int[][] stones) {
		par = new int[stones.length];
		int ans = 0;
		for(int i =0;i<par.length;i++){
			par[i] = i;
		}
		for(int i =0;i<stones.length;i++){
			for(int j = i+1;j<stones.length;j++){
				int[] a = stones[i];
				int[] b = stones[j];
				int p1 = findPar(i);
				int p2 = findPar(j);
				// if any coordinate matches( either x axis or y axis)  but parents are not the same
				if((a[0] == b[0] || a[1] == b[1])&& p1!=p2){  
					ans++;
					par[p1] = Math.min(p1,p2); // Making parents same by keeping parents as minimum
					par[p2] = Math.min(p1,p2); // Making parents same by keeping parents as minimum
				}

			}
		}
		return ans;
	}