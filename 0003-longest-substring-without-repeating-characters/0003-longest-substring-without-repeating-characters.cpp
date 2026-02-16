class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> bucket;

        int left = 0;
        int right = 0;
        int result = 0;

        while (right < s.length()) {
            bucket[s[right]]++;

            while (left < right && bucket[s[right]] > 1) {
                bucket[s[left]]--;

                if (bucket[s[left]] == 0) {
                    bucket.erase(s[left]);
                }

                left++;
            }

            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};