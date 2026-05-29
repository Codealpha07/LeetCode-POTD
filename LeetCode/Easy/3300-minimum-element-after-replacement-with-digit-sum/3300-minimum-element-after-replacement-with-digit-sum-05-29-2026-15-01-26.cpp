class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = 36;
        for(int &i:nums){
            ans = min(ans, digitSum(i));
        }
        return ans;
    }
private:
    int digitSum(int n){
        int ans = 0;
        while(n){
            ans+=n%10;
            n/=10;
        }
        return ans;
    }
};