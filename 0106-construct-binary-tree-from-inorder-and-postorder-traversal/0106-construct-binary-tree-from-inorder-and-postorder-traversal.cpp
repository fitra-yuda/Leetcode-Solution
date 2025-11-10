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
    int index;

    TreeNode* dfs(int left, int right, vector<int>& postorder, unordered_map<int,int> &inorderIndex) {
        if (left > right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[index]);
        index--;
        int nextIndex = inorderIndex[root -> val];
        root -> right = dfs(nextIndex + 1, right, postorder, inorderIndex); 
        root -> left = dfs(left, nextIndex - 1, postorder, inorderIndex);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderIndex;
        int size = inorder.size();
        index = size - 1;

        for (int i = 0; i < size; i++) {
            inorderIndex[inorder[i]] = i;
        }
    
        return dfs(0, size - 1, postorder, inorderIndex);
    }
};