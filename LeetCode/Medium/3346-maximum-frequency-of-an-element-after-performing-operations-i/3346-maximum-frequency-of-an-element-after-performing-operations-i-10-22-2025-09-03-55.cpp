class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOp) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<long long, long long> freq;
        set<long long> val(nums.begin(), nums.end());
        for(int x:nums) freq[x]++;
        vector<long long> lowerRange(n), upperRange(n);
        for(int i=0; i<n; i++) lowerRange[i]=nums[i]-k, val.insert(lowerRange[i]);
        for(int i=0; i<n; i++) upperRange[i]=nums[i]+k, val.insert(upperRange[i]);

        long long ans = 1;
        for(long long i:val){
            long long r = upper_bound(lowerRange.begin(), lowerRange.end(), i)-lowerRange.begin()-1;
            long long l = lower_bound(upperRange.begin(), upperRange.end(), i)-upperRange.begin();
            ans = max(ans, min(r-l+1, numOp+freq[i]));
        }
        return ans;
    }
};