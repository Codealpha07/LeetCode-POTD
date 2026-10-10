
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL*k1+k2;
        vector<long long> diff(n);
        long long maxDiff = 0, totalDiff = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            totalDiff += diff[i];
        }
        // All differences can become zero.
        if (k >= totalDiff) return 0;
        // Find the smallest feasible threshold.
        long long low = 0, high = maxDiff;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long operations = 0;

            for (long long d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
                if (operations > k) break;
            }

            if (operations <= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long long threshold = low;
        long long used = 0;
        long long ans = 0;
        long long countAtThreshold = 0;

        for (long long d : diff) {
            if (d > threshold) {
                used += d - threshold;
                d = threshold;
            }

            if (d == threshold) {
                countAtThreshold++;
            }

            ans += d * d;
        }

        // Distribute leftover operations across threshold values.
        long long remaining = k - used;
        ans -= remaining * (2 * threshold - 1);

        return ans;
    }
};
