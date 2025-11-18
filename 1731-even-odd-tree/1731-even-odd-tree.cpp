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
    bool dfs(TreeNode* root, int depth, unordered_map<int,int> &hashMap) {
        if (root == NULL) {
            return true;
        }

        if (depth % 2 == 0) {
            if (root -> val % 2 == 0) {
                return false;
            }

            if (hashMap.count(depth) == 0) {
                hashMap[depth] = root -> val;
            } else if (hashMap[depth] >= root -> val) {
                return false;
            } else {
                hashMap[depth] = root -> val;
            }
        } else {
            if (root -> val % 2 == 1) {
                return false;
            }

            if (hashMap.count(depth) == 0) {
                hashMap[depth] = root -> val;
            } else if (hashMap[depth] <= root -> val) {
                return false;
            } else {
                hashMap[depth] = root -> val;
            }
        }

        bool leftResult = dfs(root -> left, depth + 1, hashMap);
        bool rightResult = dfs(root -> right, depth + 1, hashMap);

        return leftResult && rightResult;
    }
public:
    bool isEvenOddTree(TreeNode* root) {
        unordered_map<int,int> hashMap;
        return dfs(root, 0, hashMap);
    }
};