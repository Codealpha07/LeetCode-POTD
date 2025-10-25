class Solution {
public:
    int totalMoney(int n) {
        long long w = n / 7; 
        long long d = n % 7;   

        long long fullWeeks = 28LL*w+7LL*w*(w-1)/2;
        long long partial   = d * (2 * w + d + 1) / 2;

        return static_cast<int>(fullWeeks + partial);
    }
};
