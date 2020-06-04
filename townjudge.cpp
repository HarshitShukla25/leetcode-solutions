class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size()==0) {
            if(N==1) return 1;
            else return -1;
        }
        map<int,int> m;
        int n=trust.size();
        set<int> s;
        
        for(auto ch : trust)
        {
            m[ch[1]]++;
            
            s.insert(ch[0]);
        }
        for(auto ch:m)
        {
            if(m[ch.first]==(N-1) && s.find(ch.first)==s.end())
                return ch.first;
        }
        return -1;
    }
};
/*
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if(trust.size()==0) {
            if(N==1) return 1;
            else return -1;
        }
        map<int,int> m;
        int n=trust.size();
        set<int> s;
        
        for(auto ch : trust)
        {
            m[ch[1]]++;
            
            s.insert(ch[0]);
        }
        for(auto ch:m)
        {
            if(m[ch.first]==(N-1) && s.find(ch.first)==s.end())
                return ch.first;
        }
        return -1;
    }
};*/