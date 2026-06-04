class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int currSum = 0;
        int bestLen = INT_MAX;

        for (int r=0; r<n; r++) {
            currSum += nums[r];
            while (currSum >= target) {
                bestLen = min(bestLen, r - l + 1);
                currSum -= nums[l++];
            }
        }
        return bestLen == INT_MAX ? 0 : bestLen;
    }
};