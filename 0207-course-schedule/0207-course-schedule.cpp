class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int dest = prerequisites[i][0];
            int source = prerequisites[i][1];

            adjList[source].push_back(dest);
            indegree[dest]++;
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] > 0) continue;
            q.push(i);
        }

        int total = 0;
        while (q.size() > 0) {
            int node = q.front();
            q.pop();
            total++;

            for (auto nei : adjList[node]) {
                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return total == numCourses;
    }
};