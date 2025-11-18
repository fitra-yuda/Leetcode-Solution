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
class BSTIterator {
private:    
    vector<int> nodes;
    int index;

    void extract(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        extract(root -> left);
        nodes.push_back(root -> val);
        extract(root -> right);
    }
public:
    BSTIterator(TreeNode* root) {
        index = 0;
        extract(root);
    }
    
    int next() {
        int result = nodes[index];
        index++;

        return result;
    }
    
    bool hasNext() {
        return index < nodes.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */