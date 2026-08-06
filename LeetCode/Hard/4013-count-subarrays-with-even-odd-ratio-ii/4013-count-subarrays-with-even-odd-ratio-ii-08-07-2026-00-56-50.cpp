class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<long long> sorted;
        sorted.push_back(0);

        long long pref = 0;
        long long ans = 0;

        for (int x : nums) {

            if (x %2) pref += a;
            else pref -= b;

            // prefixes <= pref
            ans += upper_bound(sorted.begin(), sorted.end(), pref) - sorted.begin();

            // insert while keeping vector sorted
            sorted.insert(upper_bound(sorted.begin(), sorted.end(), pref), pref);
        }
        return ans;
    }
};