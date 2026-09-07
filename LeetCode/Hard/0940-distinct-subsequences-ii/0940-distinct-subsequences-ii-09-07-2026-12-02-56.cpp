class Solution {
public:
    int distinctSubseqII(std::string s) {
        long long MOD = 1e9 + 7;
        vector<long long> ans(26, 0); // number of distinct subsequences of the part processed so far that start with character c

        // Process the string in reverse
        for (int i = s.length()-1; i >= 0; --i) {
            long long total = 0;
            for (long long val : ans) {
                total = (total + val) % MOD;
            }
            ans[s[i] - 'a'] = (total + 1) % MOD;
        }
        long long final_sum = 0;
        for (long long val : ans) {
            final_sum = (final_sum + val) % MOD;
        }

        return final_sum;
    }
};