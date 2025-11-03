class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int ans = 0;
        int i = 1;
        int total=neededTime[0], high=neededTime[0];
        while(i<n){
            if(colors[i]==colors[i-1]){
                total+=neededTime[i];
                high = max(high, neededTime[i]);
            }
            else{
                ans += total-high;
                total=neededTime[i];
                high=neededTime[i];
            }
            i++;
        }
        ans += total-high;
        return ans;
    }
};