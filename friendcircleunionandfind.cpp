class Solution {
public:
    int friendCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for (auto i = 0; i < n; i++){
            for (auto j = 0; j < n; j++){
                if (M[i][j] == 1 && i != j){
                    Union(parent, i, j);
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < n; i++){
            if (parent[i] == i){
                count += 1;
            }
        }
        return count;
    }
    
    int Find(vector<int>& parent, int i){
        if (parent[i] == i){
            return i;
        } 
        return Find(parent, parent[i]);
    }
    
    void Union(vector<int>& parent, int i, int j){
        int i_set = Find(parent, i);
        int j_set = Find(parent, j);
        if (i_set != j_set){
            parent[j_set] = i_set;
        }
    }
};