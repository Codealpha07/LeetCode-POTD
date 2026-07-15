class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n; // gcd(n*n, n+n*n) -> gcd(n*n, n(1+n)) -> n*gcd(n, n+1) = 1 -> n 
    }
};