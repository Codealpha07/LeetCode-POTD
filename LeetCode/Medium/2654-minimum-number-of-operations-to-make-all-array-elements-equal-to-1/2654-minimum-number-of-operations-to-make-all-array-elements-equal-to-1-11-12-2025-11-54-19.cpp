class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt=0;
        for(int i:nums) cnt+=(i==1);
        if(cnt) return n-cnt;
        int res=INT_MAX;
        for(int i=0; i<n; i++){
            int g = nums[i];
            for (int j=i+1; j<n; j++) {
                g = __gcd(g, nums[j]);
                if (g==1) {
                    res=min(res, j - i + n - 1);
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};