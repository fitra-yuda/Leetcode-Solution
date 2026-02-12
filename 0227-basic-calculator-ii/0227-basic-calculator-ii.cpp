class Solution {
private:
    bool isDigit(char x) {
        return x >= '0' && x <= '9';
    }

    bool isSpace(char x) {
        return x == ' ';
    }
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int currentNumber = 0;
        int operation = '+';

        for (int i = 0; i < s.length(); i++) {
            
            if (isdigit(s[i])) {
                currentNumber = (currentNumber * 10) + (s[i] - '0');
            } 

            if ((isSpace(s[i]) == false && isDigit(s[i]) == false) || i == s.length() - 1) {
                if (operation == '+') {
                    st.push(currentNumber);
                } else if (operation == '-') {
                    st.push(currentNumber * -1);
                } else if (operation == '*') {
                    int numberFromStack = st.top();
                    st.pop();
                    st.push(numberFromStack * currentNumber);
                } else if (operation == '/') {
                    int numberFromStack = st.top();
                    st.pop();
                    st.push(numberFromStack / currentNumber);
                }

                operation = s[i];
                currentNumber = 0;
            }
        }

        while (st.size() > 0) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};