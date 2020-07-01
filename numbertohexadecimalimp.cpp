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

///using unsigned int is a good way to deal with this
class Solution {
public:
    string toHex(int num) {
        char itoh[16] = {'0', '1','2', '3', '4', '5', '6', '7', '8',
                         '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string result="";
        
        //this basically does the two complement.
        //i.e., that is INT_MAX - num if it's negative.
        unsigned int num_non_negative = num;
        
        while(num_non_negative>=16){
            int remainder = num_non_negative%16;
            num_non_negative = num_non_negative/16;
            result=itoh[remainder]+result;
        }
        
        result=itoh[num_non_negative]+result;
        
        return result;
    }
};