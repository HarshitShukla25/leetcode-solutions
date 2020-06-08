class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> c1(26,0);
        vector<int> c2(26,0);
        for(int i=0;i<s.size();i++)
        {
            c1[s[i]-97]++;
        }
        for(int i=0;i<s.size();i++)
        {
            c2[t[i]-97]++;
        }
        int count=0;
        for(int i=0;i<26;i++)
        {
            count += min(c1[i],c2[i]);
        }
        
        
        return s.size()-count;
    }
};