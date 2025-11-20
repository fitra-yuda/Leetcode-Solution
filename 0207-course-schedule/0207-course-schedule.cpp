class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> results;
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> adjList(numCourses);
        queue<int> q;

        for (int i = 0; i < prerequisites.size(); i++) {
            int source = prerequisites[i][0];
            int dest = prerequisites[i][1];
            inDegree[dest]++;

            adjList[source].push_back(dest);
        }

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

        return results.size() == numCourses;
    }
};