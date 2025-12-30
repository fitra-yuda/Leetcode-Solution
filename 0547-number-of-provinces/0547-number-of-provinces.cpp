class DisjoinSet {
private:
    vector<int> arr;
    vector<int> ranks;
public:
    DisjoinSet(int n) {
        for (int i = 0; i <= n; i++) {
            arr.push_back(i);
            ranks.push_back(i);
        }
    }

    int findParent(int node) {
        if (arr[node] == node) {
            return node;
        }

        arr[node] = findParent(arr[node]);
        return arr[node];
    }

    void join(int first, int second) {
        int firstParent = findParent(first);
        int secondParent = findParent(second);

        if (firstParent != secondParent) {
            if (ranks[firstParent] >= ranks[secondParent]) {
                // mark first parent as parent of second node
                arr[secondParent] = firstParent;

                // update first parent ranks 
                ranks[firstParent] += ranks[secondParent]; 
            } else {
                // mark second parent as parent of the first node
                arr[firstParent] = secondParent;
                
                // update second parent ranks;
                ranks[secondParent] += ranks[firstParent];
            }
        }
    }

    int getDiffParent() {
        int result = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == i) {
                result++;
            }
        }

        return result;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int totalNode = isConnected.size();        

        DisjoinSet disjoinSet(totalNode);

        for (int i = 0; i < totalNode; i++) {
            for (int j = 0; j < totalNode; j++) {
                if (i == j) {
                    continue;
                }

                if (isConnected[i][j] == 1) {
                    disjoinSet.join(i + 1, j + 1);
                }
            }
        }

        return disjoinSet.getDiffParent();
    }
};