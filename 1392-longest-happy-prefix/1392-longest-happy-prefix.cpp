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
    string longestPrefix(string s) {
        vector<int> LPS = generateLPS(s);
        int patternLength = LPS[s.length() - 1];

        return s.substr(0, patternLength);
    }
};