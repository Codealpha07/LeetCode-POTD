class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        vector<int> heights(n);
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0) heights[j]=0;
                else heights[j]++;
            }
            vector<int> orderedHeights = heights;
            sort(orderedHeights.begin(), orderedHeights.end());
            for(int j=0; j<n; j++){
                ans = max(ans, orderedHeights[j]*(n-j));
            }
        }
        return ans;
    }
};