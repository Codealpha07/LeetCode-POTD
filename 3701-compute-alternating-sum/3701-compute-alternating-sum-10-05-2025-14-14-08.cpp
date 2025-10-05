class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int sign = 1;
        int ans = 0;
        for(int i:nums){
            ans+=i*sign;
            sign*=-1;
        }
        return ans;
    }
};