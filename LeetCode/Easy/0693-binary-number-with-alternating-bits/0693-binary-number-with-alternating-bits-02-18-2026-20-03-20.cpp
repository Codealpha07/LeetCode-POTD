class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n&1;
        while((n&1)==prev){
            n>>=1;
            prev = 1-prev;
        }
        return n==0;
    }
};