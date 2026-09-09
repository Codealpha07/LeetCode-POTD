class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        ans += max(0LL, 1LL*(n-999)); 
        ans += max(0LL, n-999999);
        ans += max(0LL, n-999999999);
        ans += max(0LL, n-999999999999);
        ans += max(0LL, n-999999999999999);
        if(ans==1000000000000000) ans++;
        return ans;
    }
};