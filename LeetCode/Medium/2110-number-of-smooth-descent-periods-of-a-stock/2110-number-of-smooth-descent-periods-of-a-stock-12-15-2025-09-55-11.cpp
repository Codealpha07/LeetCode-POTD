class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = 0;
        long long currLen = 1;
        for(int i=1; i<n; i++){
            if(prices[i]-prices[i-1]==-1){
                currLen++;
            }
            else{
                ans+=(currLen*(currLen+1))/2;
                currLen=1;
            }
        }
        ans+=(currLen*(currLen+1))/2;
        return ans;
    }
};