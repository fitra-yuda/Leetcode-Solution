class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> hashTable;
        int left = 0;
        int right = 0;
        int result = 0;

        int maxCount = 0;
        while (right < s.length()) {
            hashTable[s[right]]++;

            maxCount = max(maxCount, hashTable[s[right]]);

            if ((right - left + 1) - maxCount > k) {
                hashTable[s[left]]--;
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};