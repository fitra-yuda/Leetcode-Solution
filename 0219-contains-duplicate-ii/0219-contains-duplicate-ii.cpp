class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> bucket;

        int left = 0;
        int right = 0;
        bool result = false;

        while (right < nums.size()) {
            bucket[nums[right]]++;

            if (right - left > k) {
                bucket[nums[left]]--;

                if (bucket[nums[left]] == 0) {
                    bucket.erase(nums[left]);
                }

                left++;
            }

            if (bucket[nums[right]] > 1) {
                result = true;
                break;
            }

            right++;
        }

        return result;
    }
};