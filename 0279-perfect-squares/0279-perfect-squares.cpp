class Solution {
private:
    int dfs(vector<int> &arr, vector<int> &dp, int n) {
        if (n == 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        int result = INT_MAX;
        for (int i = 0; i < arr.size(); i++) {
            if (n - arr[i] >= 0) {
                result = min(result, dfs(arr, dp, n - arr[i]) + 1);
            }
        }

        return dp[n] = result;
    }
public:
    int numSquares(int n) {
        vector<int> arr;

        for (int i = 1; i * i <= n; i++) {
            arr.push_back(i * i);
        }

        reverse(arr.begin(), arr.end());

        vector<int> dp(n + 1, -1);

        return dfs(arr, dp, n);
    }
};