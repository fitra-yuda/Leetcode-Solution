class Solution {
private:
    void construct(int n, int k, vector<int> &combination, vector<vector<int>> &combinations, int number) {
        if (k == 0) {
            combinations.push_back(combination);
            return;
        }

        for (int i = number; i <= n; i++) {
            combination.push_back(i);
            construct(n, k - 1, combination, combinations, i + 1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinations;
        vector<int> combination;

        construct(n, k, combination, combinations, 1);

        return combinations;
    }
};