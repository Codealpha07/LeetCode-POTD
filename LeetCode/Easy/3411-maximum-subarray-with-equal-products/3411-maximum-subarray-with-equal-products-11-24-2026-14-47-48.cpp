class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n-1; i++) {
            int currLCM = nums[i], currGCD = nums[i];
            long long prod = nums[i];

            for (int j = i + 1; j < n; j++) {
                currLCM = lcm(currLCM, nums[j]);
                currGCD = gcd(currGCD, nums[j]);
                prod *= nums[j];

                if (prod == (long long)currLCM * currGCD) {
                    ans = max(ans, j - i + 1);
                }
                
                // Stop the loop early to prevent overflow
                if (prod > (long long)INT_MAX) break;
            }
        }
        return ans;
    }

private:
    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }
};
