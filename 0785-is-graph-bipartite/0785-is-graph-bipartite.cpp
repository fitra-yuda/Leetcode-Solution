class Solution {
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int color, int node, int parent) {
        colors[node] = color;
        int nextColor = (color + 1) % 2;
        for (auto nei : graph[node]) {
            if (nei == parent) {
                continue;
            }

            if (colors[nei] == nextColor) {
                continue;
            } else if (colors[nei] != -1 && colors[nei] != nextColor) {
                return false;
            }

            bool result = dfs(graph, colors, nextColor, nei, node);

            if (result == false) {
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colors(graph.size() + 1, -1);

        for (int i = 0; i < graph.size(); i++) {
            if (colors[i] != -1) {
                continue;
            }

            bool result = dfs(graph, colors, 1, i, -1);

            if (result == false) {
                return false;
            }
        }

        return true;
    }
};