class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> s;
        
            //removing the peak elements
        for(char c : num)
        {
            while(!s.empty() && k>0 && s.top()>c)
            {
                s.pop();
                k--;
            }
            if(!s.empty() || c!='0')
                s.push(c);
        }
        //Now delete elements from top of stack agar k abhi bhi nhi khatam hua
        while(!s.empty()&&k>0)
        {
            s.pop();
            k--;
        }
        if(s.empty())
            return "0";
        // kuch ni bs stack ko string me kr rhe aur koi extra space ni use kr rhe
        
        while(!s.empty())
        {
            num[n-1] = s.top();
            s.pop();
            n--;
        }
        return num.substr(n);
        
        
    }
};