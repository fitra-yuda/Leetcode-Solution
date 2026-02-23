/*

How to solve the problem : 

# Using hashtable + Bit Manipulation
1. Loop from the first index of the s until last index of the s
2. Shift left the current result by 1, the reason is because of everytime we add the s[i] into the current result, the binary sub string length will by increase by 1, that why we need to shift left by 1
3. if s[i] == '1'
   - add the current result by 1, since the most right index of binary sub string will have a value of 1
4. if k == 0, that means we already have a substring with size k
   - we need to check if the current result is not exists in hashtable, just put that into the hashtable, and add count variable by 1
   - otherwise, just skip
   - decrease the current result by (2^k - 1), or we can use this forumula : currentResult & ( (1 << (k - 1) - 1)). The purpose is to elimnate the most left binary in the current substring.
5. Check if the count == 2^K - 1, that means the answer should be true, since the substring from s can cover all the bniary codes combination with size k or (can cover all the number from 0 until 2^K - 1)

Time Complexity : O(N)
N -> size of length s

Memory Complexity : O(M)
M -> 2^K - 1

*/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_map<int,int> hashTable;

        int currentResult = 0;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            
            currentResult = currentResult << 1;

            if (s[i] == '1') {
                currentResult += 1;
            }

            if ((i - k) + 1 >= 0) {
                if (hashTable.count(currentResult) == 0) {
                    hashTable[currentResult] = 1;
                    count++;
                }

                // eliminate most left index in current sub string
                currentResult = currentResult & ((1 << (k - 1)) - 1); 
            }
        }

        return count == (1 << k);
    }
};