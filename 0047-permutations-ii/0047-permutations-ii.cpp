class Solution {
private:
    void construct(vector<int> &nums, vector<vector<int>> &permutations, vector<int> &permutation, unordered_map<int,int> &count) {
        if (nums.size() == permutation.size()) {
            permutations.push_back(permutation);
            return;
        }

        for (auto& [key, value] : count) {
            if (value <= 0) continue;

            permutation.push_back(key);
            value--;
            construct(nums, permutations, permutation, count);
            value++;
            permutation.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> permutation;
        unordered_map<int,int> count;

        for (auto num : nums) {
            count[num]++;
        }

        construct(nums, permutations, permutation, count);

        return permutations;
    }
};