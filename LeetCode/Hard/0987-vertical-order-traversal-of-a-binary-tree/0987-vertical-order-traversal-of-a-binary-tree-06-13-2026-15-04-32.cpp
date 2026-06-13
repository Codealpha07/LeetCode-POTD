class Solution {
public:
    map<int, map<int, multiset<int>>> mp;
    void dfs(TreeNode* root, int row, int col){
        if(!root) return;
        mp[col][row].insert(root->val);
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for(auto &col : mp){
            vector<int> curr;
            for(auto &row : col.second){
                curr.insert(curr.end(),row.second.begin(),row.second.end());
            }
            ans.push_back(curr);
        }
        return ans;
    }
};