class Solution {
private:
    int calculate(vector<int> &nums, int index, int currentResult) {

        if (index >= nums.size()) {
            return 0;
        }

        int sum = 0;
        while (index < nums.size()) {
            sum += currentResult ^ nums[index];
            int result = calculate(nums, index + 1, currentResult ^ nums[index]);
            sum += result;
            index++;
        }

        return sum;
    }
public:
    int subsetXORSum(vector<int>& nums) {
       return calculate(nums, 0, 0); 
    }
};