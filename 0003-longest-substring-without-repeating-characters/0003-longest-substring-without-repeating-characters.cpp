class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> bucket;

        int left = 0;
        int right = 0;
        int result = 0;

        while (right < s.length()) {

            if (bucket.count(s[right]) > 0) {
                left = max(left, bucket[s[right]] + 1);
            }
           
            bucket[s[right]] = right;
            result = max(result, (right - left) + 1);
            right++;
        }

        return result;
    }
};