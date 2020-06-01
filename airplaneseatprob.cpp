class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n==1) return 1.0;
        return 0.5;
    }
                      
};

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n==1) return 1.0;
        return 1.0/n + (n-2)*nthPersonGetsNthSeat(n-1)/n;
            }
                      
};

