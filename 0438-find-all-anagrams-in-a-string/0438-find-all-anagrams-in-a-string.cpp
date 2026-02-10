class Solution {
private:
    bool isValidIndex(vector<int> &bucket) {
        bool result = true;
        
        for (int i = 0; i < bucket.size(); i++) {
            if (bucket[i] > 0) {
                result = false;
                break;
            }
        }

        return result;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> results;
        vector<int> bucket(26, 0);
        
        for (auto character : p) {
            bucket[character - 'a']++;
        }

        int windowSize = p.length();
        int left = 0;
        int right = 0;

        while (right < s.length()) {
            bucket[s[right] - 'a']--;

            if ((right - left) + 1 == windowSize) {
                if (isValidIndex(bucket)) {
                    results.push_back(left);
                }
                bucket[s[left] - 'a']++;
                left++;
            }

            right++;
        }

        return results;
    }
};