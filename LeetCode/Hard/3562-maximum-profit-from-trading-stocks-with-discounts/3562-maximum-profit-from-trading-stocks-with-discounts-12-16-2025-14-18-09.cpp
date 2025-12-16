class Solution {
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        this->present = present;
        this->future = future;
        this->budget = budget;

        g.assign(n, {});
        for (auto& e : hierarchy) {
            g[e[0] - 1].push_back(e[1] - 1);
        }

        auto [dp0, dp1, _] = dfs(0);
        return dp0[budget];
    }

private:
    vector<vector<int>> g;
    vector<int> present, future;
    int budget;

    // returns {dp0, dp1, subtreeSize}
    tuple<vector<int>, vector<int>, int> dfs(int u) {
        int cost = present[u];
        int dCost = cost / 2;  // discounted cost

        vector<int> dp0(budget + 1, 0);  // parent not purchased
        vector<int> dp1(budget + 1, 0);  // parent purchased
        vector<int> subProfit0(budget + 1, 0);
        vector<int> subProfit1(budget + 1, 0);

        int uSize = cost;

        for (int v : g[u]) {
            auto [subDp0, subDp1, vSize] = dfs(v);
            uSize += vSize;

            for (int i = budget; i >= 0; i--) {
                for (int sub = 0; sub <= min(vSize, i); sub++) {
                    subProfit0[i] = max(subProfit0[i],
                                        subProfit0[i - sub] + subDp0[sub]);
                    subProfit1[i] = max(subProfit1[i],
                                        subProfit1[i - sub] + subDp1[sub]);
                }
            }
        }

        for (int i = 0; i <= budget; i++) {
            dp0[i] = dp1[i] = subProfit0[i];

            // buy u with discount (parent bought)
            if (i >= dCost) {
                dp1[i] = max(dp1[i],
                             subProfit1[i - dCost] + future[u] - dCost);
            }

            // buy u without discount
            if (i >= cost) {
                dp0[i] = max(dp0[i],
                             subProfit1[i - cost] + future[u] - cost);
            }
        }

        return {dp0, dp1, uSize};
    }
};
