class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(), nums.rend());
        long long total = 0;
        int i = 0;
        while(i<k){
            if(mul>0){
                total = total + (long long)nums[i++]*mul;
                mul--;
            }
            else total += nums[i++];
        }
        return total;
    }
};