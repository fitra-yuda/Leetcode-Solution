class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> results;

        for (int i = 0; i < n; i++) {
            results.push_back(nums[i]);
            results.push_back(nums[i + n]);
        }

        return results;
    }
};