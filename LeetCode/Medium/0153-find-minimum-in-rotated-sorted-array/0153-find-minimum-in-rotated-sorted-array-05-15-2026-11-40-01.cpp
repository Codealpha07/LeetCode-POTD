class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int l = 0, h = n-1;
        if(nums[h]>nums[l]) return nums[l];
        while(h>l){
            int mid = (h+l)>>1;
            if(h-l==1) return min(nums[l], nums[h]);
            if(nums[l]>nums[mid]) h=mid;
            else if(nums[mid]>nums[h]) l=mid;
        }
        return -1;
    }
};