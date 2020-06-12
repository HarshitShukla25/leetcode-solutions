    class Solution {
   public:
string minRemoveToMakeValid(string s) {
    vector<int> index2remove; // create a vector to store index of '('. In the end, index2remove size will drop to 0 only when s is balanced.
    for(int i = 0; i < s.length(); ++i){
        if (s[i] == '(') index2remove.push_back(i);
        else if (s[i] == ')'){
            if (index2remove.size()>0) index2remove.pop_back();
            else s[i] = 'A'; //detected ')' that can't be balanced. Mark it to 'A'.
        }
    }
   string result;
    int j = 0;
    for(int i = 0; i < s.length(); ++i){ // traverse s
        if(j < index2remove.size()){ // 
            if(i == index2remove[j] ){
                ++j;
                continue;
            }
        }
        if (s[i]== 'A') continue; 
        result += s[i]; //cope s[i] to result only if it is not marked to 'A' or i is not in the index2remove.
    }
    return result;
}
//
    string minRemoveToMakeValid(string s) {
        // Check edge case
        if (s.size() == 0) return s;
        
        // Build index removal parentheses using stack
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                if (st.empty()) st.push(i);
                else if (s[st.top()] == ')') st.push(i);
                else st.pop();  
            }
        }
        
        // Build result
        string res;
        res.resize(s.size() - st.size());
        
        for (int idx = res.size()-1, i = s.size()-1; i >= 0; i--) {
            if (st.empty() || st.top() != i) res[idx--] = s[i];
            else st.pop();
        }
        
        return res;
    }