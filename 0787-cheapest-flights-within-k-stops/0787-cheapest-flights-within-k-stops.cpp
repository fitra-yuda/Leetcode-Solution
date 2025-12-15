
class Node {
public:
    int nodeNumber;
    int cost;
    int stop;

    Node(int nodeNumber, int cost, int stop) {
        this -> nodeNumber = nodeNumber;
        this -> cost = cost;
        this -> stop = stop;
    }
};

struct Compare {
    bool operator()(Node &first, Node &second) {

        // swap if current cost > next cost
        return first.cost > second.cost;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        k++;

        vector<vector<pair<int,int>>> adjList(n);

        for (auto flight : flights) {
            int from = flight[0];
            int to = flight[1];
            int cost = flight[2];
            adjList[from].push_back({to, cost});
        }

        priority_queue<Node, vector<Node>, Compare> pq;
        vector<vector<bool>> visited(n, vector<bool>(k + 1, false));

        pq.push(Node(src,0,0));

        while (pq.size() > 0) {
            auto [nodeNumber, cost, stop] = pq.top();
            pq.pop();

            if (visited[nodeNumber][stop]) {
                continue;
            }

            visited[nodeNumber][stop] = true;

            if (nodeNumber == dst) {
                return cost;
            }

            for (auto nei : adjList[nodeNumber]) {
                int nextDest = nei.first;
                int nextCost = nei.second + cost;

                if (stop + 1 > k) {
                    continue;
                }

                pq.push(Node(nextDest,nextCost, stop + 1));
            }
        }

        return -1;
    }
};