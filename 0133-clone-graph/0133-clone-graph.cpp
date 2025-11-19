/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return nullptr;
        }

        unordered_map<Node*, Node*> bucket;
        queue<Node*> q;
        q.push(node);
        bucket[node] = new Node(node -> val);

        while(q.size() > 0) {
            Node* curr = q.front();
            q.pop();

            for (auto nei : curr -> neighbors) {
                if (bucket.find(nei) == bucket.end()) {
                    bucket[nei] = new Node(nei -> val);
                    q.push(nei);
                }

                bucket[curr] -> neighbors.push_back(bucket[nei]);
            }
        }

        return bucket[node];
    }
};