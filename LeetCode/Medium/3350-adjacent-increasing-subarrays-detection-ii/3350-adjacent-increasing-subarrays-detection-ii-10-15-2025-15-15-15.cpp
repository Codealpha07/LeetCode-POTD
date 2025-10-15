class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<pair<int, int>> ranges;
        int r=1,l=0;
        while(r<nums.size()){
            if(nums[r]>nums[r-1]) r++;
            else{
                if(r-l>1) ranges.push_back({l,r-1});
                l=r;
                r++;
            }
        }
        ranges.push_back({l,r-1});
        int k = max(1, (ranges[0].second-ranges[0].first+1)/2);
        for(int i=1; i<ranges.size(); i++){
            k = max(k, (ranges[i].second-ranges[i].first+1)/2);
            if(ranges[i].first-ranges[i-1].second == 1){
                k = max(k, min((ranges[i].second-ranges[i].first+1), (ranges[i-1].second-ranges[i-1].first+1)));
            }
        }
        return k;
    }
};