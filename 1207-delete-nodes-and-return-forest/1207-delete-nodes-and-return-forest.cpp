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
    TreeNode* postorder(TreeNode* root, unordered_map<int,int> &hashMap, vector<TreeNode*> &results) {
        if (root == NULL) {
            return root;
        }

        root -> left = postorder(root -> left, hashMap, results);
        root -> right = postorder(root -> right, hashMap, results);

        if (hashMap[root -> val] > 0) {
            if (root -> left) {
                results.push_back(root -> left);
            }

            if (root -> right) {
                results.push_back(root -> right);
            }

            root = NULL;
        }

        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> results;
        unordered_map<int,int> hashMap;

        for (auto number : to_delete) {
            hashMap[number]++;
        }

        root = postorder(root, hashMap, results);

        if (root != NULL) {
            results.push_back(root);
        }

        return results;
    }
};