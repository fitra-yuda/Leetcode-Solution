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
    void dfs(TreeNode* root, vector<long long> &depthSum, int depth) {
        if (root == NULL) {
            return;
        }

        if (depthSum.size() < depth) {
            depthSum.push_back(root -> val);
        } else {
            depthSum[depth - 1] += root -> val;
        }

        dfs(root -> left, depthSum, depth + 1);
        dfs(root -> right, depthSum, depth + 1);
    }
public:
    int maxLevelSum(TreeNode* root) {
        vector<long long> depthSum;

        dfs(root, depthSum, 1);

        int result = 0;
        int total = INT_MIN;
        for (int i = 0; i < depthSum.size(); i++) {
            if (total < depthSum[i]) {
                result = i + 1;
                total = depthSum[i];
            }
        }

        return result;
    }
};