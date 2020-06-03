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

//////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> vec;
        if (accounts.size() == 0)   return vec;
        unordered_map<string, string> email;
        unordered_map<string, set<string>> email_group;
        unordered_map<string, bool> visited;
        for (int i = 0; i < accounts.size(); i++) {
            string usr = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); j++) {
                email[accounts[i][j]] = usr;
                email_group[accounts[i][j]].insert(accounts[i].begin() + 1, accounts[i].end());
            }
        }
        
        for (auto it = email_group.begin(); it != email_group.end(); it++) {
            
            string usr = email[it->first];
            if (visited.find(it->first) != visited.end())   continue;
            list<string> ver;
            set<string> sec;
            ver.push_back(it->first);
            while (!ver.empty()) {
                string u = ver.front();
                ver.pop_front();
                visited[u] = true;
                sec.insert(u);
                for (set<string> :: iterator it2 = email_group[u].begin(); 
                     it2 != email_group[u].end(); it2++) {
                    
                    if (visited.find(*it2) == visited.end()) {
                        visited[*it2] = true;
                        ver.push_back(*it2);
                    }
                }
            }
            vector<string> v;
            v.push_back(usr);
            v.insert(v.end(), sec.begin(), sec.end());
            vec.push_back(v);
        }
        
        return vec;
    }
};



///////////////////////////////////////////////////////////////////

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> out;
        unordered_map<string, vector<string>> groups;
        unordered_map<string, string> email_to_name;
        for (auto& act : accounts) {
            for (int i = 1; i < act.size(); i++) {
                // Create mappings for emails to name
                email_to_name[act[i]] = act[0];
                // Create mappings of 1st email to all other emails
                groups[act[1]].push_back(act[i]);
                groups[act[i]].push_back(act[1]);
            }
        }
        unordered_map<string, bool> visited;
        for (auto group : groups) {
            // Find unvisited group entry
            if (!visited[group.first]) {
                vector<string> tmp;
                // Push name as the first string
                tmp.push_back(email_to_name[group.first]);
                queue<string> q;
                q.push(group.first);
                visited[group.first] = true;
                // Do BFS loop
                while(!q.empty()) {
                    string s = q.front(); q.pop();
                    // Push email
                    tmp.push_back(s);
                    
                    for (auto& email : groups[s]) {
                        if (!visited[email]) {
                            q.push(email);
                            visited[email] = true;
                        }
                    }
                }
                // Sort the list of emails for this name
                // nlogn
                sort(tmp.begin() + 1, tmp.end());
                out.push_back(tmp);   
            }
        }
        return out;
    }
};

///////////////////////////////

class Solution {
public:
    //O(n)
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
     vector<vector<string>> res;
    unordered_map<string,string> email_toName;
    unordered_map<string,vector<string>> groups;
        int n = accounts.size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();i++)
            {
                email_toName[accounts[i][j]] = accounts[i][0];
                groups[accounts[i][1]].push_back(accounts[i][j]);
                groups[accounts[i][j]].push_back(accounts[i][1]);
            }
        }
        unordered_map<string ,bool> visited;
        for(auto group : groups)
        {
            if(!visited[group.first])
            {
                vector<string> tmp;
                tmp.push_back(email_toName[group.first]);
                queue<string> q;
                q.push(group.first);
                visited[group.first] = true;
                while(q.empty())
                {
                    string s = q.front();q.pop();
                    tmp.push_back(s);
                    for(auto& email:groups[s])
                    {
                        if(!visited[email])
                        {
                            q.push(email);
                            visited[email] = true;
                        }
                    }
                    sort(tmp.begin()+1,tmp.end());
                    res.push_back(tmp);
                }
            }
        }
            return res;
        }
        
};