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
    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &inorderIdx, int &index, int left, int right) {

        if (left > right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        index++;
        int nextIndex = inorderIdx[root -> val];
        root -> left = constructTree(preorder, inorder, inorderIdx, index, left, nextIndex - 1);
        root -> right = constructTree(preorder, inorder, inorderIdx, index, nextIndex + 1, right);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderIdx;

        int size = inorder.size();
        int startIndex = 0;

        for (int i = 0; i < inorder.size(); i++) {
            inorderIdx[inorder[i]] = i;
        }

        return constructTree(preorder, inorder, inorderIdx, startIndex, 0, size - 1);
    }
};