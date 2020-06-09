class Solution {
public:
    
    bool allzero(vector<int> v)
    {
        for(auto i : v) if(i!=0) return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        
        int n = p.size();
        int m = s.size();
        vector<int> count(26,0);
        vector<int> res;
        if(n>m) return res;
        for(int i=0;i<n;i++ )
        {
            count[s[i]-'a']--;
            count[p[i]-'a']++;
        
        }
        for(int i=n;i<m;i++)
        {
            if(allzero(count))
            {
                res.push_back(i-n);
            }
            count[s[i]-'a']--;
            count[s[i-n]-'a']++; //basically these two are used to imitate the shifting of the sliding window
        }
        if(allzero(count))
            {
                res.push_back(m-n);
            }
        return res;
    }
};