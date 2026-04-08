class Solution {
public:
    const int MOD = 1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto q:queries){
            for(int idx=q[0]; idx<=q[1]; idx+=q[2]){
                nums[idx] = (nums[idx]*1LL*q[3])%MOD;
            }
        }
        int XOR = 0;
        for(auto num:nums){
            XOR ^= num;
        }
        return XOR;
    }
};