class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0; int r=0;
        unordered_map<int,int>m;
        int ans=0;
        while(r<nums.size()){
            m[nums[r]]++;
            if(m[nums[r]]<=k){
                ans=max(r-l+1,ans);
            }
            while(m[nums[r]]>k){
                m[nums[l]]--;
                l++;
            }
            r++;
        }
        return ans;
        
    }
};