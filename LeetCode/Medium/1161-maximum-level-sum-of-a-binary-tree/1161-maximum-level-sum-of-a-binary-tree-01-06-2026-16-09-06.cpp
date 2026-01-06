/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    const int MAXL = 1e4+1;
    int maxLevelSum(TreeNode* root) {
        vector<long long> levelSum(MAXL, 0);
        int maxLevel = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto [node, level] = q.front();
            q.pop();
            levelSum[level]+=node->val;
            if(node->left) q.push({node->left, level+1});
            if(node->right) q.push({node->right, level+1});
            maxLevel=level;
        }
        int best=INT_MIN, ans=0;
        for(int i=0; i<=maxLevel; i++){
            if(levelSum[i]>best){
                best=levelSum[i]; ans=i+1;
            }
        }
        return ans;
    }
};