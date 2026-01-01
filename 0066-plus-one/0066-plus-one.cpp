class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> results;
        int addition = 1;
        for (int i = digits.size() - 1; i >= 0; i--) {

            if (addition == 1) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                } else {
                    digits[i] += addition;
                    addition = 0;
                }
            }

            results.push_back(digits[i]);
        }

        if (addition == 1) {
            results.push_back(addition);
        }

        reverse(results.begin(), results.end());

        return results;
    }
};