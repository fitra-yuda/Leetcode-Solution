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
    long long max(long long a, long long b) {
        if (a > b) return a;
        else return b;
    }
public:
    vector<int> largestValues(TreeNode* root) {
        if (root == NULL) {
            return {};
        }
        
        vector<int> results;
        queue<TreeNode*> q;

        q.push(root);

        while(q.size() > 0) {
            int levelSize = q.size();
            long long maxValue = LLONG_MIN;

            for (int i = 0; i < levelSize; i++) {
                TreeNode* currentNode = q.front();
                q.pop();

                maxValue = max(maxValue, currentNode -> val);

                if (currentNode -> left) {
                    q.push(currentNode -> left);
                }

                if (currentNode -> right) {
                    q.push(currentNode -> right);
                }
            }

            results.push_back(maxValue);
        }

        return results;
    }
};