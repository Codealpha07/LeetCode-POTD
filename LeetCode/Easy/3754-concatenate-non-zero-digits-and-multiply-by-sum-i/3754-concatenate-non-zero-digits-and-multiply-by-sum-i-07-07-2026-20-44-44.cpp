class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0;
        int mul = 1;
        while(n){
            int rem = n%10;
            if(rem!=0){
                x = x+mul*rem;   
                sum += rem;
                mul*=10;
            }
            n = n/10;
        }
        return x*sum;
    }
};