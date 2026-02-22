class Solution {
public:
    int binaryGap(int n) {
        int last = -1;     // position of previous 1-bit
        int pos = 0;       // current bit index
        int best = 0;
        while (n > 0) {
            if (n&1){       
                if (last!=-1) {
                    best = max(best, pos - last);
                }
                last = pos;
            }
            n >>= 1;
            pos++;
        }
        return best;
    }
};