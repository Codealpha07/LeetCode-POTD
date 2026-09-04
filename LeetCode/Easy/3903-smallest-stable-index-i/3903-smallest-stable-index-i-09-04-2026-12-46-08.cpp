class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> preMax(n), suffMin(n);
        preMax[0] = nums[0];
        suffMin.back() = nums.back();
        for(int i=1; i<n; i++){
            preMax[i] = max(preMax[i-1], nums[i]);
            suffMin[n-1-i] = min(suffMin[n-i], nums[n-1-i]);
        }
        for(int i=0; i<n; i++){
            if(preMax[i]-suffMin[i]<=k) return i;
        }
        return -1;
    }
};