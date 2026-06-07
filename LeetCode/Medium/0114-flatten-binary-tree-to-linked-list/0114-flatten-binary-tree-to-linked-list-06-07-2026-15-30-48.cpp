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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            // Check if it's left exists
            if(curr->left){
                TreeNode* temp = curr->left;
                // Go to it's rightmost child
                while(temp->right) temp = temp->right;
                // Connect that child to the root's immediate right child 
                temp->right = curr->right;
                // move Curr->left to it's right
                curr->right = curr->left;
                curr->left = nullptr;
            }
            // Move curr to it's right coz left is sorted
            curr = curr->right;
        }
    }
};