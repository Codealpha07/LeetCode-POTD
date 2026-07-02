class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n=grid[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n));

        pq.push({health-grid[0][0], {0, 0}});
        vis[0][0] = 1;
        while(!pq.empty()){
            auto [h, p] = pq.top(); pq.pop();
            auto [i, j] = p;
            if(h<=0) return 0;
            if(i==m-1 && j==n-1) return h>=1;
            for(auto d:dir){
                int new_i = i+d[0], new_j = j+d[1];
                if(new_i>=0 && new_j>=0 && new_i<m && new_j<n && !vis[new_i][new_j]){
                    vis[new_i][new_j] = true;
                    pq.push({h-grid[new_i][new_j], {new_i, new_j}});
                }
            }
        }
        return false;
    }
};