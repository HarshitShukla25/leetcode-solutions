class Solution {
public:
    int numSub(string s) {
         int MOD = 1e9 + 7;
    int i = 0, l = s.size();
    int ans = 0;
    while (i < l) {
        int count = 0; // count gives length of block of 1's
        if (s[i] == '1') {
            while(i < l && s[i] == '1') {
                ++count;
                ++i;
            }
            long substringCount = 1L * count * (count + 1) / 2 % MOD;
            ans = (ans + substringCount) % MOD;
        } else {
            ++i;
        }// ye dikkat krta hai for loop lgaane pr so always use while.
    }
    return ans;
//         int max=0;
//         vector<int> sz;
//         for(int i=0;i<s.size();i++)
//         {
//             if(s[i]-'0'==1)
//             {   int j=0;
//                 while(j<s.size()&&s[j]-'0'==1 ) {j++;if(max<j)max=j;}
//                 sz.push_back(j);
//                 i+=j;
//             }
//         }
//         vector<int> dp(max+1,0);
//         dp[0]=0;
//         dp[1]=1;
//         dp[2]=3;
//         int d=3;
//         for(int i=3;i<=max;i++)
//         {
//             dp[i] = dp[i-1]+d;
//             d+=1;
//         } 
//         int res=0;
//         int MOD =1e9+7;
//         for(auto &it: sz)
//         {
//             res+= dp[it]%MOD;
//         }
            
//         return res;
    }
};