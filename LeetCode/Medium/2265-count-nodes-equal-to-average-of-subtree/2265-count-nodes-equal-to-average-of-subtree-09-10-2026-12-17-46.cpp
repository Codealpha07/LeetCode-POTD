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
    int count = 0;
    pair<int, int> sumDfs(TreeNode* root, int &count){
        if(!root) return {0,0};
        int n = 1;
        auto [leftTotal, leftCnt] = sumDfs(root->left, count);
        auto [rightTotal, rightCnt] = sumDfs(root->right, count);
        n += leftCnt + rightCnt;
        int total = root->val + leftTotal + rightTotal;
        if(root->val == total/n) count++;
        return {total, n};
    }
    int averageOfSubtree(TreeNode* root) {
        sumDfs(root, count);
        return count;
    }
};