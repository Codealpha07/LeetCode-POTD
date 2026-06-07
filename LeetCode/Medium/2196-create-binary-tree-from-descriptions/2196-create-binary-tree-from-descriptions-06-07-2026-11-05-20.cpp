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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> children;
        for(auto &d : descriptions) {
            int p = d[0], c = d[1], isLeft = d[2];
            if(!m.count(p)) m[p] = new TreeNode(p);
            if(!m.count(c)) m[c] = new TreeNode(c);

            if(isLeft) m[p]->left = m[c];
            else m[p]->right = m[c];
            children.insert(c);
        }
        for(auto &d : descriptions) {
            int p = d[0];
            if(!children.count(p)) return m[p];
        }
        return nullptr;
    }
};