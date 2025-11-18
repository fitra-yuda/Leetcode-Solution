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
public:
    
    string dfs(TreeNode* root){
        if(root){
            
            char current = (root->val + 'a');
            string left = dfs(root->left);
            
            string right = dfs(root->right);
            
            // cout << current << " " << left << " " << right << endl;
            if(right == "" && left == ""){
                left = current;
                return left;
            }else if(right == "" && left != ""){
                return left + current;
            }else if(left == "" && right != ""){
                return right + current;
            }else if(left + current > right + current){
                return right + current;
            }else{
                return left + current;
            }
        }
        
        return "";
    }
    
    string smallestFromLeaf(TreeNode* root) {
        return dfs(root);
    }
};