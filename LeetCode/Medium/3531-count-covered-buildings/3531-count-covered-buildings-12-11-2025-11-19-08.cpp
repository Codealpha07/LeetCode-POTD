class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        if (n < 3) return 0;
        vector<pair<int, int>> rowLimits(n, {n, -1});
        vector<pair<int, int>> colLimits(n, {n, -1});
        for (auto &b : buildings) {
            int r = b[0] - 1, c = b[1] - 1;

            rowLimits[r].first = min(rowLimits[r].first, c);
            rowLimits[r].second = max(rowLimits[r].second, c);

            colLimits[c].first = min(colLimits[c].first, r);
            colLimits[c].second = max(colLimits[c].second, r);
        }
        int ans = 0;
        for (auto &b : buildings) {
            int x = b[0] - 1, y = b[1] - 1;
            if (rowLimits[x].first < y && y < rowLimits[x].second &&
                colLimits[y].first < x && x < colLimits[y].second) {
                ans++;
            }
        }
        return ans;
    }
};
