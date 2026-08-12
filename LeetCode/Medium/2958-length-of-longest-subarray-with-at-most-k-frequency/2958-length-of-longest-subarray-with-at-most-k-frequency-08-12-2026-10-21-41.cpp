class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int best = 1;
        int l=0, r=0;
        while(r<n){
            if(freq[nums[r]]==k){
                best = max(best, r-l);
                while(l<=r && freq[nums[r]]!=k-1){
                    freq[nums[l]]--; l++;
                }
            }
            freq[nums[r]]++;
            r++;
        }
        best = max(best, r-l);
        return best;
    }
};