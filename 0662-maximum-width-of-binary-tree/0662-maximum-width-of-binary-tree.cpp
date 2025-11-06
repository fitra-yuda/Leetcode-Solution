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
    int widthOfBinaryTree(TreeNode* root) {
        int result = 1;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (q.empty() == false) {
            int level_size = q.size();
            int start = q.front().second;
            int end = q.back().second;

            result = max(result, end - start + 1);

            for (int i = 0; i < level_size; i++) {
                auto [current_node, number] = q.front();
                q.pop();

                int next_number = number - start;

                if (current_node -> left) {
                    q.push({current_node -> left, next_number * 2LL + 1});
                }

                if (current_node -> right) {
                    q.push({current_node -> right, next_number * 2LL + 2});
                }
            }
        }

        return result;
    }
};