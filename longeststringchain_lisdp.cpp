static bool compare(const string &s1, const string &s2) {
return s1.length() < s2.length();
}

bool canConn(string& from, string& to) {
    if(to.length() - from.length() != 1) return false;

    int ti=0 , fi=0;
    while(ti < to.length()) {  //sirf size hi nhi occurence usi order me bhi imp hai  mtlb abc to abcd bn jaega lekin acb ko abcd ek letter add krke nhi bna skte
    	
        if(from[fi] == to[ti]) ++ti,++fi;
        else ++ti;
    }
    return fi == from.length();
}


int longestStrChain(vector<string>& words) {
    sort(words.begin(), words.end(), compare);
    vector<int> dp(words.size(), 1);
    int res = 0;
    for (int i=0; i<words.size(); ++i) {
        for (int k=0; k < i; ++k) {
            if (canConn(words[k], words[i])) {
                dp[i] = max(dp[i], dp[k] + 1);    
            }
        } 
        res = max(res, dp[i]);
    }

    return res;
}