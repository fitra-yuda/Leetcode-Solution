class Solution {
void dfs(vector<int> &permutation, vector<vector<int>> &results, unordered_map<int,int> &bucket, int n) {
    if (n == permutation.size()) {
        results.push_back(permutation);
    }

    for (auto &[key, value] : bucket) {
        if (value <= 0) {
            continue;
        }

        value--;
        permutation.push_back(key);

        dfs(permutation, results, bucket, n);

        value++;
        permutation.pop_back();
    }
}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> permutation;
        unordered_map<int,int> bucket;

        for (auto num : nums) {
            bucket[num]++;
        }

        dfs(permutation, results, bucket, nums.size());

        return results;
    }
};