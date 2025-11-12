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
    vector<TreeNode*> generate(int left, int right) {
        if (left > right) {
            return {nullptr};
        }

        vector<TreeNode*> results;
        for (int i = left; i <= right; i++) {
            vector<TreeNode*> leftResult = generate(left, i - 1);
            vector<TreeNode*> rightResult = generate(i + 1, right);

            for (auto childLeft : leftResult) {
                for (auto childRight : rightResult) {
                    results.push_back(new TreeNode(i, childLeft, childRight));
                }
            }
        }

        return results;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        return generate(1, n);
    }
};