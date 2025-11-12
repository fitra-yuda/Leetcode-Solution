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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        int result = root -> val;
        q.push(root);

        while (q.size() > 0) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                result = currentNode -> val;

                if (currentNode -> right) {
                    q.push(currentNode -> right);
                }

                if (currentNode -> left) {
                    q.push(currentNode -> left);
                }

            }
        }

        return result;
    }
};