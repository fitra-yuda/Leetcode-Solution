class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int openBracket = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                if (openBracket > 0) {
                    result += s[i];
                }
                openBracket++;
            } else if (s[i] == ')') {
                openBracket--;

                if (openBracket > 0) {
                    result += s[i];
                }
            }
        }

        return result;
    }
};