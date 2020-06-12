class Solution {
public:
    bool buddyStrings(string A, string B) 
    {
        if(A.size()!=B.size())
            return false;
        if(A==B)
        {
            int freq[26]={0};
            for(int i=0;i<A.size();i++)
            {
                freq[A[i]-'a']++;
                if(freq[A[i]-'a']>=2)
                    return true;
            }
            return false;
        }
        int count=0;
        char swap;
        int index;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]!=B[i])
            {
                if(count==1)
                {
                    char temp=A[i];
                    A[i]=swap;
                    A[index]=temp;
                    return A==B;
                }
                swap=A[i];
                index=i;
                count++;
                
            }  
            if(count>2)
                return false;
        }
        return A==B;
    }
};