class Solution {

    vector<int> par;
    int find(int x)
    {
        return par[x]= (par[x]==x)?x:find(par[x]);
    }
    public: int makeConnected(int n, vector<vector<int>>& connections) { 
        int cables = connections.size();
         if(cables < n - 1) return -1;
        par.resize(n,0);
        for(int i=0;i<n;i++)
            par[i]=i;
        int unconnected=0;
       
        for(int i=0;i<connections.size();i++)
        {
            int a = find(connections[i][0]);
            int b = find(connections[i][1]);
            if(a!=b)
            {   
                par[b]=a;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
                unconnected++;
        }
        return unconnected-1;
    }

};