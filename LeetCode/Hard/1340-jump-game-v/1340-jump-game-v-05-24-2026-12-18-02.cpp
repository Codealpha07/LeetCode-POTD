class Solution {
public:
    int dp[1001];

    int maxJumps(vector<int>& arr, int d) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;

        // Check for every index
        for(int i=0; i<arr.size(); i++){
            ans = max(ans, rec(i, arr, d));
        }
        return ans;
    }
private:
    // rec returns the maximum number of jumps starting from index i 
    int rec(int i, vector<int>& arr, int d){
        // Base case 
        if(i>=arr.size() || i<0) return 0;

        // Cache Check 
        if(dp[i]!=-1) return dp[i];

        //Compute
        int best = 1;
        int n = arr.size();
        for(int nxt=i+1; nxt<=min(n-1, i+d); nxt++){
            if(arr[nxt]>=arr[i]) break;
            best = max(best, 1+rec(nxt, arr, d));
        }
        for(int nxt=i-1; nxt>=max(0, i-d); nxt--){
            if(arr[nxt]>=arr[i]) break;
            best = max(best, 1+rec(nxt, arr, d));
        }

        // Save and return 
        return dp[i]=best;
    }
};