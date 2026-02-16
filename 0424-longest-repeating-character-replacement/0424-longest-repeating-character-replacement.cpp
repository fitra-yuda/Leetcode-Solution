class Solution {
private:
    char getMaximumCharacter(unordered_map<char,int> &bucket){ 
        char keyResult = ' ';
        int maxValue = 0;

        for (auto [key, value] : bucket) {
            if (key == ' ') {
                keyResult = key;
                maxValue = value;
            } else if (maxValue < value) {
                keyResult = key;
                maxValue = value;
            }
        }

        return keyResult;
    }

    int calculateKUsed(unordered_map<char,int> &bucket) {
        char maximumCharacter = getMaximumCharacter(bucket);
        int totalKUsed = 0;

        for (auto [key, value] : bucket) {
            if (key == maximumCharacter) {
                continue;
            }

            totalKUsed += value;
        }

        return totalKUsed;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> bucket;        

        int left = 0;
        int right = 0;
        int result = 0;

        while (right < s.length()) {
            bucket[s[right]]++;

            if (bucket.size() > 1) {
                int kUsed = calculateKUsed(bucket);

                while (kUsed > k) {
                    bucket[s[left]]--;
                    left++;

                    if (bucket[s[left]] == 0) {
                        bucket.erase(s[left]);
                    }

                    kUsed = calculateKUsed(bucket);
                }
            }

            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};