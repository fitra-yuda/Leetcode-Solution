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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == NULL) {
            return NULL;
        }

        root -> left = trimBST(root -> left, low, high);
        root -> right = trimBST(root -> right, low, high);

        if (root -> val < low) {
            if (root -> right == NULL) {
                return NULL;
            }

            return root -> right;
        } else if (root -> val > high) {
            if (root -> left == NULL) {
                return NULL;
            } 

            return root -> left;
        }

        return root;
    }
};