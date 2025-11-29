
/*

Note : 
states : 
- buy / skip
- sell / skip
- skip

- buy = 0
- skip = 1

*/

class Solution {
private:
    int calculate(vector<int> &prices, int index, int state, vector<vector<int>> &dp) {
        if (index >= prices.size()) {
            return 0;
        }

        if (dp[index][state] != -1) {
            return dp[index][state];
        }

        int currentResult = 0;
        if (state == 0) {
            currentResult = calculate(prices, index + 1, 1, dp) - prices[index];
        } else {
            currentResult = calculate(prices, index + 2, 0, dp) + prices[index];
        }

        int skipState = calculate(prices, index + 1, state, dp);

        dp[index][state] = max(currentResult, skipState);

        return dp[index][state];
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return calculate(prices, 0, 0, dp);
    }
};