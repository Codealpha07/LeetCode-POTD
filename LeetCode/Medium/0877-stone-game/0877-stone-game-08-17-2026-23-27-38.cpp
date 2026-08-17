class Solution {
public:
    vector<vector<int>> dp;
    int rec(vector<int>& piles, int l, int r) {
        if (l==r) return piles[l];
        if (dp[l][r] != -1) return dp[l][r];
        int takeLeft = piles[l] - rec(piles, l+1, r);
        int takeRight = piles[r] - rec(piles, l, r-1);
        return dp[l][r] = max(takeLeft, takeRight);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp.assign(n, vector<int>(n, -1));
        return rec(piles, 0, n-1)>0;
    }
};