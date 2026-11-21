class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int sum = INT_MAX;
        int currentSum = 0;
        
        int left = 0;
        int right = 0;

        int leftResult = 0;
        int rightResult = 0;

        while (right < arr.size()) {
            currentSum += abs(arr[right] - x);

            if (right - left + 1 == k) {
                
                if (sum > currentSum) {
                    leftResult = left;
                    rightResult = right;
                    sum = currentSum;
                }

                currentSum -= abs(arr[left] - x);
                left++;
            }

            right++;
        }

        vector<int> result;

        while (leftResult <= rightResult) {
            result.push_back(arr[leftResult]);
            leftResult++;
        }

        return result;
    }
};