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
    int sumNumbers(TreeNode* root) {
        int ans = check(root, 0); 
        return ans;
    }
private:
    int check(TreeNode* root, int pathSum){
        if(!root) return 0;
        pathSum = pathSum*10+root->val;
        if(!root->left && !root->right) return pathSum;
        return check(root->left, pathSum)+check(root->right, pathSum);
    }
};