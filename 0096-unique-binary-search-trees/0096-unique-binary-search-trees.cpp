class Solution {
public:
    int numTrees(int n) {
        vector<int> bucket(n + 1, 1);

        for (int i = 2; i <= n; i++) {
            int total = 0;
            for (int j = 1; j <= i; j++) {
                int left = j - 1; 
                int right = i - j;

                total += bucket[left] * bucket[right];
            }

            bucket[i] = total;
        }

        return bucket[n];
    }
};