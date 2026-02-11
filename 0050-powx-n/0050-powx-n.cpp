class Solution {
private:
    double calculate(double x, long long rank) {
        if (rank == 0) {
            return 1;
        }

        double result = calculate(x, rank / 2);
        result *= result;
        if (rank % 2 == 1) {
            result *= x;
        }

        return result;
    }
public:
    double myPow(double x, int n) {
        long long rank = n;
        if (n < 0) {
            x = 1 / x;
            rank *= -1;
        }

        return calculate(x, rank);
    }
};