class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx = nums[0];
        vector<int> pg(nums.size());
        pg[0]=nums[0];
        for(int i=1; i<nums.size(); i++){
            mx=max(mx, nums[i]);
            pg[i]=gcd(nums[i], mx);
        }
        sort(pg.begin(), pg.end());
        int i=0, j=nums.size()-1;
        long long ans = 0;
        while(i<j){
            ans+=gcd(pg[i++], pg[j--]);
        }
        return ans;
    }
};