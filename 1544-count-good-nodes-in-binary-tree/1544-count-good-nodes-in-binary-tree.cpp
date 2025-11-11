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
    int count(TreeNode* root, int maxNumber) {
        if (root == NULL) {
            return 0;
        }

        int result = 0;
        if (root -> val >= maxNumber) {
            maxNumber = root -> val;
            result++;
        } 

        int leftResult = count(root -> left, maxNumber);
        int rightResult = count(root -> right, maxNumber);

        return result + leftResult + rightResult;
    }
public:
    int goodNodes(TreeNode* root) {
        return count(root, INT_MIN);
    }
};