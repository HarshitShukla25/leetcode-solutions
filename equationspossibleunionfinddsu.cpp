class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> arr(26);
        for(int i=0;i<arr.size();i++)
            arr[i] = i;
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                int val = arr[equations[i][0]-'a'];
                int put = arr[equations[i][3]-'a'];
                for(int j=0;j<arr.size();j++)
                {
                    if(arr[j]==val)
                        arr[j]=put;
                }
            }
        }
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
                if(arr[equations[i][0]-'a']==arr[equations[i][3]-'a'])
                    return false;
        }
        return true;
    }
};