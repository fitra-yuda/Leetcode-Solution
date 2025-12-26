class Solution {
public:
    int numSquares(int n) {
        vector<int> arr;

        for (int i = 1; i * i <= n; i++) {
            arr.push_back(i * i);
        }

        reverse(arr.begin(), arr.end());
        vector<int> dp(n + 1, n + 1);

        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i - arr[j] >= 0) {
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }

        return dp[n];
    }
};