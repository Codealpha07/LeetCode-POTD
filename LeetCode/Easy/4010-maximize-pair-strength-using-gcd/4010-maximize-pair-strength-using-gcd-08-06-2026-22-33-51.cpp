class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = INT_MIN;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                long long val = (1LL*nums[i]*nums[j])/(1LL*gcd(nums[i], nums[j])*gcd(nums[i], nums[j]));
                ans = max(ans, val);
            }
        }
        return ans;
    }
};