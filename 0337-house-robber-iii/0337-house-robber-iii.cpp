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
    // first = take, second = skip
    pair<int,int> dfs(TreeNode* root) {
        if (root == NULL) {
            return {0,0};
        }

        pair<int,int> leftResult = dfs(root -> left);
        pair<int,int> rightResult = dfs(root -> right);

        int take = root -> val + leftResult.second + rightResult.second;
        int skip = leftResult.first + rightResult.first;

        return {max(take, skip), skip};
    }
public:
    int rob(TreeNode* root) {
        pair<int,int> result = dfs(root); 

        return max(result.first, result.second);
    }
};