class Solution {
private:
    void construct(vector<int> &candidates, vector<int> numbers, vector<vector<int>> &results, int target, int index) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            results.push_back(numbers);
        } else if (index >= candidates.size()) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            numbers.push_back(candidates[i]);
            construct(candidates, numbers, results, target - candidates[i], i);
            numbers.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> numbers;

        construct(candidates, numbers, results, target, 0);

        return results;
    }
};