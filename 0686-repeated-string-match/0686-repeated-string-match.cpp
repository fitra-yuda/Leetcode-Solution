class Solution {
private:
    vector<int> generateLPS(string pattern) {
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

    bool check(string a, string b, vector<int> &LPS) {

        int indexA = 0;
        int indexB = 0;

        while (indexA < a.length()) {
            if (a[indexA] == b[indexB]) {
                indexA++;
                indexB++;
            } else {
                if (indexB == 0) {
                    indexA++;
                } else {
                    indexB = LPS[indexB - 1];
                }
            }

            if (indexB == b.length()) {
                break;
            }
        }

        if (indexB != b.length()) {
            return false;
        }

        return true;
    }
public:
    int repeatedStringMatch(string a, string b) {
        vector<int> LPS = generateLPS(b);
        int result = 1;

        string temp = a;
        while (a.length() < b.length()) {
            result++;
            a += temp;
        }

        if (check(a, b, LPS)) {
            return result;
        } else if (check(a + temp, b, LPS)) {
            return result + 1;
        } else {
            return -1;
        }
    }
};