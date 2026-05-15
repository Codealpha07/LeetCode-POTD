class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int l = 0, h = n-1;
        while(h>l){
            int mid = (h+l)>>1;
            if(nums[mid]>nums[h]) l=mid+1;
            else h=mid;
        }
        return nums[l];
    }
};