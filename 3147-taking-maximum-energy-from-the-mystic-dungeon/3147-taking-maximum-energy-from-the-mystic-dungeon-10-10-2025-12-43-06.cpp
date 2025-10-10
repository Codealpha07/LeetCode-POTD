#include <vector>
#include <climits>

class Solution {
public:
    int maximumEnergy(std::vector<int>& energy, int k) {
        int n = energy.size();
        std::vector<int> sum(n, 0); // Initialize sum vector with size n and all values set to 0
        for (int i = 0; i < k; i++) {
            int count = 0;
            while (i + count * k < n) {
                sum[i] += energy[i + count * k];
                count++;
            }
        }
        for (int i = k; i < n - k; i++) {
            sum[i] = sum[i - k] - energy[i - k];
        }
        for (int i = n - k + 1; i < n; i++) {
            sum[i] = energy[i];
        }
        int max = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (sum[i] > max) {
                max = sum[i];
            }
        }
        return max;
    }
};
