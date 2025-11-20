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
    int answer;

    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftResult = dfs(root -> left);
        int rightResult = dfs(root -> right);

        int result = (root -> val - 1) + leftResult + rightResult;
        answer += abs(result);
        return result;
    }
public:
    int distributeCoins(TreeNode* root) {
        answer = 0;
        dfs(root);

        return answer;
    }
};