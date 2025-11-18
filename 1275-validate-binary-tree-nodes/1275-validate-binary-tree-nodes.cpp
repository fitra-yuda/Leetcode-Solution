class Solution {
private:
    int findRoot(int n, vector<int>& leftChild, vector<int> &rightChild) {
        
        unordered_set<int> bucket;
        bucket.insert(leftChild.begin(), leftChild.end());
        bucket.insert(rightChild.begin(), rightChild.end());

        for (int i = 0; i < n; i++) {
            if (bucket.find(i) == bucket.end()) {
                return i;
            }
        }

        return -1;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);

        if (root == -1) {
            return false;
        }

        queue<int> q;
        unordered_set<int> visited;
        q.push(root);
        visited.insert(root);

        while (q.size() > 0) {
            int node = q.front();
            q.pop();

            vector<int> childs = {leftChild[node], rightChild[node]};

            for (auto child : childs) {
                if (child == -1) continue;

                if (visited.find(child) != visited.end()) {
                    return false;
                }
                q.push(child);
                visited.insert(child);
            }
        }

        return visited.size() == n;
    }
};