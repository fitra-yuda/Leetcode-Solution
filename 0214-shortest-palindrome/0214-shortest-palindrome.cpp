/*

Main idea : 
1. we can convert to problem to "find the longest palindrome that start from index 0"
2. after we get the longest palindrome that start from index 0, the rest of the string must append in front of it
   to get the shortest palindrome
   - Example : abccbadef
   - Longest palindrome that start from index 0: abccba
   - The rest of the string that must be append in front of it : def
   - result : def + abccbadef = defabccbadef
3. We can find the longest palindrome that start from index 0 by using this approach
   - s + # + reverse(s)
   - the reason why we need '#' character is because of, we need a separete character between s and reverse(s) to reset the LPS array result to 0 where s[index] = '#'

*/


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

    string reverseString(string s) {
        for (int i = 0; i < s.length() / 2; i++) {
            swap(s[i], s[s.length() - 1 - i]);
        }

        return s;
    }
public:
    string shortestPalindrome(string s) {
        string newS = s + '#' + reverseString(s);

        vector<int> LPS = generateLPS(newS);

        int longestPalindromeLength = LPS.back();

        string rest = s.substr(longestPalindromeLength, s.length() - longestPalindromeLength);
        string reverseRest = reverseString(rest);

        return reverseRest + s;
    }
};