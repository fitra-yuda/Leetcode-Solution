class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> bucket;

        for (int i = 0; i < size; i++) {
            int reminder = target - nums[i];

            if (bucket.count(reminder) > 0) {
                return {bucket[reminder], i};
            }

            bucket[nums[i]] = i;
        }

        return {-1,-1};
    }
};