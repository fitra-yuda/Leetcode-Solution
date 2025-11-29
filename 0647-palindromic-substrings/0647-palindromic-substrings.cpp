class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;

        for (int i = 0; i < s.length(); i++) {

            // handle odd
            int left = i;
            int right = i;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                result++;
                left--;
                right++;
            }

            // handle even
            left = i - 1;
            right = i;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                result++;
                left--;
                right++;
            }
        }

        return result;
    }
};