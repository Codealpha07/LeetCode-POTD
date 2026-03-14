class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-2;
        // Find break point (first decreasing element)
        while(i>=0 && nums[i]>=nums[i+1]) i--;
        // i-> arr[i+1]>arr[i]
        
        // if,  i -> doesn't exist (i==0) -> reverse the array (already decreasing)
        if(i==-1){
            reverse(nums.begin(), nums.end());
            return;
        } 

        // find smallest number > arr[i] in the right half. 
        int j=n-1;
        while(j>i && nums[j]<=nums[i]) j--;

        // Swap both
        swap(nums[i], nums[j]);

        // Reverse the right half from (i+1....n-1)
        reverse(nums.begin()+i+1, nums.end());
    }
};