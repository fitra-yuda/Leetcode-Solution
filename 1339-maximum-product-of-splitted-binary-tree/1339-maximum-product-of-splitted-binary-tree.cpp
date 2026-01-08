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

    long long sum(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }

        long long leftResult = sum(root -> left);
        long long rightResult = sum(root -> right);

        return root -> val + leftResult + rightResult;
    }

    long long calculate(long long a, long long b) {
        return a * b;
    }

    long long max(long long a, long long b) {
        if (a > b) return a;
        else return b;
    }

    long long dfs(TreeNode* root, int sum, long long &result) {

        // is leaf
        if (root -> left == NULL && root -> right == NULL) {
            return root -> val;
        }

        long long leftResult = 0;
        if (root -> left) {
            leftResult = dfs(root -> left, sum, result);
        }

        long long rightResult =  0;
        if (root -> right) {
            rightResult = dfs(root -> right, sum, result); 
        }

        long long left = calculate((sum - leftResult), leftResult);
        long long right = calculate((sum - rightResult), rightResult);

        result = max(result, max(left, right));

        return root -> val + leftResult + rightResult;
    }
public:
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        int total = sum(root);
        long long result = 0;

        dfs(root, total, result);

        return result % MOD;
    }
};