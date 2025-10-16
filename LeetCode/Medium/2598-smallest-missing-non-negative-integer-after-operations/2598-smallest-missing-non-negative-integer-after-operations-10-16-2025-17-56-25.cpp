class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int v) {
        int n = nums.size();
        vector<int> lastUsed(v, 0);
        unordered_map<int, int> freq;
        for (auto num : nums) {
            int r = num % v;
            if (r < 0) r += v;
            int val = r + v * lastUsed[r];
            freq[val]++;
            lastUsed[r]++;
        }
        for (int i = 0; i <= n; i++) {
            if (freq[i] == 0)
                return i;
        }
        return n;
    }
};
