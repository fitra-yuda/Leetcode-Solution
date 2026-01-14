class Solution {
private:
    void dfs(vector<int> &nums, vector<int> &result, vector<vector<int>> &results) {
        if (result.size() == nums.size()) {
            results.push_back(result);
            return;
        }

        for (auto num : nums) {
            if (find(result.begin(), result.end(), num) == result.end()) {
                result.push_back(num);
                dfs(nums, result, results);
                result.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;
        dfs(nums, result, results);

        return results;
    }
};