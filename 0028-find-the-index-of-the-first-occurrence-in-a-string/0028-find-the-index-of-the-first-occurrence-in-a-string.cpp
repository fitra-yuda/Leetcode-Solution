class Solution {
private:
    vector<int> generateLPS(string &pattern) {
        vector<int> LPS(pattern.length(), 0);
        int left = 0;
        int right = 1;

        while (right < pattern.length()) {
            if (pattern[left] == pattern[right]) {
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

        return LPS;
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> LPS = generateLPS(needle);

        // construct the answer
        int textIndex = 0;
        int patternIndex = 0;
        int result = -1;

        while (textIndex < haystack.length()) {
            if (haystack[textIndex] == needle[patternIndex]) {
                textIndex++;
                patternIndex++;
            } else {
                if (patternIndex == 0) {
                    textIndex++;
                } else {
                    patternIndex = LPS[patternIndex - 1];
                }
            }

            if (patternIndex == needle.length()) {
                result = textIndex - patternIndex;
                break;
            }
        }

        return result;
    }
};