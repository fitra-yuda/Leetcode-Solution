class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.length();
        int resultLength = 1;
        int resultIndex = 0;

        for (int i = 0; i < length; i++) {
            // handle odd
            int left = i;
            int right = i;

            while (left >= 0 && right < length && s[left] == s[right]) {
                int window = (right - left) + 1;

                if (window > resultLength) {
                    resultIndex = left;
                    resultLength = window;
                }

                left--;
                right++;
            }


            // handle even
            left = i - 1;
            right = i;

            while (left >= 0 && right < length && s[left] == s[right]) {
                int window = (right - left) + 1;

                if (window > resultLength) {
                    resultIndex = left;
                    resultLength = window;
                }
                left--;
                right++;
            }
        }

        return s.substr(resultIndex, resultLength);
    }
};