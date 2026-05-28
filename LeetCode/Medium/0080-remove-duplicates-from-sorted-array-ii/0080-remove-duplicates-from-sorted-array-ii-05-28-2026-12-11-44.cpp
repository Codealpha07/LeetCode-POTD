class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2) return n;
        int j=2;
        for(int i=2; i < nums.size(); i++){
            if(nums[i] != nums[j-1]){nums[j] = nums[i]; j++;}
            else if(j>1 && nums[j-1]!=nums[j-2]){nums[j]=nums[i]; j++;}
        }
        return j;
    }
};