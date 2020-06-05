class Solution {
public:
    vector<int> ww;
    Solution(vector<int>& w) {
         ww=w;
    }
    
    int pickIndex() {
        int sum=0;
        for(int i=0;i<ww.size();i++)
            sum+=ww[i];
        int random = rand()%sum;
        for(int i=0;i<ww.size();i++)
        {
            if(random<ww[i])
                return i;
            random-= ww[i];
            
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */