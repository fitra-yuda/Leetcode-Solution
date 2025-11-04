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

    void extractLeaf(TreeNode* root, vector<int> &results) {
        if (root == NULL) {
            return;
        }

        extractLeaf(root -> left, results);
        extractLeaf(root -> right, results);

        if (root -> left == NULL && root -> right == NULL) {
            results.push_back(root -> val);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> root1Result;
        vector<int> root2Result;

        extractLeaf(root1, root1Result);
        extractLeaf(root2, root2Result);

        if (root1Result.size() != root2Result.size()) {
            return false;
        }

        for (int i = 0; i < root1Result.size(); i++) {
            if (root1Result[i] != root2Result[i]) {
                return false;
            }
        }

        return true;
    }
};