class Solution {
private:
    vector<int> generateLPS(string pattern) {
        vector<int> LPS(pattern.size(), 0);
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
private:
    bool isContain(string text, string pattern) {
        vector<int> LPS = generateLPS(pattern);

        int textIndex = 0;
        int patternIndex = 0;
        
        while (textIndex < text.length() && patternIndex < pattern.length()) {
            if (text[textIndex] == pattern[patternIndex]) {
                textIndex++;
                patternIndex++;
            } else {
                if (patternIndex == 0) {
                    textIndex++;
                } else {
                    // move into previous pattern
                    patternIndex = LPS[patternIndex - 1];
                }
            }
        }

        return patternIndex == pattern.length();
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> bucket;
        vector<string> results;
        for (int i = 0; i < words.size(); i++) {
            string text = words[i];

            for (int j = 0; j < words.size(); j++) {
                if (i == j) {
                    continue;
                }

                string pattern = words[j];

                bool result = isContain(text, pattern);

                if (result && bucket.find(pattern) == bucket.end()) {
                    results.push_back(pattern);
                    bucket.insert(pattern);
                }
            }
        }

        return results;
    }
};