class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // Sort the array to apply the greedy strategy
        sort(nums.begin(), nums.end());
        
        int nextAvailable = INT_MIN; // Tracks the smallest unused value
        int distinctCount = 0;
    
        for (int num : nums) {
            // Determine the minimum value in range [num - k, num + k]
            int start = max(num - k, nextAvailable);
            if (start <= num + k) {
                // If within range, use it and update nextAvailable
                nextAvailable = start + 1;
                ++distinctCount;
            }
        }
        
        return distinctCount;
    }
};