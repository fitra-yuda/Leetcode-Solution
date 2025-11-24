class Solution {
private:
    bool check(vector<int> &matchsticks, int index, int left, int right, int top, int bottom) {
        if (index == matchsticks.size()) {
            return left == 0 && right == 0 && top == 0 && bottom == 0;
        }

        // left
        if (matchsticks[index] <= left) {
            if (check(matchsticks, index + 1, left - matchsticks[index], right, top , bottom)) {
                return true;
            }
        }

        // right
        if (matchsticks[index] <= right) {
            if (check(matchsticks, index + 1, left, right - matchsticks[index], top , bottom)) {
                return true;
            }
        }

        // top
        if (matchsticks[index] <= top) {
            if (check(matchsticks, index + 1, left, right, top - matchsticks[index], bottom)) {
                return true;
            }
        }
        
        // bottom
        if (matchsticks[index] <= bottom) {
            if (check(matchsticks, index + 1, left, right, top , bottom - matchsticks[index])) {
                return true;
            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() <= 3) {
            return false;
        }

        int sum = 0;

        for (auto data : matchsticks) {
            sum += data;
        }

        if (sum % 4 != 0) {
            return false;
        }

        sum /= 4;
        sort(matchsticks.rbegin(), matchsticks.rend());

        return check(matchsticks, 0, sum, sum, sum, sum);
    }
};