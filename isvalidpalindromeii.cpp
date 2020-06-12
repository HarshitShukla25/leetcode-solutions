class Solution {
public:
    bool validPalindrome(string s) {
        if(ispal(s)) return true;
        vector<string> prestring;
        vector<string> sufstring;
        prestring[0]="";
        for(int i=1i<s.size();i++)
        {
            prestring[i]=s[i-1]+prestring[i-1];
        }
        
        
    }
};