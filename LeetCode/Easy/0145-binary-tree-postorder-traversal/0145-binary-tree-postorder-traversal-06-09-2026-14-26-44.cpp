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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st1;
        vector<int> ans;
        if(!root) return ans;
        st1.push(root);
        while(!st1.empty()){
            // Take out the top element and push it n ans
            TreeNode* node = st1.top(); st1.pop();
            ans.push_back(node->val);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};