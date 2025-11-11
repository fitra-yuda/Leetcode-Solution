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
    void inOrder(TreeNode* root, int &k, int &answer) {
        if (root == NULL) {
            return;
        } else if (k < 0) {
            return;
        }

        inOrder(root -> left, k, answer);
        k--;
        
        if (k == 0) {
            k--;
            answer = root -> val;
            return;
        }

        inOrder(root -> right, k, answer);

        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int answer = -1;

        inOrder(root, k, answer);

        return answer;
    }
};