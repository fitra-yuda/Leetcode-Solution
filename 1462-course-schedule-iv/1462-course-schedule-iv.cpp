class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses + 1, 0);
        vector<vector<int>> adjList(numCourses + 1);

        for (auto data : prerequisites) {
            int source = data[0];
            int dest = data[1];
            indegree[dest]++;
            adjList[source].push_back(dest);
        }

        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        unordered_map<int,unordered_map<int,int>> bucket;

        while (q.size() > 0) {
            int node = q.front();
            q.pop();

            for (auto nei : adjList[node]) {
                indegree[nei]--;

                bucket[nei][node] = 1;
                for (auto [preq, value] : bucket[node]) {
                    bucket[nei][preq] = 1;
                }

                if (indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        vector<bool> results;
        for (auto query : queries) {
            int preq = query[0];
            int node = query[1];

            if (bucket[node].count(preq) > 0) {
                results.push_back(true);
            } else {
                results.push_back(false);
            }
        }

        return results;
    }
};