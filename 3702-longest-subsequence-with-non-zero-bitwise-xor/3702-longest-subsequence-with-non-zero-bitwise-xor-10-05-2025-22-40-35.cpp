class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0, count=0,zeroes=0;
        for(int i:nums){
            x^=i;
            count++;
            zeroes+=(i==0);
        }
        if(zeroes==nums.size()) return 0;
        if(x!=0) return count;
        return --count;
    }
};