class Solution {
private:
    void construct(vector<int> &nums, vector<vector<int>> &permutations, int index) {
        if (index >= nums.size()) {
            permutations.push_back(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            construct(nums, permutations, index + 1);
            swap(nums[i], nums[index]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        construct(nums, permutations, 0);

        return permutations;
    }
};