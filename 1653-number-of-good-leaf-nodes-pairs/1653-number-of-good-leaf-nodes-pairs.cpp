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
    vector<int> dfs(TreeNode* root, int distance, int &answer) {
        if (root == NULL) {
            return {};
        } else if (root -> left == NULL && root -> right == NULL) {
            return {1};
        }

        vector<int> left = dfs(root -> left, distance, answer);
        vector<int> right = dfs(root -> right, distance, answer);

        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                if (left[i] + right[j] <= distance) {
                    answer++;
                }
            }
        }

        vector<int> results;
        for (auto data : left) results.push_back(data + 1);
        for (auto data : right) results.push_back(data + 1);

        return results;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int answer = 0;
        dfs(root, distance, answer);

        return answer;
    }
};