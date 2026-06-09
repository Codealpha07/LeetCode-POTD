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
    int ans = 0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int leftPathLen = solve(root->left);
        int rightPathLen = solve(root->right);
        int totalPath = leftPathLen+rightPathLen; // Total path at root and its child
        ans = max(ans, totalPath);
        return 1+max(leftPathLen, rightPathLen); // +1 becuase the root is connected to its parent by 1 edge.  
    }
    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return ans;
    }
};