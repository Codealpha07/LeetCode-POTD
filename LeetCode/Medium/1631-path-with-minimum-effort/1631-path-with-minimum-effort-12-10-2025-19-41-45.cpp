class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        const int INF = 1e9;
        
        // dist[x][y] = minimum effort needed to reach (x, y)
        vector<vector<int>> dist(n, vector<int>(m, INF));
        
        // min-heap: {effort, {x, y}}
        using T = pair<int, pair<int,int>>;
        priority_queue<T, vector<T>, greater<T>> pq;
        
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            pq.pop();
            auto [x, y] = cell;
            
            // If this is an outdated entry, skip
            if (d != dist[x][y]) continue;
            
            // Early exit: reached target
            if (x == n - 1 && y == m - 1) return d;
            
            for (auto &dd : dir) {
                int nx = x + dd[0];
                int ny = y + dd[1];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                
                int diff = abs(heights[x][y] - heights[nx][ny]);
                int nd = max(d, diff);  // effort = max edge diff along path
                
                if (nd < dist[nx][ny]) {
                    dist[nx][ny] = nd;
                    pq.push({nd, {nx, ny}});
                }
            }
        }
        // Should never reach here
        return 0;
    }
};
