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
    // Doing it using zero based tree indexing 
    // parent -> i, left child -> 2*i+1, right child -> 2*i+2
    int widthOfBinaryTree(TreeNode* root) {
        int max_width = 1;
        queue<pair<TreeNode*, int>> q; // node, index
        q.push({root, 0});
        while(!q.empty()){
            int sz = q.size();
            int leftMostNodeIdx = q.front().second;
            int rightMostNodeIdx = q.back().second;

            max_width = max(max_width, rightMostNodeIdx-leftMostNodeIdx+1);

            for(int i=0; i<sz; i++){
                pair<TreeNode*, int> p = q.front();
                TreeNode* node = p.first;
                // most imp : now assign the new nodes index from zero onwards itself.
                // if we wouldn't do this then the skewed tree leads to integer overflow.  
                long long idx = p.second-leftMostNodeIdx;
                q.pop();
                if(node->left){
                    q.push({node->left, 2*idx+1});
                }
                if(node->right){
                    q.push({node->right, 2*idx+2});
                }
            }
        }
        return max_width;
    }
};