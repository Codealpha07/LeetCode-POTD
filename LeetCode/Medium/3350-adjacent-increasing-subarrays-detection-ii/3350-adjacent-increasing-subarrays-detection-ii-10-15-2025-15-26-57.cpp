class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prev=-1, curr;
        int k = 0;
        int r=1,l=0;
        while(r<nums.size()){
            if(nums[r]>nums[r-1]) r++;
            else{
                if(prev==-1) prev = r-l;
                else{
                    curr = r-l;
                    k = max({k, prev/2, min(prev, curr)});
                    prev=curr;
                }
                l=r;
                r++;
            }
        }
        curr=r-l;
        k = max({k, prev/2, curr/2, min(prev, curr)});
        return k;
    }
};