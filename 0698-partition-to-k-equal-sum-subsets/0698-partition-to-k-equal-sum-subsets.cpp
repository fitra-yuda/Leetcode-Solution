class Solution {
private:
    bool check(vector<int> &nums, vector<int> &bucket, int index, int sum) {
        if (index >= nums.size()) {
            return true;
        }

        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] + nums[index] <= sum) {
                bucket[i] += nums[index];
                bool result = check(nums, bucket, index + 1, sum);

                if (result) {
                    return true;
                }

                bucket[i] -= nums[index];
            }

            if (bucket[i] == 0) {
                break;
            }
        }
        
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for (auto number : nums) {
            sum += number;
        }

        if (sum % k != 0) {
            return false;
        }

        sum /= k;
        sort(nums.rbegin(), nums.rend());
        
        vector<int> bucket(k, 0);

        return check(nums, bucket, 0, sum);
    }
};