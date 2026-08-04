class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=1; i<nums.size(); i++){
            int curr = nums[i-1];
            while(nums[i]-curr>1){
                ans.push_back(++curr);
            }
        }
        return ans;
    }
};