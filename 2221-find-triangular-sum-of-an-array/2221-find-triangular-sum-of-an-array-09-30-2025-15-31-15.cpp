class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int m = nums.size();
        while(m>1){
            for(int i=0; i<m-1; i++){
                nums[i]+=nums[i+1];
                nums[i]%=10;
            }
            m--;
        }
        return nums[0]%10;
    }
};