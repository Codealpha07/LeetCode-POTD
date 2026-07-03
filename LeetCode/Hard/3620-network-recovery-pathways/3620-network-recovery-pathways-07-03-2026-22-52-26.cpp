class Solution {
public:
    /*
    Hint : Convert the question in this way : 
    Find the maximum edge score X such that:
    You can reach from node 0 to node n - 1
    Only use online nodes and edges with score ≥ X
    The total path cost is ≤ k
    Return the maximum X that satisfies all conditions, or -1 if impossible.

    Approach : 
    Set low = 0 and high = 1e9 (maximum edge weight)
    For each mid (potential threshold):
        Filter edges that have score >= mid and only connect online nodes
        Construct the graph with these edges
        Run Dijkstra from node 0 to node n - 1
        If a path is found within cost k, update best = mid, and try for higher values
        Else, try lower values
    */
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int ans = -1;
        int l = 0, r=1e9;
        // Binary search 
        while(l<=r){
            int mid = (l+r)>>1; // Potential candidate for the ans

            // Keep only valid edges (weight <= mid)
            vector<vector<pair<int, int>>> adj(online.size());
            for (auto& e : edges) {
                int u = e[0], v = e[1], c = e[2];
                if (c >= mid && online[u] && online[v]) {
                    adj[u].emplace_back(v,c);
                }
            }

            // mid is good to go.
            if(check(adj, k)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        return ans;
    }
private:
    bool check(vector<vector<pair<int, int>>>& adj, long long k){
        int n = adj.size();
        // Dijkstra
        long long totalScore = 4e18;
        vector<long long> dist(n, 4e18);
        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>>pq;
        pq.emplace(0,0); // TotalScore, src
        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();
            if(d>dist[u]) continue;
            if(u==n-1){
                totalScore = d;
                break;
            }
            for(auto [v,w]: adj[u]){
                if(dist[v]>d+w){
                    dist[v] = d+w;
                    pq.emplace(dist[v],v);
                }
            }
        }
        return (totalScore<=k);
    }
};