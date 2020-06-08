class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> v;
        map<char,int> m;
        for(int i=0;i<S.length();i++)
            m[S[i]]=i;
        int i=0;
        while(i<S.length())
        {
            int l=i;
            char c=S[i];
            int p=m[c];
            while(i<=p)
            {
                p=max(p,m[S[i]]);
                i++;
                
            }
            v.push_back(p-l+1);
            
        }
        return v;
    }
};