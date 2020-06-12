class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n= digits.size();
        if(digits[n-1]!=9)
        {
            digits[n-1]+=1;
            return digits;
        }
        else
        {
            int i=0;
            while(i<n)
            {
                if(digits[n-i-1]==9){digits[n-i-1]=0;i++;}
                else break;
                

            }
            if(i==n) {digits.insert(digits.begin(),1);return digits;}
            digits[n-i-1]+=1;
            return digits;
            
        }
        return digits;
    }
};