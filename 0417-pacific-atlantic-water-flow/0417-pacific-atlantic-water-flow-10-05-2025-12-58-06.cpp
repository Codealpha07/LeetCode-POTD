class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<pair<int, int>>> reachables(m, vector<pair<int, int>>(n, {0,0}));
        
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        // reachable from pacific ocean
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++) {reachables[i][0].first=1; q.push({i,0});}
        for(int i=0; i<n; i++) {reachables[0][i].first=1; q.push({0,i});}
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(auto d:dir){
                int nx = x+d[0], ny =y+d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(heights[nx][ny]>=heights[x][y] && !reachables[nx][ny].first){
                    q.push({nx, ny});
                    reachables[nx][ny] = {1,0};
                }
            }
        }

        // reachable from atlantic 
        queue<pair<int, int>> q2;
        for(int i=0; i<m; i++) {reachables[i][n-1].second=1; q2.push({i, n-1});}
        for(int i=0; i<n; i++) {reachables[m-1][i].second=1; q2.push({m-1,i});}
        while(!q2.empty()){
            auto [x,y] = q2.front(); q2.pop();
            for(auto d:dir){
                int nx = x+d[0], ny =y+d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if(heights[nx][ny]>=heights[x][y] && !reachables[nx][ny].second ){
                    q2.push({nx, ny});
                    reachables[nx][ny].second=1;
                }
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (reachables[i][j].first == 1 && reachables[i][j].second == 1) res.push_back({i, j});
            }
        }
        return res;
    }
};