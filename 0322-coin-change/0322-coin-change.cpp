class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {

            int minimumCoin = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                int coin = coins[j];

                if (i - coin >= 0 && dp[i - coin] >= 0) { 
                    minimumCoin = min(dp[i - coin] + 1, minimumCoin);
                }
                
            }
            
            if (minimumCoin != INT_MAX) {
                dp[i] = minimumCoin;
            }
        }

        return dp[amount];
    }
};