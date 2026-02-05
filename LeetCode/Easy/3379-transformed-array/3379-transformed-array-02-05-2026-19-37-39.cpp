class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0; i<n; i++){
            int j = nums[i]%n;
            if(nums[i]==0) result[i] = j;
            if(nums[i]>0) result[i] = nums[(i+j)%n];
            else{
                result[i] = nums[(i+j+n) % n];
            }
        }
        return result;
    }
};