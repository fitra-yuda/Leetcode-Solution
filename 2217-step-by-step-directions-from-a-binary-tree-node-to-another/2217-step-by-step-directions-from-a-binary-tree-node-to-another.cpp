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
    bool dfs(TreeNode* root, int target, string &path) {
        if (root == NULL) {
            return false;
        } else if (root -> val == target) {
            return true;
        }

        path.push_back('L');
        if(dfs(root -> left, target, path)) {
            return true;
        }

        path.pop_back();
        path.push_back('R');
        if(dfs(root -> right, target, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        dfs(root, startValue, startPath);
        
        string destPath = "";
        dfs(root, destValue, destPath);

        string result = "";
        int i = 0;
        int j = 0;
        
        while (i < startPath.size() && j < destPath.size()) {
            if (startPath[i] != destPath[j]) {
                break;
            }
            i++;
            j++;
        }

        while (i < startPath.size()) {
            result += 'U';
            i++;
        }

        while (j < destPath.size()) {
            result += destPath[j];
            j++;
        }

        return result;
    }
};