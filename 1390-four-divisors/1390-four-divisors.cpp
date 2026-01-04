class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;

        for (auto num : nums) {
            int total = 0;
            int count = 0;
            for (int i = 1; i * i <= num; i++) {
                if (num % i == 0) {
                    int temp = i;
                    if (i * i == num) {
                        count += 1;
                    } else {
                        temp += (num / i);
                        count += 2;
                    }

                    total += temp;
                }
            }

            if (count == 4) {
                result += total;
            }
        }

        return result;
    }
};