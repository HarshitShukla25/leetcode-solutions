class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==0) return 0;
        int n = pairs.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i].first = pairs[i][0];
            v[i].second = pairs[i][1];
        }
        sort(v.begin(),v.end());
        int lis[n];
        lis[0]=1;
        for(int i=1;i<v.size();i++)
        {   lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if(v[i].first>v[j].second && lis[i]<lis[j]+1)
                    lis[i] = lis[j]+1;
            }
        }
        return *max_element(lis,lis+n);
    }
};