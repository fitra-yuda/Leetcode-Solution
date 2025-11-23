class Solution {
private:
    void construct(vector<int> &nums, vector<vector<int>> &results, vector<int> &result, int index) {
        if (index >= nums.size()) {
            results.push_back(result);
            return;
        }

        // take
        result.push_back(nums[index]);
        construct(nums, results, result, index + 1);
        result.pop_back();

        // skip
        construct(nums, results, result, index + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;

        construct(nums, results, result, 0);

        return results;
    }
};