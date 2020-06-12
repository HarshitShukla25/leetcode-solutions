class Solution {
public:
    vector<pair<int, int>> vec;
    Solution(int N, vector<int>& blacklist) {
        sort(blacklist.begin(), blacklist.end());
        if (blacklist.size() == 0) {
            vec.push_back(make_pair(0, N - 1));
        } else {
            int start = 0, end = blacklist[0] - 1;
            if (end >= start) vec.push_back(make_pair(start, end));
            for (int i = 1; i < blacklist.size(); i++) {
                start = blacklist[i - 1] + 1;
                end = blacklist[i] - 1;
                if (end >= start) vec.push_back(make_pair(start, end));
            }
            if (blacklist[blacklist.size() - 1] < N - 1) {
                start = blacklist[blacklist.size() - 1] + 1;
                end = N - 1;
                if (end >= start) vec.push_back(make_pair(start, end));
            }
        }
    }
    
    int pick() {
        if (vec.size() == 0)    return 0;
        int idx = rand() % vec.size();
        int start = vec[idx].first, end = vec[idx].second;
        if (start == end)   return start;
        int val = start + (rand() % (end - start + 1));
        //cout << val << endl;
        return val;
    }
};