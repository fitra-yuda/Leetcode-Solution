class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> bucket;
        int result = -1;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            bucket[nums[i]]++;

            if (bucket[result] < bucket[nums[i]]) {
                result = nums[i];
            }
        }

        return result;
    }
};