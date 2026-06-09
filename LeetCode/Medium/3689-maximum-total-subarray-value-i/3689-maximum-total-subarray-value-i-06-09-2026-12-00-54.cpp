class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        ans = *max_element(nums.begin(), nums.end());
        ans -= *min_element(nums.begin(), nums.end());
        return 1LL*ans*k;
    }
};