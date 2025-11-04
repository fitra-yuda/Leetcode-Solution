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

/*

# Observation
1. value 2 -> represent boolean OR
2. value 3 -> represent boolean AND
3. leaf always have value either 0 or 1

*/

class Solution {
private:
    bool isLeaf(TreeNode* root) {
        return root -> left == NULL && root -> right == NULL;
    }
public:
    bool evaluateTree(TreeNode* root) {
        if (isLeaf(root)) {
            return root -> val;
        }

        bool leftResult = evaluateTree(root -> left);
        bool rightResult = evaluateTree(root -> right);

        if (root -> val == 2) {
            return leftResult || rightResult;
        } else {
            return leftResult && rightResult;
        }
    }
};