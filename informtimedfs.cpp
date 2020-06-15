class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& m,int i,int curr,int &res, vector<int>& informTime)
    {
        curr+=informTime[i];
        res = max(res,curr);
        for (auto it = m[i].begin(); it != m[i].end(); it++)
        {
            dfs(m,*it,curr,res,informTime);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<manager.size();i++)
            if(manager[i]!=-1)
                m[manager[i]].push_back(i);
        int curr=0,res=0;
        dfs(m,headID,curr,res,informTime);
        return res;
    }
};