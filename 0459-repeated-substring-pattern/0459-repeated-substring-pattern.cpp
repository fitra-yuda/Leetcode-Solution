class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        vector<int> LPS(s.length(), 0);

        int left = 0;
        int right = 1;

        while (right < s.length()) {
            if (s[left] == s[right]) {
                left++;
                LPS[right] = left;
                right++;
            } else {
                if (left == 0) {
                    right++;
                } else {
                    left = LPS[left - 1];
                }
            }
        }

        return LPS[s.length() - 1] > 0 && (LPS[s.length() - 1] % (s.length() - LPS[s.length() - 1])) == 0;
    }
};