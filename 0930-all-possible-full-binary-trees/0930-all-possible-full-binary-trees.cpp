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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) {
            return {};
        }

        if (n == 1) {
            return {new TreeNode(0)};
        }

        vector<TreeNode*> results;
        for (int left = 1; left < n; left += 2) {
            vector<TreeNode*> leftResult = allPossibleFBT(left);
            vector<TreeNode*> rightResult = allPossibleFBT(n - 1 - left);

            for (auto left : leftResult) {
                for (auto right : rightResult) {
                    results.push_back(new TreeNode(0, left, right));
                }
            }
        }

        return results;
    }
};