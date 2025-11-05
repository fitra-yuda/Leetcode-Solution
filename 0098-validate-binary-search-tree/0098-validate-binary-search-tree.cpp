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
private:
    bool dfs(TreeNode* root, long long minValue, long long maxValue) {
        if (root == NULL) {
            return true;
        }

        if (!(minValue < root -> val && root -> val < maxValue)) {
            return false;
        }

        bool leftResult = dfs(root -> left, minValue, root -> val);
        bool rightResult = dfs(root -> right, root -> val, maxValue);

        return leftResult && rightResult;
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};