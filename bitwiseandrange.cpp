class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      int count = 0;
        int mt = m;
        int nt = n;
        while(mt != nt){
            mt >>= 1;
            nt >>= 1;
            count++;
        }
        return nt << count;
    }
};