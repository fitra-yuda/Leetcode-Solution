class Solution {
private:
    bool dfs(vector<vector<int>> &adjList, vector<bool> &visited, int node, int parent) {
        
        visited[node] = true;
        for (auto nextNode : adjList[node]) {
            if (parent == nextNode) {
                continue;
            }

            if (visited[nextNode]) {
                return true;
            }

            dfs(adjList, visited, nextNode, node);
        }

        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adjList(edges.size() + 1);
    
        for (auto edge : edges) {
            int source = edge[0];
            int dest = edge[1];

            adjList[source].push_back(dest);
            adjList[dest].push_back(source);
            vector<bool> visited(edges.size() + 1, false);

            if (dfs(adjList, visited, source, -1)) {
                return {source, dest};
            }
        }
        
        return {-1, -1};
    }
};