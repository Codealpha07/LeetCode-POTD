class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)>>1;
            if(nums[mid]==target) return mid;
            
            // Check if the left part is sorted
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && target<=nums[mid]){
                    r=mid-1;
                }
                else l=mid+1;
            }
            // The right half is sorted instead
            else{
                if(nums[r]>=target && target>=nums[mid]){
                    l=mid+1;
                }
                else r=mid-1;
            }
        }
        return -1;
    }
};