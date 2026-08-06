class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int> preEven(n);
        if(nums[0]%2==0) preEven[0] = 1;
        for(int i=1; i<n; i++){
            preEven[i] = preEven[i-1]+(1-nums[i]%2);
        }
        int ans = 0;
        for(int i=0; i<n; i++){ // i-> ending position
            for(int j=0; j<=i; j++){ // j-> starting position for subarray : 0....i
                int x=preEven[i], y=0;
                if(j!=0) x -= preEven[j-1];
                y = (i-j+1)-x;
                if(y!=0 && x*b<=y*a) ans++;
            }
        }
        return ans;
    }
};