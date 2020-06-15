class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int> m;
        int maxlength=0;
        int substart=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.count(s[i]) && m[s[i]]>=substart)
            {
                maxlength= max(maxlength,i-substart);
                substart = m[s[i]]+1;
            }
            m[s[i]]=i;
            
        }
        int len =s.size();
        int res = max(maxlength,len-substart);
        return res;
    }
};