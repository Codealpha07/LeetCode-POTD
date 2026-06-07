class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> m;
        unordered_set<int> root, child;

        for (auto &d : descriptions) {
            int p = d[0], c = d[1], isLeft = d[2];
            if (m[p] == nullptr) m[p] = new TreeNode(p);
            if (m[c] == nullptr) m[c] = new TreeNode(c);

            if (isLeft) m[p]->left = m[c];
            else m[p]->right = m[c];
            child.insert(c);

            // only parents that are not children can be roots
            if (!child.count(p)) root.insert(p);
            root.erase(c);
        }
        int rootVal = *root.begin();
        return m[rootVal];
    }
};