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
    void inOrder(vector<int> &node, TreeNode* root) {
        if (root == NULL) {
            return;
        }

        inOrder(node, root -> left);
        node.push_back(root -> val);
        inOrder(node, root -> right);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> node;
        inOrder(node, root);

        for (int i = 1; i < node.size(); i++) {
            if (node[i - 1] >= node[i]) {
                return false;
            }
        }

        return true;
    }
};