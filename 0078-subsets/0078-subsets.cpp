class Solution {
private:
    void dfs(vector<int> &nums, vector<int> &result, vector<vector<int>> &results, int index) {

        results.push_back(result);
        for (int i = index; i < nums.size(); i++) {
            result.push_back(nums[i]);
            dfs(nums, result, results, i + 1);
            result.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> results;
        dfs(nums, result, results, 0);

        return results;
    }
};