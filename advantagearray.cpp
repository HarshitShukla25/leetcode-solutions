
       class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> ms(A.begin(), A.end());
        vector<int> ans(A.size());
        for(int i = 0; i < B.size(); i++) {
            auto it = ms.upper_bound(B[i]);
            if(it != ms.end()) {
                ans[i] = *it;
                ms.erase(it);
            } else {
                ans[i] = *ms.begin();
                ms.erase(ms.begin());
            }
        }
        return ans;
    }
};