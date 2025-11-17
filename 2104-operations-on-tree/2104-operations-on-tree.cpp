class LockingTree {
private:
    vector<vector<int>> adjList;
    vector<int> parent;
    unordered_map<int,int> bucket;
public:
    LockingTree(vector<int>& parent) {
        this -> parent = parent;
        adjList.assign(parent.size() , {});

        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == -1) continue;

            adjList[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (bucket.count(num) == 0 || bucket[num] == -1) {
            bucket[num] = user;
            return true;
        }

        return false;
    }
    
    bool unlock(int num, int user) {
        if (bucket.count(num) > 0 && bucket[num] == user) {
            bucket[num] = -1;
            return true;
        }

        return false;
    }

    bool checkAncestor(int child) {
        int parentNode = parent[child];
        if (parentNode == -1) {
            return true;
        } else if (bucket.count(parentNode) > 0 && bucket[parentNode] != -1) {
            return false;
        }

        return checkAncestor(parentNode);
    }

    bool checkDescendant(int currentNode) {
        bool result = false;
        queue<int> q;
        q.push(currentNode);
        
        while(q.size() > 0) {
            int node = q.front();
            q.pop();

            if (bucket.count(node) > 0 && bucket[node] != -1) {
                result = true;
                break;
            }

            for (auto child : adjList[node]) {
                q.push(child);
            }
        }
        return result;
    }

    void unlockChild(int currentNode) {
        queue<int> q;
        q.push(currentNode);

        while (q.size() > 0) {
            int node = q.front();
            q.pop();

            bucket[node] = -1;
            for (auto child : adjList[node]) {
                q.push(child);
            }
        }
    }
    
    bool upgrade(int num, int user) {
        bool ancestorResult = checkAncestor(num);
        bool descendantResult = checkDescendant(num);
        bool checkUnlock = false;

        if (bucket.count(num) == 0 || bucket[num] == -1) {
            checkUnlock = true;
        }


        if (ancestorResult && descendantResult && checkUnlock) {
            unlockChild(num);
            lock(num, user);
            return true;
        }

        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */