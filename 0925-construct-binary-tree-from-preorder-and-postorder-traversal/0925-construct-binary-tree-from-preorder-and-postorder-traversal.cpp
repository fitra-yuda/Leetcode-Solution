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
    TreeNode* constructTree(vector<int>& preorder, vector<int> &postorder, unordered_map<int,int> &postorderIdx, int &index, int currentIndex) {

        if (index >= postorder.size()) {
            return NULL;
        }

        int nextChildIndex = postorderIdx[preorder[index]];

        if (nextChildIndex > currentIndex) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        root -> left = constructTree(preorder, postorder, postorderIdx, index, nextChildIndex);
        root -> right = constructTree(preorder, postorder, postorderIdx, index, nextChildIndex);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int,int> postorderIdx;
        int size = postorder.size();
        int index = 0;
        for (int i = 0; i < size; i++) {
            postorderIdx[postorder[i]] = i;
        }

        return constructTree(preorder, postorder, postorderIdx, index, size);
    }
};