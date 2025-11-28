class Solution {
public:
    int helper(vector<int> &nums) {
        int first = 0;
        int second = 0;

        for (int i = 0; i < nums.size(); i++) {
            int newResult = max(nums[i] + second, first);
            second = first;
            first = newResult;
        }

        return max(first, second);
    }

    int rob(vector<int>& nums) {
        vector<int> nums1(nums.begin() + 1, nums.end());
        vector<int> nums2(nums.begin(), nums.end() - 1);

        return max({nums[0], helper(nums1), helper(nums2)});
    }
};