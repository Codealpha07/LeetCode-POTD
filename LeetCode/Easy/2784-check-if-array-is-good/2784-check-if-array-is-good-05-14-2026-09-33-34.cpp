// sorting -> O(nlogn), O(1)

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]!=i+1) return false;
        }
        return nums.back()==nums.size()-1;
    }
};