class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(),0);
        if(total%2==1) return false;
        total /= 2;
        vector<vector<bool>> dp(nums.size(), vector<bool>(total+1));
        for(int i=0; i<nums.size(); i++) dp[i][0]=true;
        dp[0][nums[0]] = true;
        for(int i=1; i<nums.size(); i++){
            for(int target=1; target<=total; target++){
                bool notTake = dp[i-1][target];
                bool take = false;
                if(nums[i]<=target) take = dp[i-1][target - nums[i]];
                dp[i][target] = take | notTake;
            } 
        }
        return dp[nums.size()-1][total];
    }
};