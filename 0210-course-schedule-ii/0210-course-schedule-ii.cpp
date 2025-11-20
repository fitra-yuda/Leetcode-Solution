class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> results;
        vector<vector<int>> adjList(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int dest = prerequisites[i][0];
            int source = prerequisites[i][1];

            adjList[source].push_back(dest);
            inDegree[dest]++;
        }

        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (q.size() > 0) {
            int node = q.front();
            q.pop();
            results.push_back(node);

            for (auto nextNode : adjList[node]) {
                inDegree[nextNode]--;

                if (inDegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }

        if (results.size() != numCourses) {
            return {};
        }

        return results;
    }
};