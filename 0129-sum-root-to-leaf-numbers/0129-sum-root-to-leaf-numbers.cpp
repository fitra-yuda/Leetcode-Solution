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
    void calculate(TreeNode* root, int currentNumber, int &answer) {
        if (root == NULL) {
            return;           
        }

        currentNumber *= 10;
        currentNumber += root -> val;

        if (root -> left == NULL && root -> right == NULL) {
            answer += currentNumber;
            return;
        }

        calculate(root -> left, currentNumber, answer);
        calculate(root -> right, currentNumber, answer);
        
        return;
    }
public:
    int sumNumbers(TreeNode* root) {
        int answer = 0;
        calculate(root, 0, answer);

        return answer;
    }
};