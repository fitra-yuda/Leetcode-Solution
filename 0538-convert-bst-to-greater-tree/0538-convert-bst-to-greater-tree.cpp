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
    int calculate(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftResult = calculate(root -> left);
        int rightResult = calculate(root -> right);

        return leftResult + rightResult + root -> val;
    }

    void inorder(TreeNode* root, int &sum) {
        if (root == NULL) {
            return;
        }

        inorder(root -> left, sum);
        int prevRootValue = root -> val;
        root -> val = sum;
        sum -= prevRootValue;
        inorder(root -> right, sum);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        int sum = calculate(root);
        inorder(root, sum);

        return root;
    }
};