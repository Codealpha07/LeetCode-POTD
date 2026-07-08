class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        // compressed non-zero digits
        vector<int> d;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                d.push_back(s[i] - '0');
                pos.push_back(i);
            }
        }

        int m = d.size();

        // prefix digit sums
        vector<long long> prefSum(m + 1, 0);

        // prefix concatenated number
        vector<long long> prefNum(m + 1, 0);

        // powers of 10
        vector<long long> pw(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + d[i];
            prefNum[i + 1] = (prefNum[i] * 10 + d[i]) % MOD;
            pw[i + 1] = pw[i] * 10 % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            // first non-zero >= l
            int L = lower_bound(pos.begin(), pos.end(), l) - pos.begin();

            // first non-zero > r
            int R = upper_bound(pos.begin(), pos.end(), r) - pos.begin();

            if (L == R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L;

            long long x =
                (prefNum[R] - prefNum[L] * pw[len] % MOD + MOD) % MOD;

            long long sum = prefSum[R] - prefSum[L];

            ans.push_back(x * (sum % MOD) % MOD);
        }

        return ans;
    }
};