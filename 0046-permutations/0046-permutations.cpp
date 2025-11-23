class Solution {
private:
    vector<vector<int>> construct(vector<int> &nums, int index) {
        if (index >= nums.size() - 1) {
            return {{nums[index]}};
        } 

        vector<vector<int>> results;
        vector<vector<int>> nextResults = construct(nums, index + 1);

        for (auto nextResult : nextResults) {
            for (int i = 0; i <= nextResult.size(); i++) {
                vector<int> result = nextResult;
                result.insert(result.begin() + i, nums[index]);
                results.push_back(result);
            }
        }

        return results;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results = construct(nums, 0);

        return results;
    }
};