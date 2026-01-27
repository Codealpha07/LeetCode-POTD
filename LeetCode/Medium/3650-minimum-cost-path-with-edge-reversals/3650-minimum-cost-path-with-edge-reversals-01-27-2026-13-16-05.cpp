class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto e:edges){
            int u=e[0], v=e[1], w=e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2*w}); 
        }
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,0}); // {dist, node}
        dist[0] = 0;
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dist[node]) continue;

            for (auto it : adj[node]) {
                int next = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[next]) {
                    dist[next] = dist[node] + wt;
                    pq.push({dist[next], next});
                }
            }
        }
        return dist[n-1];
    }
};