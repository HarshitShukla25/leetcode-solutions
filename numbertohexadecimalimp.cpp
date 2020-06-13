class Solution {
public:
    string toHex(int num) {
        string ans = "";
        for(int i = 0 ; i<8 ; i++){
            int x = 0;
            for(int j = 0 ; j < 4 ; j++){
                x = x|(num&(1<<j));
            }
            if(x < 10)
                 ans = to_string(x) + ans;
            else if(x == 10)
                 ans = "a" + ans;
            else if(x == 11)
                 ans = "b" + ans;
            else if(x == 12)
                 ans = "c" + ans;
            else if(x == 13)
                 ans = "d" + ans;
            else if(x == 14)
                 ans = "e" + ans;
            else
                 ans = "f" + ans;
            num = num>>4;
            if(num == 0)
                break;
        }
        return ans;
    }
};