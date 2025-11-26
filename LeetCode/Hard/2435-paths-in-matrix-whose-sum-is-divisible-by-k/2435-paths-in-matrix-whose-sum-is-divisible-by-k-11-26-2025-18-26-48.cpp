class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n, K;
    int ans = 0;

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        K = k;
        dfs(0, 0, grid, grid[0][0] % K);
        return ans;
    }

    void dfs(int x, int y, vector<vector<int>>& grid, int currMod) {
        // If we reached destination
        if (x == m - 1 && y == n - 1) {
            if (currMod % K == 0)
                ans = (ans + 1) % MOD;
            return;
        }

        // Move Right
        if (y + 1 < n) {
            int nextMod = (currMod + grid[x][y+1]) % K;
            dfs(x, y+1, grid, nextMod);
        }

        // Move Down
        if (x + 1 < m) {
            int nextMod = (currMod + grid[x+1][y]) % K;
            dfs(x+1, y, grid, nextMod);
        }
    }
};
