class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size(), n=mat[0].size();
        vector<int> cntr(m,0), cntc(n,0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cntr[i]+=mat[i][j];
                cntc[j]+=mat[i][j];
            }
        }
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1 && cntr[i]==1 && cntc[j]==1){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};