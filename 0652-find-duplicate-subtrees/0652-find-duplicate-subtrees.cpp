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
    unordered_map<string,int> hashMap;

    string dfs(TreeNode* root, vector<TreeNode*> &results) {
        if (root == NULL) {
            return "N";
        }
        
        string result = "";
        result += dfs(root -> left, results);
        result += ',';
        result += dfs(root -> right, results);
        result += ',';
        result += root -> val;

        hashMap[result]++;

        if (hashMap[result] == 2) {
            results.push_back(root);
        }

        return result;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> results;
        dfs(root, results);
        return results;
    }
};