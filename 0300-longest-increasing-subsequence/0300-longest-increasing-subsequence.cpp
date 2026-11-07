class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 1;

        vector<int> bucket;
        bucket.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            if (bucket[bucket.size() - 1] < nums[i]) {
                bucket.push_back(nums[i]);
                result++;
            } else {
                int findIndex = lower_bound(bucket.begin(), bucket.end(), nums[i]) - bucket.begin();
                bucket[findIndex] = nums[i];
            }
        }
        
        return result;
    }
};