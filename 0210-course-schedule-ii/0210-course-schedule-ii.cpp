class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int source = prerequisites[i][1];
            int dest = prerequisites[i][0];

            adjList[source].push_back(dest);
            indegree[dest]++;
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> results;
        while (q.size() > 0) {
            int node = q.front();
            q.pop();
            results.push_back(node);

            for (auto nei : adjList[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if (results.size() == numCourses) {
            return results;
        }

        return {};
    }
};