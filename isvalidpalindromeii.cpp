class Solution {
public:
	bool ispal(string s)
	{
        int  n= s.size();
		int i=0;
		while(i<n-i-1)
		{
			if(s[i]!=s[n-i-1]) return false;
			i++;
		}
		return true;
	}
    bool validPalindrome(string s) {
    	int n= s.size();
        if(ispal(s)) return true;
        vector<string> prestring(n,"");
        vector<string> sufstring(n,"");
        
        for(int i=1;i<s.size();i++)
        {
            prestring[i]=s[i-1]+prestring[i-1];
        }
        for(int i=s.size()-2;i>=0;i--)
        {
        	sufstring[i]=s[i+1]+sufstring[i+1];
        }
        for(int i=0;i<s.size();i++)
        {
        	string k  = prestring[i]+sufstring[i];
        	if(ispal(k)) return true;
        }
        return false;
    }
};   // time limit exceeds

//better solution
class Solution {
public:
    //Check if a string is a normal palindrome
    //Quite similar to Valid Palindrome I
    bool isvalid(string s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    bool validPalindrome(string s) 
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return isvalid(s,i+1,j)||isvalid(s,i,j-1);
            
            i++;
            j--;
        }
        //For eg: aabbcaa we check for "bbc"
        //First we delete c and check if "bb" is a palindrome(delete j from (i to j))
        //Secondly we delete b and check if "bc" is a palindrome(delete i from (i to j))
        //We use OR as we can delete at most one character
        
        return true;
    }
};