class Solution {
public:
    int arrangeCoins(int n) {
       long long i=1;
        long long sum = (i*(i-1)/2);
        long long nn = n;
        while(sum <= nn) {i++;sum = (i*(i-1)/2);}
        return int(i-2);
    }
};