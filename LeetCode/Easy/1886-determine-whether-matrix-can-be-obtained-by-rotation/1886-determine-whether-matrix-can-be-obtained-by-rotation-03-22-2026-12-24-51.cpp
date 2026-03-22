class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target) return true;
        for(int i=0; i<3; i++){
            if(rotate(mat, target)) return true;
        }
        return false;
    }
private:
    bool rotate(vector<vector<int>> &mat, vector<vector<int>>& target){
        for(int i=0; i<mat.size(); i++){
            for(int j=i; j<mat[0].size(); j++){
                swap(mat[i][j], mat[j][i]);     // transpose of matrix.
            }
        }
        for(int i=0; i <mat.size(); i++) {
            reverse(mat[i].begin(),mat[i].end());       // reverse each row.
        }
        return mat==target;
    }
};