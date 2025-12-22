/*

Basecase : 
if (i == 0), then dp[i] = arr[i].first * arr[i].second

DP State : 
dp[i] = maximum score at i-th index

DP Transtition : 
dp[i] = arr[i].first * arr[i].second + (dp[i - 1] or dp[i - 2])

Final State : 
- find the maximum result for every i-th index

*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<pair<int,int>> arr;

        sort(nums.begin(), nums.end());
        int current = -1;
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                current = nums[i];
                total++;
            } else if (nums[i] != nums[i - 1]) {
                arr.push_back({current, total});
                current = nums[i];
                total = 1;
            } else {
                total++;
            }
        }

        arr.push_back({current, total});

        int currentResult = 0;
        int prev = 0;
        int prevprev = 0;
        for (int i = 0; i < arr.size(); i++) {
            currentResult = arr[i].first * arr[i].second;

            if (i > 0 && arr[i].first - 1 != arr[i - 1].first) {
                currentResult += prev;
            }  else if (i > 0 && arr[i].first - 1 == arr[i - 1].first) {
                if (i > 1) {
                    currentResult = max(currentResult + prevprev, prev);
                } else {
                    currentResult = max(currentResult, prev); 
                }
            }

            prevprev = prev;
            prev = currentResult;
        }

        return currentResult; 
    }
};