class Solution {
    unordered_map<unsigned long, int> map_;
public:
    int recursive(int low, int high) {
        if (low > high) return 0;
        
        if (low == high) return 1;
        
        unsigned long idx = 0;
        int sum = 0;
        int l = 0;
        int r = 0;
        for (int i = low; i <= high; i++) {
            
            idx = ((i-1)<<8)+low;
            if (0 == map_.count(idx)) {
                map_[idx] = recursive(low, i-1);
            }
            l = max(1, map_[idx]);
            
            idx = (high<<8)+(i+1);
            if (0 == map_.count(idx)) {
                map_[idx] = recursive(i+1, high);
                
            }
            r = max(1, map_[idx]);
            
            
            sum += l*r;
        }
        
        return sum;
    }
    
    int numTrees(int n) {
        int sum = recursive(1, n);
        return sum;
    }
};