class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> bucket;
        int result = -1;
        int count = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2]) {
                return nums[i];
            }
        }

        return nums[nums.size() - 1];
    }
};