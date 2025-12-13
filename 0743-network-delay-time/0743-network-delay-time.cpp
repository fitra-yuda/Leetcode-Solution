
struct Compare {
    bool operator()(pair<int,int> first, pair<int,int> second) {
        return first.second > second.second;
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n + 1);        
        vector<int> visited(n + 1, INT_MAX);

        for (auto time : times) {
            int source = time[0];
            int dest = time[1];
            int cost = time[2];

            adjList[source].push_back({dest, cost});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        pq.push({k, 0});

        int result = 0;

        while (pq.size() > 0) {
            auto [node, cost] = pq.top();
            visited[node] = min(visited[node], cost);
            pq.pop();

            for (auto data : adjList[node]) {
                int nextNode = data.first;
                int nextCost = data.second;

                if (visited[nextNode] != INT_MAX) {
                    continue;
                }

                pq.push({nextNode, nextCost + cost});
            }
        }

        for (int i = 1; i < visited.size(); i++) {
            if (visited[i] == INT_MAX) {
                return -1;
            }
            result = max(result, visited[i]);
        }

        return result;
    }
};