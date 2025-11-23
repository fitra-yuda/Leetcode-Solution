class Solution {
private:
    void construct(vector<int> &candidates, vector<int> &combinations, vector<vector<int>> &results, int target, int index) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            results.push_back(combinations);
            return;
        } else if (index >= candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            combinations.push_back(candidates[i]);
            construct(candidates, combinations, results, target - candidates[i], i + 1);
            combinations.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> combinations;

        sort(candidates.begin(), candidates.end());
        construct(candidates, combinations, results, target, 0);

        return results;
    }
};