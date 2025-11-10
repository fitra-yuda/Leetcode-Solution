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
    bool isCompleteTree(TreeNode* root) {
        bool check = false;
        bool result = true;
        queue<TreeNode*> q;

        q.push(root);

        while(q.size() > 0) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr -> left) {
                    if (check) {
                        result = false;
                    }
                    q.push(curr -> left);
                } else {
                    check = true;
                }

                if (curr -> right) {
                    if (check) {
                        result = false;
                    }
                    q.push(curr -> right);
                } else {
                    check = true;
                }
            }
        }

        return result;
    }
};