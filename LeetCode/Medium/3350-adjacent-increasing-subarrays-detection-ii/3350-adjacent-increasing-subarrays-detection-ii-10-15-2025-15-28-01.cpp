class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> ranges;
        int r=1,l=0;
        while(r<nums.size()){
            if(nums[r]>nums[r-1]) r++;
            else{
                ranges.push_back(r-l);
                l=r;
                r++;
            }
        }
        ranges.push_back(r-l);
        int k = ranges[0]/2;
        for(int i=1; i<ranges.size(); i++){
            k = max({k, ranges[i]/2, min(ranges[i], ranges[i-1])});
        }
        return k;
    }
};