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
class Node {
public:
    TreeNode* curr;
    Node* parent;
    Node(TreeNode* curr, Node* parent) {
        this -> curr = curr;
        this -> parent = parent;
    }
};

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<Node*> q;
        q.push(new Node(root, NULL));

        vector<Node*> nodes;
        while (q.size() > 0) {
            int levelSize = q.size();

            vector<Node*> temp;
            for (int i = 0; i < levelSize; i++) {
               Node* node = q.front(); 
               temp.push_back(node);
               q.pop();

                if (node -> curr -> left) {
                    Node* leftNode = new Node(node -> curr -> left, node);
                    q.push(leftNode);
                }

                if (node -> curr -> right) {
                    Node* rightNode = new Node(node -> curr -> right, node);
                    q.push(rightNode);
                }
            }

            nodes = temp;
        }

        if (nodes.size() == 0) {
            return root;
        }

        // backtrack from leaf node
        queue<Node*> bucket;
        for(auto node : nodes) {
            bucket.push(node);
        }

        unordered_map<int, bool> visited;
        while (bucket.size() > 1) {
            Node* node = bucket.front(); 
            bucket.pop();

            if (node -> parent && visited.count(node -> parent -> curr -> val) == false) {
                visited[node -> parent -> curr -> val] = true;
                bucket.push(new Node(node -> parent -> curr, node -> parent -> parent));
            }
        }
        
        return bucket.front() -> curr;
    }
};