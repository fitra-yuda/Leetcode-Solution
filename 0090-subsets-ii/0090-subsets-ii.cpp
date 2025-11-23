class Solution {
private:
    void construct(vector<int> &nums, vector<vector<int>> &subsets, vector<int> &subset, int index) {

        subsets.push_back(subset);
        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) {
                continue;
            }

            subset.push_back(nums[i]);
            construct(nums, subsets, subset, i + 1);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        sort(nums.begin(), nums.end());

        construct(nums, subsets, subset, 0);
        
        return subsets;
    }
};