class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));

        unordered_map<int,int> bucket;

        for (int i = 0; i < arr.size(); i++) {
            bucket[arr[i]] = i;
        }

        int result = 0;
        for (int i = arr.size() - 2; i >= 0; i--) {
            for (int j = arr.size() - 1; j > i; j--) {
                int current = arr[i];
                int next = arr[j];

                if (bucket.count(current + next) == 0) {
                    // dp[i][j] = 2 numbers
                    dp[i][j] = 2;
                } else {
                    dp[i][j] = dp[bucket[next]][bucket[current + next]] + 1;
                    result = max(result, dp[i][j]);
                }
            }
        }

        return result;
    }
};