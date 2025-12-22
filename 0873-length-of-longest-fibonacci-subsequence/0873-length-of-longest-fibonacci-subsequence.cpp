
/*

Basecase :
- if index == arr.size(), then return 0

DP State : 
- DP[i] = longest subsequence that is fibonnaci at i-th index

DP Transition :
- Can pick the current number or skip the current number
- If we pick the current number, we need to find next number (current number + prev number)
- Skip the current number, Increase the index by 1

- DP[i] = max(dp[nextIndex], dp[i + 1]) + 1

*/

class Solution {
private:

    int findNumber(int index, vector<int> &arr, int find) {
        // binary search to find the number

        int left = index;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == find) {
                return mid;
            } else if (arr[mid] > find) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }

    int dfs(int index, vector<int> &arr, vector<int> &dp) {
        if (index == arr.size()) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int result = 1;
        for (int i = index + 1; i < arr.size(); i++) {
            int nextIndex = findNumber(i, arr, arr[index] + arr[i]);

            if (nextIndex != -1) {
                result = max(result, dfs(i, arr, dp) + 1);
            }
        }

        dp[index] = result;
        return dp[index];
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int result = 1;
        vector<int> dp(arr.size(), -1);

        for (int i = 0; i < arr.size(); i++) {
            result = max(result, dfs(i, arr, dp) + 1);
        }

        return result;
    }
};