class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int v) {
        vector<int> cnt(v, 0);
        for (long long num : nums) {
            int r = (int)((num % v + v) % v); // normalize to [0, v)
            cnt[r]++;
        }

        // Greedily consume residues in round-robin order
        for (int i = 0; ; ++i) {
            int r = i % v;
            if (cnt[r] == 0) return i;
            cnt[r]--;
        }
        // unreachable
        // return -1;
    }
};
