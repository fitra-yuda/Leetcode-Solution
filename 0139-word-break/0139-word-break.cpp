/*

DP State 
dp[i] -> should represent if ith index is a valid combination

DP Transtition
- Pick the current string
- Skip the current string

*/


class Solution {
private:
    bool isExists(string &s, string &word, int index) {
        if (index + word.length() > s.length()) {
            return false;
        }

        for (int i = 0; i < word.size(); i++) {
            if (s[i + index] != word[i]) {
                return false;
            }
        }

        return true;
    }

    bool dfs(string &s, int index, unordered_map<char,vector<string>> &bucket, vector<int> &dp) {
        if (index > s.length()) {
            return false;
        } else if (index == s.length()) {
            return true;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        bool result = false;
        for (auto word : bucket[s[index]]) {

            // pick
            if (isExists(s, word, index)) {
                result = dfs(s, index + word.length(), bucket, dp);
                
                if (result) {
                    break;
                }
            }
        }

        return dp[index] = result;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<char,vector<string>> bucket;
        vector<int> dp(s.length(), -1);

        for (auto word : wordDict) {
            bucket[word[0]].push_back(word);
        }

        return dfs(s, 0, bucket, dp);
    }
};