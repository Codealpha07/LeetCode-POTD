class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (i==0 && j==0) {
                    ans[i][j] = 1;
                } 
                else if(j==0){
                    ans[i][j] = ((ans[i-1][m-1]%MOD)*(grid[i-1][m-1]%MOD))%MOD;
                }
                else{
                    ans[i][j] = ((ans[i][j-1]%MOD)*(grid[i][j-1]%MOD))%MOD;
                }
            }
        }
        long long right = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                ans[i][j] = (ans[i][j]*right)%MOD;
                right = (right*grid[i][j]%MOD)%MOD;
            }
        }
        return ans;
    }
};