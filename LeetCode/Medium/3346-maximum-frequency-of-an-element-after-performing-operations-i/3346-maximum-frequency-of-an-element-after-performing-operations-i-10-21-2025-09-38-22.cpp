class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOp) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> freq;
        for(int x:nums) freq[x]++;
        vector<int> lowerRange(n), upperRange(n);
        for(int i=0; i<n; i++) lowerRange[i]=nums[i]-k;
        for(int i=0; i<n; i++) upperRange[i]=nums[i]+k;

        int ans = 1;
        for(int i=lowerRange[0]; i<upperRange[n-1]; i++){
            int r = upper_bound(lowerRange.begin(), lowerRange.end(), i)-lowerRange.begin()-1;
            int l = lower_bound(upperRange.begin(), upperRange.end(), i)-upperRange.begin();
            ans = max(ans, min(r-l+1, numOp+freq[i]));
        }
        return ans;
    }
};