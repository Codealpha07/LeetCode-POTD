class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if(x<0) sign=-1;
        if(x==INT_MIN) return 0;
        x *= sign;
        int res = 0;
        while(x){
            int rem = x%10;
            if(res <= (INT_MAX/10)-rem+1){
                res = res*10+rem;
            }
            else return 0;
            x /=10;
        }
        return res*sign;
    }
};