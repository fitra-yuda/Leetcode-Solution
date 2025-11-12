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
            int currentResult = result;
            bool check = false;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                if (currentNode -> left) {
                    if (check == false) {
                        currentResult = currentNode -> left -> val;
                        check = true;
                    }

                    q.push(currentNode -> left);
                }

                if (currentNode -> right) {
                    if (check == false) {
                        currentResult = currentNode -> right -> val;
                        check = true;
                    }

                    q.push(currentNode -> right);
                }
            }

            result = currentResult;
        }

        return result;
    }
};