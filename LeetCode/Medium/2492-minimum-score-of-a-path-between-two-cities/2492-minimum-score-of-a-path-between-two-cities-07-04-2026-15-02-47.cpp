class Solution {
public:
    int ans = INT_MAX;

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : roads) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            int w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool> vis(n, false);
        dfs(0, vis, adj);
        return ans;
    }
private:
    void dfs(int node, vector<bool>& vis, vector<vector<pair<int,int>>>& adj) {
        vis[node] = true;
        for (auto [neighbor, w] : adj[node]) {
            // Every edge in this connected component is a candidate.
            ans = min(ans, w);
            if (!vis[neighbor]) {
                dfs(neighbor, vis, adj);
            }
        }
    }
};