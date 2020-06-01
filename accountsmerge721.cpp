class Solution {
public:
    //O(n)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string,string> Email_Names;
        unordered_map<string,string> List;
        for(auto it : accounts){
            for(int i = 1; i < it.size(); i++){
                Email_Names[it[i]] = it[0];
                List[it[i]] = it[i];
            }
        }
        //vector<vector<string>> edges;
        for(auto it : accounts){
            for(int i = 1; i < it.size(); i++){
                for(int j = i; j < it.size(); j++){
                    Union(List,it[i],it[j]);
                }
            }
        }
        ////
        unordered_map<string, vector<string>> filter;
        for(auto it : List){
            filter[Find_Root(List, it.second)].push_back(it.first);
        }
        ////
        for(auto it : filter){
            vector<string> tmp;
            tmp.push_back(Email_Names[it.first]);
            sort(it.second.begin(), it.second.end(), [](const string& a, const string& b)->bool{
                return a < b;
            });
            for(auto v : it.second){
                tmp.push_back(v);
            }
            res.push_back(tmp);
        }
        return res;
    }
    //O(n)
    string Find_Root(unordered_map<string,string>& List, string a){
        string r = a;
        while(r != List.at(r)){
            r = List.at(r);
        }
        //compression
        string b = a;
        while(List.at(b) != r){
            string tmp = b;
            b = List[b];
            List[tmp] = r;
        }
        return r;
    }
    //O(1)
    void Union(unordered_map<string, string>& List, string a, string b){
        string Root_A = Find_Root(List, a);
        string Root_B = Find_Root(List, b);
        List[Root_A] = Root_B;    
    }
    //O(1)
    bool Connected(unordered_map<string,string>& List, string a, string b){
        string Root_A = Find_Root(List, a);
        string Root_B = Find_Root(List, b);     
        return Root_A == Root_B;
    }
    
};