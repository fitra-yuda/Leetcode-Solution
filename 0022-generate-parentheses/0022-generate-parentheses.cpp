class Solution {
private:
    void dfs(vector<string> &results, string &result, int openBracket, int closeBracket, int n) {

        if (result.length() == n * 2) {
            results.push_back(result);
            return;
        }

        if (openBracket >= closeBracket) {

            if (openBracket < n) {
                result += '(';
                dfs(results, result, openBracket + 1, closeBracket, n);
                result.pop_back();
            }

            result += ')';
            dfs(results, result, openBracket, closeBracket + 1, n);
            result.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string result = "";

        dfs(results, result, 0,0,n);

        return results;
    }
};