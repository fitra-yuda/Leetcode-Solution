class Solution {
private:
    bool isDigit(char currentChar) {
        return currentChar >= '0' && currentChar <= '9';
    }

    bool isSpace(char currentChar) {
        return currentChar == ' ';
    }

    int charToDigit(char currentChar) {
        return currentChar - '0'; 
    }
public:
    int calculate(string s) {
        stack<int> numbers;
        int sign = 1;
        int result = 0;
        long long currentNumber = 0;

        for (int i = 0; i < s.length(); i++) {
            char currentChar = s[i];

            if (isDigit(currentChar)) {
                currentNumber = (currentNumber * 10) + charToDigit(currentChar);
            }

            if ((isDigit(currentChar) == false && isSpace(currentChar) == false) || i == s.length() - 1) {

                if (currentChar == '(') {
                    numbers.push(result);
                    numbers.push(sign);

                    sign = 1;
                    result = 0;
                } else if (currentChar == ')') {
                    result += (currentNumber * sign);
                    sign = 1;
                    currentNumber = 0;

                    result *= numbers.top();
                    numbers.pop();
                    result += numbers.top();
                    numbers.pop();
                } else if (currentChar == '+') {
                    result += (currentNumber * sign);
                    sign = 1;
                    currentNumber = 0;
                } else if (currentChar == '-') {
                    result += (currentNumber * sign);
                    sign = -1;
                    currentNumber = 0;
                }
            }
        }

        if (currentNumber != 0) {
            result += (currentNumber * sign);
        }

        return result;
    }
};