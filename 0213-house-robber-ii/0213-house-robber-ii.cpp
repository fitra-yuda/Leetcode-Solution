class Solution {
public:
    int helper(vector<int> &nums, int start, int end) {

        int first = 0;
        int second = 0;

        while (start < end) {
            int newResult = max(nums[start] + second, first);
            second = first;
            first = newResult;
            start++;
        }

        return max(first, second);
    }

    int rob(vector<int>& nums) {
        int result = nums[0];        
        int size = nums.size();

        return max({result, helper(nums, 0, size - 1), helper(nums, 1, size)});
    }
};