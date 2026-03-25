class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> rs(m, 0), cs(n, 0);
        long long gs = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                gs += grid[i][j];
                rs[i] += grid[i][j];
                cs[j] += grid[i][j];
            }
        }
        
        if (n > 1) {
            long long currSum = 0;
            for (int i = 0; i < n - 1; i++) {
                currSum += cs[i];
                if (gs - currSum == currSum) return true;
            }
        }

        if (m > 1) {
            long long currSum = 0;
            for (int i = 0; i < m - 1; i++) {
                currSum += rs[i];
                if (gs - currSum == currSum) return true;
            }
        }

        return false;
    }
};

