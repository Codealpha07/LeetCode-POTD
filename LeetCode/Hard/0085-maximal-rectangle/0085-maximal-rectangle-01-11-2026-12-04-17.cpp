class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n=matrix[0].size();
        vector<int> left(n, 0), right(n, n), height(n, 0);
        // Area will be simply (r-l)*h
        int maxArea = 0;
        for(int i=0; i<m; i++){
            int curr_left = 0, curr_right=n;

            // For each column we will store the height coming from last row
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j]=0;
            }

            // left[j] = max(left[j], curr_left) -> left[j] is basically coming from last row ; so that the height matches 
            for(int j=0; j<n; j++){
                if(matrix[i][j]=='1') left[j]=max(left[j], curr_left);
                else curr_left=j+1, left[j]=0;
            }

            // right[j] = max(right[j], curr_right) -> right[j] is basically coming from last row ; so that the height matches 
            for(int j=n-1; j>=0; j--){
                if(matrix[i][j]=='1') right[j]=min(right[j], curr_right);
                else curr_right=j, right[j]=n;
            }

            for(int j=0; j<n; j++){
                maxArea = max(maxArea,(right[j]-left[j])*height[j]);
            }
        }
        return maxArea;
    }
};