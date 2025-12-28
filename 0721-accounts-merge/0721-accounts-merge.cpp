class Solution {
private:

    string findParent(unordered_map<string,string> &disjoinSet, string node) {

        // the current node parent == node itself
        if (disjoinSet[node] == node) {
            return node;
        } 

        disjoinSet[node] = findParent(disjoinSet, disjoinSet[node]);
        return disjoinSet[node];
    }

    void join(unordered_map<string,string> &disjoinSet, string &first, string &second) {
        string parentFirst = findParent(disjoinSet, first);
        string parentSecond = findParent(disjoinSet, second);

        if (parentFirst != parentSecond) {
            // make first to become the parent of second node
            disjoinSet[parentSecond] = parentFirst;
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // key = email, value = username
        unordered_map<string, string> users;

        // key = email, value = all of the connected emails
        unordered_map<string, unordered_set<string>> adjList;

        unordered_set<string> emails; 

        // create disjoin set
        unordered_map<string,string> disjoinSet;

        for (int i = 0; i < accounts.size(); i++) {
            string accountName = "";
            for (int j = 0; j < accounts[i].size(); j++) {
                if (j == 0) {
                    accountName = accounts[i][j];
                } else {
                    users[accounts[i][j]] = accountName;
                    emails.insert(accounts[i][j]);

                    if (disjoinSet.count(accounts[i][j]) == 0) {
                        disjoinSet[accounts[i][j]] = accounts[i][j];
                    }

                    for (int k = j + 1; k < accounts[i].size(); k++) {
                        if (disjoinSet.count(accounts[i][k]) == 0) {
                            disjoinSet[accounts[i][k]] = accounts[i][k];
                        }
                        join(disjoinSet, accounts[i][j], accounts[i][k]);
                    }
                }
            }
        }


        // key = parent of the subset, value = child of the subset
        unordered_map<string, vector<string>> bucket;

        for (auto email : emails) {
            string parent = findParent(disjoinSet, email);
            bucket[parent].push_back(email);
        }

        vector<vector<string>> results;

        for (auto [parent, childs] : bucket) {
            vector<string> result;

            for (auto child : childs) {
                result.push_back(child);
            }

            sort(result.rbegin(), result.rend());

            result.push_back(users[parent]);
            reverse(result.begin(), result.end());

            results.push_back(result);
        }

        return results;
    }
};