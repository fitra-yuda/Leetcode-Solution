class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int> bucket;

        for (auto num : nums) {
            bucket[num]++;
        }

        int result = 0;
        int count = 0;

        for (auto [key, value] : bucket) {
            if (value > count) {
                result = key;
                count = value;
            }
        }

        return result;
    }
};