class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        int reachable = 0;

        for (int i = 1; i < n; i++) {

            // Add new index entering window
            if (i - minJump >= 0)
                reachable += dp[i - minJump];

            // Remove old index leaving window
            if (i - maxJump - 1 >= 0)
                reachable -= dp[i - maxJump - 1];

            dp[i] = (reachable > 0 && s[i] == '0');
        }

        return dp[n - 1];
    }
};