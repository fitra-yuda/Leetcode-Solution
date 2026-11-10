class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int> bucket;

        for (int i = 0; i < s1.length(); i++) {
            bucket[s1[i]]++;
        }

        int left = 0;
        int right = 0;
        int window = s1.length();
        int result = false;

        while (right < s2.length()) {

            if (bucket.count(s2[right]) > 0) {
                bucket[s2[right]]--;
            }

            if (right - left + 1 == window) {
                for (auto [key, value] : bucket) {
                    if (value == 0) {
                        result = true; 
                    } else {
                        result = false;
                        break;
                    }
                } 
                
                if (bucket.count(s2[left]) > 0) {
                    bucket[s2[left]]++;
                }

                left++;
            }

            if (result) {
                break;
            }

            right++;
        }

        return result;
    }
};