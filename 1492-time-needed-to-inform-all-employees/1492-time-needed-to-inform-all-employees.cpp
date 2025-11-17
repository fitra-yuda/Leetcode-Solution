class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adjList(n);
        int totalTime = 0;

        for (int i = 0; i < manager.size(); i++) {
           if (manager[i] == -1) {
                continue;
           }

           int parent = manager[i]; 
           int child = i;

           adjList[parent].push_back(child);
        }

        queue<pair<int,int>> q;
        q.push({headID, 0});

        while(q.empty() == false) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                auto [node, currentTime] = q.front();
                q.pop();

                totalTime = max(totalTime, currentTime + informTime[node]);

                for (auto child : adjList[node]) {
                    q.push({child, currentTime + informTime[node]});
                }
            }
        }

        return totalTime;
    }
};