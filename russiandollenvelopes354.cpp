#define f first
#define s second
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0) return 0;
        int n = envelopes.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++)
        {
            v[i].first  = envelopes[i][0];
            v[i].second = envelopes[i][1];
        }
        sort(v.begin(),v.end());
        int lis[n];
        lis[0]=1;
        for(int i=1;i<n;i++)
        {   lis[i]=1;
            for(int j=0;j<i;j++)
            {
                if((v[i].f > v[j].f)&&(v[i].s>v[j].s) && (lis[i]<(lis[j]+1)))
                {
                    lis[i] = lis[j]+1;
                }
            }
        }
        return *max_element(lis,lis+n);
    }
};