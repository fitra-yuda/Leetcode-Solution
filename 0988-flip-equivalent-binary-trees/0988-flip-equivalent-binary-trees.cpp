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
    void swap(TreeNode* root) {
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
    }
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        } else if (root1 == NULL && root2 != NULL) {
            return false;
        } else if (root1 != NULL && root2 == NULL) {
            return false;
        }

        if (root1 -> val != root2 -> val) {
            return false;
        }

        if (root1 -> left == NULL && root2 -> left != NULL) {
            swap(root2);
        } else if (root1 -> left != NULL && root2 -> left == NULL) {
            swap(root2);
        } else if (root1 -> left && root2 -> left && root1 -> left -> val != root2 -> left -> val) {
            swap(root2);
        }

        bool leftResult = flipEquiv(root1 -> left, root2 -> left);
        bool rightResult = flipEquiv(root1 -> right, root2 -> right);

        return leftResult && rightResult;
    }
};