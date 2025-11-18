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
    int dfs(TreeNode* root, unordered_map<int,int> bucket) {
        bucket[root -> val]++;

        if (root -> left == NULL && root -> right == NULL) {
            int totalNode = 0;
            int totalEven = 0;
            int totalOdd = 0;

            for (auto [key, value] : bucket) {
                totalNode += value;
                if (value % 2 == 0) {
                    totalEven++;
                } else {
                    totalOdd++;
                }
            }

            if (totalNode % 2 == 0 && totalOdd == 0) {
                return 1;
            } else if (totalNode % 2 == 1 && totalOdd == 1) {
                return 1;
            } else {
                return 0;
            }

        }

        int result = 0;

        if (root -> left) {
            result += dfs(root -> left, bucket);
        }

        if (root -> right) {
            result += dfs(root -> right, bucket);
        }

        return result;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> bucket;
        return dfs(root, bucket);
    }
};