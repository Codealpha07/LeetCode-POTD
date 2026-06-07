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
        int ans = check(root, ""); 
        return ans;
    }
private:
    int check(TreeNode* root, string curr){
        if(!root) return 0;
        curr += char(root->val+'0');
        if(!root->left && !root->right){
            int pathSum = stoi(curr);
            return pathSum;
        }
        return check(root->left, curr)+check(root->right, curr);
    }
};